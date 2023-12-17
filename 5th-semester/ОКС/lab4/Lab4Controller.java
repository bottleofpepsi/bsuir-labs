package com.example.lab4;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.*;
import javafx.scene.text.Text;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CompletableFuture;

import com.fazecast.jSerialComm.*;


public class Lab4Controller {
    @FXML
    private TextArea inputText;
    @FXML
    private TextArea outputText;
    @FXML
    private MenuButton portNumberMenu;
    @FXML
    private Text portNumberErrorText;
    @FXML
    private MenuButton byteSizeMenu;
    @FXML
    private Text baudRate;
    @FXML
    private Text amountOfBytesSent;
    @FXML
    private TextArea frameStructureText;
    @FXML
    private TextArea collisionInfo;

    private SerialPort[] availablePorts;
    private SerialPort chosenPort;
    private boolean anyPortsAvailable;
    final private String FLAG = "00010100";


    public void initialize() {
        inputText.addEventFilter(KeyEvent.KEY_PRESSED, event -> {
            if (event.getCode() == KeyCode.ENTER) {
                if (anyPortsAvailable)
                    sendData();
                event.consume();
            }
        });
        inputText.addEventFilter(KeyEvent.KEY_TYPED, event -> {
            String allowedCharacters = "01";
            if (!allowedCharacters.contains(event.getCharacter()))
                event.consume();
        });

        portNumberMenu.setOnMouseEntered(event -> {
            portNumberMenu.getItems().clear();
            for (int i = 0; i < availablePorts.length; i++) {
                if (Integer.parseInt(availablePorts[i].getSystemPortName()
                        .replaceAll("COM", "")) > 15)
                    continue;

                MenuItem currentItem = new MenuItem(availablePorts[i].getSystemPortName());
                currentItem.setOnAction(actionEvent -> {
                    if (!choosePort(SerialPort.getCommPort(currentItem.getText()))) {
                        Alert warning = new Alert(Alert.AlertType.INFORMATION);
                        warning.setContentText("Данный порт уже используется другим приложением!");
                        warning.setHeaderText("Выберите другой порт");
                        warning.setTitle("Предупреждение");
                        warning.show();
                    }
                });
                portNumberMenu.getItems().add(currentItem);
            }
        });

        scanForAvailablePorts();
    }

    public void byteSizeMenuItemClickHandler(ActionEvent event) {
        MenuItem numOfBits = (MenuItem) event.getSource();
        byteSizeMenu.setText(numOfBits.getText());
        if (chosenPort != null)
            chosenPort.setNumDataBits(Integer.parseInt(numOfBits.getText()));
    }

    public void scanForAvailablePorts() {
        CompletableFuture.runAsync(() -> {
            while (true) {
                availablePorts = SerialPort.getCommPorts();
                if (availablePorts.length == 0) {
                    portNumberMenu.setVisible(false);
                    portNumberErrorText.setVisible(true);
                    anyPortsAvailable = false;
                    continue;
                }
                if (!anyPortsAvailable)
                    for (int i = 0; i < availablePorts.length; i++)
                        if (choosePort(availablePorts[i])) {
                            portNumberMenu.setVisible(true);
                            portNumberErrorText.setVisible(false);
                            anyPortsAvailable = true;
                            break;
                        }
            }
        });
    }

    private boolean choosePort(SerialPort newPort) {
        if (chosenPort != null && chosenPort.getSystemPortName().equals(newPort.getSystemPortName()))
            return true;
        if (newPort.isOpen())
            return false;

        if (newPort.openPort()) {
            if (chosenPort != null && chosenPort.isOpen())
                chosenPort.closePort();

            chosenPort = newPort;
            inputText.clear();
            outputText.clear();
            frameStructureText.clear();
            collisionInfo.clear();
            chosenPort.setComPortParameters(9600, Integer.parseInt(byteSizeMenu.getText()), 1, 0);
            baudRate.setText(chosenPort.getBaudRate() + " бит/с");

            Platform.runLater(() -> portNumberMenu.setText(chosenPort.getSystemPortName()));
            readData();

            return true;
        }
        return false;
    }

    private void readData() {
        CompletableFuture.runAsync(() -> {
            String targetPortName = chosenPort.getSystemPortName();
            byte[] message = new byte[8192];
            while (targetPortName.equals(chosenPort.getSystemPortName()))
                if (chosenPort.bytesAvailable() > 0) {
                    int byteCount = chosenPort.readBytes(message, 8192);
                    displayData(message, byteCount);
                }
        });
    }

    private void displayData(byte[] msg, int byteCount) {
        frameStructureText.clear();
        outputText.clear();

//        List<String> frames = retrieveFrames(new String(msg, 0, byteCount));
//        String displayedFrames = highlightFCS(frames);
//        String data = retrieveData(frames);

        String displayedFrames = new String(msg, 0, byteCount);
        String data = bitDestuffing(displayedFrames);

        frameStructureText.setText(displayedFrames);
        outputText.setText(data);
    }

    private List<String> retrieveFrames(String message) {
        List<String> frames = new ArrayList<String>();
        String[] withoutFlags = message.split(FLAG);
        for (int i = 0; i < withoutFlags.length; i++)
            if (withoutFlags[i].length() != 0)
                frames.add(bitDestuffing(FLAG + withoutFlags[i]));

        return frames;
    }

    private String retrieveData(List<String> frames) {
        String data = "";
        for (int i = 0; i < frames.size(); i++)
            data += frames.get(i);
        //data += correctDistortion(frames.get(i));

        return data;
    }

