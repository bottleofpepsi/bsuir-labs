#include "Bus.h"

float Bus::get_fuel() { return fuel; }											        //геттеры-сеттеры
void Bus::set_fuel(float f) { fuel = f; }

Bus Bus::operator=(const Bus& obj)												        //оператор присваивания
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		        //приведение к родительскому типу
	this->fuel = obj.fuel;

	return *this;
}

bool Bus::operator==(const Bus& other)							                        //оператор сравнения
{
    if (!(dynamic_cast<Passenger&>(*this) == dynamic_cast<const Passenger&>(other)))
        return false;
    if (other.fuel != 0.0 && this->fuel != other.fuel)
        return false;

    return true;
}

bool Bus::operator>(const Bus& other)		                                            //оператор больше
{
    if (reinterpret_cast<Passenger&>(*this) < reinterpret_cast<const Passenger&>(other))
        return false;
    if (other.fuel != 0.0 && this->fuel < other.fuel)
        return false;

    return true;
}

bool Bus::operator<(const Bus& other)	                                    //оператор меньше
{
    return !(*this > other);
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
        strcpy_s(tmp, STR_LEN, inputString(cin));
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

int Bus::chooseSortParameter()					        //функция выбора поля сортировки
{
    int select = 0;

    cout << "Сортировка по: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Расход топлива" << endl << "6. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 6);
    switch (select)
    {
    case 6:                                             //отмена
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Bus Bus::copyParameter(int n)   	                    //функция копирования поля
{
    Bus result;

    switch (n)
    {
    case 1:
    {
        result.set_max_speed(this->get_max_speed());
        break;
    }
    case 2:
    {
        result.set_model(this->get_model());
        break;
    }
    case 3:
    {
        result.set_passengers(this->get_passengers());
        break;
    }
    case 4:
    {
        result.set_route(this->get_route());
        break;
    }
    case 5:
    {
        result.set_fuel (this->get_fuel());
        break;
    }
    }

    return result;
}
