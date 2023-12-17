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

            cout << "����� ����������: " << endl
                << "1. ������" << endl << "2. ������� � �����������" << endl
                << "3. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 3);
            switch (select)
            {
            case 1:                                     //������
            {
                _RMenu();
                break;
            }
            case 2:                                     //������� � �����������                     
            {
                _PQMenu();
                break;
            }
            case 3:                                     //����� �� ���������
            {
                exit(1);
                break;
            }
            }
        }
    }

    void _RMenu()                                       //������� ������ ���� �� �����
    {
        int select = 0;

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
            case 7:                                     
            {
                return;
                break;
            }
            }
        }
    }

    void _PQMenu()                                       //������� ������ ���� �� �����
    {
        int select = 0;

        while (true)
        {
            system("cls");                              //������� �������

            cout << "����� ���� ����������: " << endl
                << "1. ��������� � ������������" << endl << "2. ��������� � �����������" << endl
                << "3. ���� ����������" << endl << "4. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 4);
            switch (select)
            {
            case 1:                                     //��������� � �������������
            {
                priority_queue <Truck> obj;
                //priority_queue <Truck, vector<Truck>, less<Truck>> obj;
                queueMenu(obj);
                break;
            }
            case 2:                                     //��������� � ������������                          
            {
                priority_queue <Truck, vector<Truck>, greater<Truck>> obj;
                queueMenu(obj);
                break;
            }
            case 3:                                     //���� ����������                          
            {
                priority_queue <Truck, deque<Truck>, Comparator> obj;
                queueMenu(obj);
                break;
            }
            case 4:                                     
            {
                return;
                break;
            }
            }
        }
    }

    template<typename T, typename T1, typename T2>
    void queueMenu(priority_queue <T, T1, T2> obj)          //���� ������� � �����������
    {
        int select = 0;

        while (true)
        {
            system("cls");

            printPQ(obj);                                   //����� ������� �� �����

            cout << "����: " << endl
                << "1. �������� �������" << endl << "2. ������� �������" << endl
                << "3. �������� �������" << endl << "4. ������ �������" << endl
                << "5. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 5);
            switch (select)
            {
            case 1:                                         //���������� ������ ��������
            {
                T temp;

                cin >> temp;
                obj.emplace(temp);
                break;
            }
            case 2:                                     //�������� ��������
            {
                if (!obj.empty())
                    obj.pop();

                break;
            }
            case 3:                                     //������� �������
            {
                while (!obj.empty())
                    obj.pop();                                  
                break;
            }
            case 4:                                     //������ �������
            {
                cout << "������ �������: " << obj.size() << endl;
                system("pause");
                break;
            }
            case 5:                                     
            {
                return;
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
                << "5. ������ � �������" << endl << "6. ����������" << endl
                << "7. �����" << endl;

            cout << endl << "����: ";
            select = inputInt(cin, 1, 7);
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
                if (emptyContainer(obj.begin()))
                    break;

                int num = 0;
                cout << "�����: ";
                num = inputInt(cin, 1, obj.size());
                obj.remove(num);
                break;
            }
            case 3:                                     //������� ������
            {
                if (emptyContainer(obj.begin()))
                    break;
                obj.clear();
                break;
            }
            case 4:                                     //����� �� �������� ����������
            {
                if (emptyContainer(obj.begin()))
                    break;
                searchMenu(obj);
                break;
            }
            case 5:                                     //������ � �������
            {
                fileMenu(obj);
                break;;
            }
            case 6:                                     //������ � �����������
            {
                if (emptyContainer(obj.begin()))
                    break;

                int n = T::chooseSortParameter();
                sort(obj.begin(), obj.end(), n);
                break;
            }
            case 7:                                     //������� � ������ ���� ������
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
            cout << param << tableFrame << endl;                    //����������� �������� ���������� �� ������

            cout << "���������: " << endl;
            search(obj.begin(), obj.end(), param).display();        //����� � ����� ����������

            flag = param.chooseParameters();                        //����� ����������
            if (flag) return;
        }
    }

    template<typename T>
    void fileMenu(Ring<T>& obj)
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
        case 5:                                     //������� � ������ ���� ������
        {
            return;
        }
        }
    }
};