    private String correctDistortion(String corruptedFrame) {
        int i = 0;
        String data = corruptedFrame.substring(16, 36).replace("$", "");
        String correctFCS = corruptedFrame.substring(36);
        String FCS = getHammingCode(data);

        if (FCS.equals(correctFCS))
            return data;

        int distortionPos = 0;
        for (i = 0; i < FCS.length(); i++)
            if (FCS.charAt(i) != correctFCS.charAt(i))
                distortionPos += (int) Math.pow(2, i);

        int numOfParityBits = 0;
        while (Math.pow(2, numOfParityBits) < distortionPos)
            numOfParityBits++;

        distortionPos -= numOfParityBits + 1;

        String inverted = data.charAt(distortionPos) == '1' ? "0" : "1";
        data = data.substring(0, distortionPos) + inverted + data.substring(distortionPos + 1);

        return data;
    }

    private String highlightFCS(List<String> frames) {
        String result = "";
        String frame = "";
        for (int i = 0; i < frames.size(); i++) {
            //result += frames.get(i).replaceAll("00010101", "0001010*1*") + "\n";
            frame = frames.get(i);
            result += frame.substring(0, 36) + " " + getHammingCode(frame.substring(16, 36).replace("$", "")) + "\n";
        }

        return result;
    }

    public void sendData() {
        Thread thread = new Thread(() -> {
            collisionInfo.clear();
            String data = inputText.getText();
            if (data.length() == 0)
                return;

            String buff = data;
            String frames = "";

            while (buff.length() > 0)
            {
                int len = Math.min(20, buff.length());
                frames += generateCollision(createFrame(buff.substring(0, len)));
                buff = buff.substring(len);
            }

            byte[] stream = frames.getBytes();
            chosenPort.writeBytes(stream, stream.length);
            amountOfBytesSent.setText(Integer.toString(data.length()));
            inputText.clear();
        });
        thread.start();
    }

    private String createFrame(String input) {
        String flag = FLAG;
        String destinationAddress = "0000";
        String sourceAddress;
        String data;
        String checkSequence = "0";

        sourceAddress = Integer.toBinaryString(Integer.parseInt(chosenPort.getSystemPortName().replace("COM", "")));
        sourceAddress = String.format("%4s", sourceAddress).replace(" ", "0");

        data = generateDistortion(input);
        data += new String(new char[20 - input.length()]).replace("\0", "$");

        checkSequence = getHammingCode(input);

        String withoutFlag = destinationAddress + sourceAddress + data + checkSequence;
        return flag + bitStuffing(withoutFlag);
    }

    private String bitStuffing(String input) {
        String pattern = "0001010";
        int pos = 0;

        while (pos < input.length()) {
            pos = input.indexOf(pattern, pos);
            if (pos == -1)
                break;

            input = input.substring(0, pos + pattern.length()) + "1" + input.substring(pos + pattern.length());
            pos += pattern.length() + 1;
        }

        return input;
    }

    private String bitDestuffing(String input) {
        String pattern = "0001010";
        int pos = 8;

        while (pos < input.length()) {
            pos = input.indexOf(pattern, pos);
            if (pos == -1)
                break;

            input = input.substring(0, pos + pattern.length()) + input.substring(pos + pattern.length() + 1);
            pos += pattern.length();
        }

        return input;
    }

    private String generateDistortion(String data) {
        if (Math.random() <= 0.7) {
            int pos = (int) (Math.random() * (data.length() - 1));
            String inverted = data.charAt(pos) == '1' ? "0" : "1";
            data = data.substring(0, pos) + inverted + data.substring(pos + 1);
        }
        return data;
    }

    private String getHammingCode(String data) {
        String code = "";
        int numOfParityBits = 0;
        int i = 0;

        while (Math.pow(2, numOfParityBits) <= data.length() + numOfParityBits)
            numOfParityBits++;

        for (i = 0; i < numOfParityBits; i++)
            data = data.substring(0, (int) Math.pow(2, i) - 1) + "0" + data.substring((int) Math.pow(2, i) - 1);

        for (i = 0; i < numOfParityBits; i++) {
            int parity = 0;
            int pos = (int) Math.pow(2, i) - 1;
            for (int j = pos; j < data.length(); j += (pos + 1) * 2)
                for (int k = j; k <= Math.min(j + pos, data.length() - 1); k++)
                    parity ^= Integer.parseInt(data.substring(k, k + 1));

            data = data.substring(0, pos) + Integer.toString(parity) + data.substring(pos + 1);
        }

        for (i = 0; i < numOfParityBits; i++)
            code += data.charAt((int) Math.pow(2, i) - 1);

        return code;
    }

    private String generateCollision(String frame) {
        String result = "";
        int attempts = 0;

        for (int i = 0; i < frame.length(); i++) {
            attempts = 0;
            while (attempts < 16) {
                while (!(Math.random() <= 0.7)) {
                }
                collisionWindowDelay();
                if (Math.random() <= 0.3) {
                    attempts++;
                    backoffDelay(attempts);
                    result += "0";
                    collisionInfo.appendText("+");

                } else {
                    result += frame.charAt(i);
                    collisionInfo.appendText("– ");
                    break;
                }
            }
        }
        collisionInfo.appendText("\n");

        return result;
    }

    private  void collisionWindowDelay() {
        try {
            Thread.sleep(200);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void backoffDelay(int attempt) {
        try {
            Thread.sleep((int) (Math.random() * Math.pow(2, Math.min(attempt, 10))) * 200);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}