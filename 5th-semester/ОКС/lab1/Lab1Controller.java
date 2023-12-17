package com.example.lab1;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.*;
import javafx.scene.text.Text;
import java.util.concurrent.CompletableFuture;
import com.fazecast.jSerialComm.*;


public class Lab1Controller {
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

    private SerialPort[] availablePorts;
    private SerialPort chosenPort;
    private boolean anyPortsAvailable;


    public void initialize()
    {
        inputText.addEventFilter(KeyEvent.KEY_PRESSED, event -> {
            if (event.getCode() == KeyCode.ENTER)
            {
                if (anyPortsAvailable)
                    sendData();
                event.consume();
            }
        });

        portNumberMenu.setOnMouseEntered(event -> {
            portNumberMenu.getItems().clear();
            for (int i = 0; i < availablePorts.length; i++)
            {
                MenuItem currentItem = new MenuItem(availablePorts[i].getSystemPortName());
                currentItem.setOnAction(actionEvent -> {
                    if(!choosePort(SerialPort.getCommPort(currentItem.getText())))
                    {
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

    public void scanForAvailablePorts()
    {
        CompletableFuture.runAsync(() -> {
            while (true)
            {
                availablePorts = SerialPort.getCommPorts();
                if (availablePorts.length == 0)
                {
                    portNumberMenu.setVisible(false);
                    portNumberErrorText.setVisible(true);
                    anyPortsAvailable = false;
                    continue;
                }
                if (!anyPortsAvailable)
                    for (int i = 0; i < availablePorts.length; i++)
                        if(choosePort(availablePorts[i]))
                        {
                            portNumberMenu.setVisible(true);
                            portNumberErrorText.setVisible(false);
                            anyPortsAvailable = true;
                            break;
                        }
            }
        });
    }

    public boolean choosePort(SerialPort newPort)
    {
        if (chosenPort != null && chosenPort.getSystemPortName().equals(newPort.getSystemPortName()))
            return true;
        if (newPort.isOpen())
            return false;

        if (newPort.openPort())
        {
            if (chosenPort != null && chosenPort.isOpen())
                chosenPort.closePort();

            chosenPort = newPort;
            inputText.clear();
            outputText.clear();
            chosenPort.setComPortParameters(9600, Integer.parseInt(byteSizeMenu.getText()), 1, 0);
            baudRate.setText(chosenPort.getBaudRate() + " бит/с");
            Platform.runLater(() -> portNumberMenu.setText(chosenPort.getSystemPortName()));
            readData();
            return true;
        }

        return false;
    }
    
    public void byteSizeMenuItemClickHandler(ActionEvent event)
    {
        MenuItem numOfBits = (MenuItem) event.getSource();
        byteSizeMenu.setText(numOfBits.getText());
        if (chosenPort != null)
            chosenPort.setNumDataBits(Integer.parseInt(numOfBits.getText()));
    }

    public void readData()
    {
        CompletableFuture.runAsync(() -> {
            String targetPortName = chosenPort.getSystemPortName();
            byte[] message = new byte[1024];
            while (targetPortName.equals(chosenPort.getSystemPortName()))
                if (chosenPort.bytesAvailable() > 0)
                {
                    int byteCount = chosenPort.readBytes(message, 1024);
                    outputText.setText(new String(message, 0, byteCount));
                }
        });
    }

    public void sendData()
    {
        byte[] data = inputText.getText().getBytes();
        if (data.length == 0)
            return;
        
        chosenPort.writeBytes(data, data.length);
        amountOfBytesSent.setText(Integer.toString(data.length));
        inputText.clear();
    }
}
