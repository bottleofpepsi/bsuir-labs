#pragma once
#include "header.h"

class Interface                                         //класс меню
{
public:
    void printMenu()                                    //функция вывода меню на экран
    {
        int select = 0;

        system("chcp 1251");							//кодировка
        system("color E0");					            //изменение цвета консоли

        while (true)
        {
            system("cls");                              //очистка консоли

            cout << "Выбор типа транспорта: " << endl
                << "1. Транспорт" << endl << "2. Грузовой транспорт" << endl
                << "3. Пассажирский транспорт" << endl << "4. Грузовик" << endl
                << "5. Автобус" << endl << "6. Троллейбус" << endl << "7. Выход" << endl;

            cout << endl << "Ввод: ";
            select = inputInt(cin, 1, 7);
            switch (select)
            {
            case 1:                                     //инициализация кольца транспорта
            {
                Ring <Vehicle> obj;
                ringMenu(obj);
                break;
            }
            case 2:                                     //инициализация кольца грузового транспорта                             
            {
                Ring <Cargo> obj;
                ringMenu(obj);
                break;
            }
            case 3:                                     //инициализация кольца пассажирского транспорта
            {
                Ring <Passenger> obj;
                ringMenu(obj);
                break;
            }
            case 4:                                     //инициализация кольца грузовиков
            {
                Ring <Truck> obj;
                ringMenu(obj);
                break;
            }
            case 5:                                     //инициализация кольца автобусов
            {
                Ring <Bus> obj;
                ringMenu(obj);
                break;
            }
            case 6:                                     //инициализация кольца троллейбусов
            {
                Ring <Trolleybus> obj;
                ringMenu(obj);
                break;
            }
            case 7:                                     //выход из программы
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
            obj.display();                              //вывод очереди

            cout << "Меню: " << endl
                << "1. Добавить узел" << endl << "2. Удалить узел" << endl
                << "3. Очистить кольцо" << endl << "4. Поиск" << endl
                << "5. Работа с файлами" << endl << "6. Назад" << endl;

            cout << endl << "Ввод: ";
            select = inputInt(cin, 1, 6);
            switch (select)
            {
            case 1:                                     //добавление нового элемента
            {
                T temp;

                cin >> temp;
                obj.insert(temp);
                break;
            }
            case 2:                                     //удаление элемента по номеру
            {
                if (obj.isEmpty())
                    break;

                int num = 0;
                cout << "Номер: ";
                num = inputInt(cin, 1, obj.size());
                obj.remove(num);
                break;
            }
            case 3:                                     //очистка кольца
            {
                obj.clear();
                break;
            }
            case 4:                                     //поиск по заданным параметрам
            {
                if (!obj.isEmpty())
                    searchMenu(obj);
                break;
            }
            case 5:                                     //работа с файлами
            {
                fileMenu(obj);
                break;;
            }
            case 6:                                     //возврат к выбору типа кольца
            {
                return;
            }
            }
        }
    }

    template<typename T>
    void searchMenu(Ring<T> obj)                        //меню поиска
    {
        bool flag = false;
        T param;

        while (true)
        {
            system("cls");
            cout << "Введённые параметры: " << endl;
            int k = T::display();
            cout << param << tableFrame << endl;        //отображение введённых параметров на экране

            cout << "Результат: " << endl;
            obj.search(param).display();                //поиск и вывод результата

            flag = param.chooseParameters();            //выбор параметров
            if (flag) return;
        }
    }

    template<typename T>
    void fileMenu(Ring<T>& obj)                         //меню работы с файлами
    {
        int select = 0;

        system("cls");

        cout << "Меню: " << endl
            << "1. Записать в текстовый файл" << endl
            << "2. Прочесть из текстового файла" << endl
            << "3. Записать в бинарный файл" << endl
            << "4. Прочесть из бинарного файла" << endl
            << "5. Назад" << endl;

        cout << endl << "Ввод: ";
        select = inputInt(cin, 1, 5);
        switch (select)
        {
        case 1:                                     //запись в текстовый файл
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
        case 2:                                     //чтение из текстового файла
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
        case 3:                                     //запись в бинарный файл
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
        case 4:                                     //чтение из бинарного файла
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

