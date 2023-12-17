#pragma once
#include "header.h"

class Interface                                         //����� ����
{
public:
    void printMenu()                                    //������� ������ ���� �� �����
    {
        int select = 0;

        system("chcp 1251");							//���������
        system("color E0");					            //��������� ����� �������

        while (true)
        {
            system("cls");                              //������� �������

            cout << "����� ���� ����������: " << endl
                << "1. ���������" << endl << "2. �������� ���������" << endl
                << "3. ������������ ���������" << endl << "4. ��������" << endl
                << "5. �������" << endl << "6. ����������" << endl << "7. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 7);
            switch (select)
            {
            case 1:                                     //������������� ������ ����������
            {
                Ring <Vehicle> obj;
                ringMenu(obj);
                break;
            }
            case 2:                                     //������������� ������ ��������� ����������                             
            {
                Ring <Cargo> obj;
                ringMenu(obj);
                break;
            }
            case 3:                                     //������������� ������ ������������� ����������
            {
                Ring <Passenger> obj;
                ringMenu(obj);
                break;
            }
            case 4:                                     //������������� ������ ����������
            {
                Ring <Truck> obj;
                ringMenu(obj);
                break;
            }
            case 5:                                     //������������� ������ ���������
            {
                Ring <Bus> obj;
                ringMenu(obj);
                break;
            }
            case 6:                                     //������������� ������ ������������
            {
                Ring <Trolleybus> obj;
                ringMenu(obj);
                break;
            }
            case 7:                                     //����� �� ���������
            {
                exit(1);
                break;
            }
            }
        }
    }

    template<typename T>
    void ringMenu(Ring<T> obj)
    {
        int select = 0;

        while (true)
        {
            system("cls");
            obj.display();                              //����� �������

            cout << "����: " << endl
                << "1. �������� ����" << endl << "2. ������� ����" << endl
                << "3. �������� ������" << endl << "4. �����" << endl
                << "5. ������ � �������" << endl << "6. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 6);
            switch (select)
            {
            case 1:                                     //���������� ������ ��������
            {
                T temp;

                cin >> temp;
                obj.insert(temp);
                break;
            }
            case 2:                                     //�������� �������� �� ������
            {
                if (obj.isEmpty())
                    break;

                int num = 0;
                cout << "�����: ";
                num = inputInt(cin, 1, obj.size());
                obj.remove(num);
                break;
            }
            case 3:                                     //������� ������
            {
                obj.clear();
                break;
            }
            case 4:                                     //����� �� �������� ����������
            {
                if (!obj.isEmpty())
                    searchMenu(obj);
                break;
            }
            case 5:                                     //������ � �������
            {
                fileMenu(obj);
                break;;
            }
            case 6:                                     //������� � ������ ���� ������
            {
                return;
            }
            }
        }
    }

    template<typename T>
    void searchMenu(Ring<T> obj)                        //���� ������
    {
        bool flag = false;
        T param;

        while (true)
        {
            system("cls");
            cout << "�������� ���������: " << endl;
            int k = T::display();
            cout << param << tableFrame << endl;        //����������� �������� ���������� �� ������

            cout << "���������: " << endl;
            obj.search(param).display();                //����� � ����� ����������

            flag = param.chooseParameters();            //����� ����������
            if (flag) return;
        }
    }

    template<typename T>
    void fileMenu(Ring<T>& obj)                         //���� ������ � �������
    {
        int select = 0;

        system("cls");

        cout << "����: " << endl
            << "1. �������� � ��������� ����" << endl
            << "2. �������� �� ���������� �����" << endl
            << "3. �������� � �������� ����" << endl
            << "4. �������� �� ��������� �����" << endl
            << "5. �����" << endl;

        cout << endl << "����: ";
        select = inputInt(cin, 1, 5);
        switch (select)
        {
        case 1:                                     //������ � ��������� ����
        {
            TextFile file;
            file.setFileName(enterTxtFileName());

            file.openFileOut();
            if (!checkIfOpened(file))
                break;
            
            for (int i = 0; i < obj.size(); i++)
                file.writeInFile(obj[i]);

            file.closeFileOut();
            break;
        }
        case 2:                                     //������ �� ���������� �����
        {
            TextFile file;
            file.setFileName(enterTxtFileName());

            file.openFileIn();
            if (!checkIfOpened(file))
                break;

            obj.clear();
            while (true)
            {
                T tmp;
                file.readFromFile(tmp);
                if (file.isEOF())
                    break;
                obj.insert(tmp);
            }

            file.closeFileIn();
            break;
        }
        case 3:                                     //������ � �������� ����
        {
            BinaryFile file;
            file.setFileName(enterBinFileName());

            file.clearBinFile();
            file.openFile();
            if (!checkIfOpened(file))
                break;

            for (int i = 0; i < obj.size(); i++)
                file.writeInFile(obj[i]);

            file.closeFile();
            break;
        }
        case 4:                                     //������ �� ��������� �����
        {
            BinaryFile file;
            file.setFileName(enterBinFileName());

            file.openFile();
            if (!checkIfOpened(file))
                break;

            obj.clear();
            while (true)
            {
                T tmp;
                file.readFromFile(tmp);
                if (file.isEOF())
                    break;
                obj.insert(tmp);
            }

            file.closeFile();
            break;
        }
        case 5:                                    
        {
            return;
        }
        }
    }
};

