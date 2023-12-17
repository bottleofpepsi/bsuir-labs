#pragma once
#include "header.h"
#include "Ring.cpp"

class Interface                                             //класс меню
{
public:
    void printMenu()                                        //функция вывода меню на экран
    {
        int select = 0;
        
        system("chcp 1251");				                //кодировка
        system("color E0");							        //изменение цвета консоли

        while (true)
        {
            system("cls");                                  //очистка консоли

            cout << "Выбор типа транспорта: " << endl
                << "1. Транспорт" << endl << "2. Грузовой транспорт" << endl
                << "3. Пассажирский транспорт" << endl << "4. Грузовик" << endl
                << "5. Автобус" << endl << "6. Троллейбус" << endl << "7. Выход" << endl;

            cout << endl << "Ввод: ";
            cin >> select;
            switch (select)
            {
            case 1:                                         //инициализация кольца транспорта
            {
                Ring <Vehicle> obj;
                printRingMenu(obj);
                break;
            }
            case 2:                                         //инициализация кольца грузового транспорта                             
            {
                Ring <Cargo> obj;
                printRingMenu(obj);
                break;
            }
            case 3:                                         //инициализация кольца пассажирского транспорта
            {
                Ring <Passenger> obj;
                printRingMenu(obj);
                break;
            }
            case 4:                                         //инициализация кольца грузовиков
            {
                Ring <Truck> obj;
                printRingMenu(obj);
                break;
            }
            case 5:                                         //инициализация кольца автобусов
            {
                Ring <Bus> obj;
                printRingMenu(obj);
                break;
            }
            case 6:                                         //инициализация кольца троллейбусов
            {
                Ring <Trolleybus> obj;
                printRingMenu(obj);
                break;
            }
            case 7:                                         //выход из программы
            {
                exit(1);
                break;
            }
            }
        }
    }

    template<typename T>
    void printRingMenu(Ring<T> obj)                         //меню очереди
    {
        int select = 0;
        while (true)
        {
            system("cls");
            obj.display();                                  //вывод очереди

            cout << "Меню: " << endl
                << "1. Добавить узел" << endl << "2. Удалить узел" << endl
                << "3. Очистить кольцо" << endl << "4. Поиск" << endl << "5. Назад" << endl;

            cout << endl << "Ввод: ";
            cin >> select;
            switch (select)
            {
            case 1:                                         //добавление нового элемента
            {
                T temp;
                cin >> temp;
                obj.insert(temp);
                break;
            }
            case 2:                                         //удаление элемента по номеру
            {
                int num = 0;
                cout << "Номер: ";
                cin >> num;
                obj.remove(num);
                break;
            }
            case 3:                                         //очистка кольца
            {
                obj.clear();
                break;
            }
            case 4:                                         //поиск по заданным параметрам
            {
                if (obj.isEmpty())                          //выход, если кольцо пусто
                    return;

                bool flag = false;
                T param;

                while (true)
                {
                    system("cls");
                    cout << "Введённые параметры: " << endl;
                    param.display();
                    cout << param << endl;

                    cout << "Результат: " << endl;
                    obj.search(param).display();            //поиск и вывод результата

                    flag = param.chooseParameters();        //выбор параметров
                    if (flag) return;
                }
                break;
            }
            case 5:                                         //возврат к выбору типа кольца
            {
                return;
                break;
            }
            }
        }
    }
};