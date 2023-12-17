#include "Bus.h"

float Bus::get_fuel() { return fuel; }											//геттеры-сеттеры
void Bus::set_fuel(float f) { fuel = f; }

Bus Bus::operator=(const Bus& obj)												//оператор присваивания
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//приведение к родительскому типу
	this->fuel = obj.fuel;

	return *this;
}

bool operator==(const Bus& obj1, const Bus& obj2)								//оператор сравнения
{
	if (!(dynamic_cast<const Passenger&>(obj1) == dynamic_cast<const Passenger&>(obj2)))
		return false;
	if (obj1.fuel != 0.0 && obj1.fuel != obj2.fuel)
		return false;

	return true;
}

istream& operator>>(istream& in, Bus& obj)									//оператор ввода
{
	in >> dynamic_cast<Passenger&>(obj);								    //приведение к родительскому типу
	cout << "Введите расход топлива: ";
	obj.fuel = inputFloat(in);
	return in;
}

ostream& operator<<(ostream& out, Bus& obj)								    //оператор вывода
{
	out << dynamic_cast<Passenger&>(obj)									//приведение к родительскому типу
		<< setw(6) << obj.fuel << setw(8) << " л/100км" << " |" << endl;

	return out;
}

ifstream& operator>>(ifstream& in, Bus& obj)				                //оператор чтения из текстового файла
{
    in >> dynamic_cast<Passenger&>(obj);
    in >> obj.passengers >> obj.route;
    return in;
}

ofstream& operator<<(ofstream& out, Bus& obj)			                    //оператор записи в текстовый файл
{
    out << dynamic_cast<Passenger&>(obj);
    out << " " << obj.fuel << endl;
    return out;
}

fstream& operator>>(fstream& in, Bus& obj)					                //оператор чтения из бинарного файла
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Bus));
    return in;
}

fstream& operator<<(fstream& out, Bus& obj)			                        //оператор записи в бинарный файл
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Bus));
    return out;
}

int Bus::display()															//шапка таблицы
{
	cout << left << setfill('=') << setw(93) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " | "
		<< setw(17) << "Кол-во пассажиров" << " | "
		<< setw(10) << "№ маршрута" << " | "
		<< setw(14) << "Расход топлива" << " | " << endl
		<< setfill('=') << setw(93) << '=' << endl << setfill(' ');

    return 93;
}

bool Bus::chooseParameters()                            //меню ввода параметров для Bus
{
    Bus tempObj;
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Расход топлива" << endl << "6. Сброс параметров" << endl << "7. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 7);
    switch (select)
    {
    case 1:                                             //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        tempObj.set_max_speed(tmp);
        break;
    }
    case 2:                                             //модель
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputString(cin, STR_LEN));
        tempObj.set_model(tmp);
        break;
    }
    case 3:                                             //кол-во пассажиров
    {
        int tmp = 0;
        cout << "Значение: ";
        tmp = inputInt(cin, 0);
        tempObj.set_passengers(tmp);
        break;
    }
    case 4:                                             //маршрут
    {
        int tmp = 0;
        cout << "Значение: ";
        tmp = inputInt(cin, 0);
        tempObj.set_route(tmp);
        break;
    }
    case 5:                                             //расход топлива
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        tempObj.set_fuel(tmp);
        break;
    }
    case 6:                                             //сброс параметров
    {
        *this = Bus();
        break;
    }
    case 7:                                             //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}