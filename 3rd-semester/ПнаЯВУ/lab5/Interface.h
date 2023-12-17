#pragma once
#include "header.h"
#include "Ring.cpp"

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
                printRingMenu(obj);
                break;
            }
            case 2:                                     //������������� ������ ��������� ����������                             
            {
                Ring <Cargo> obj;
                printRingMenu(obj);
                break;
            }
            case 3:                                     //������������� ������ ������������� ����������
            {
                Ring <Passenger> obj;
                printRingMenu(obj);
                break;
            }
            case 4:                                     //������������� ������ ����������
            {
                Ring <Truck> obj;
                printRingMenu(obj);
                break;
            }
            case 5:                                     //������������� ������ ���������
            {
                Ring <Bus> obj;
                printRingMenu(obj);
                break;
            }
            case 6:                                     //������������� ������ ������������
            {
                Ring <Trolleybus> obj;
                printRingMenu(obj);
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
    void printRingMenu(Ring<T> obj)
    {
        int select = 0;

        while (true)
        {
            system("cls");
            obj.display();                              //����� �������

            cout << "����: " << endl
                << "1. �������� ����" << endl << "2. ������� ����" << endl
                << "3. �������� ������" << endl << "4. �����" << endl << "5. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 5);
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
                num = inputInt(cin, 1, obj.ringLength());
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
            case 5:                                     //������� � ������ ���� ������
            {
                return;
                break;
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
            param.display();
            cout << param << endl;                      //����������� �������� ���������� �� ������

            cout << "���������: " << endl;
            obj.search(param).display();                //����� � ����� ����������

            flag = param.chooseParameters();            //����� ����������
            if (flag) return;
        }
    }
};

