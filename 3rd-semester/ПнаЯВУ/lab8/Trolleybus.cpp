#include "Trolleybus.h"

float Trolleybus::get_power_consumption() { return power_consumption; }			//геттеры-сеттеры
void Trolleybus::set_power_consumption(float f) { power_consumption = f; }

Trolleybus Trolleybus::operator=(const Trolleybus& obj)							//оператор присваивания
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//приведение к родительскому типу
	this->power_consumption = obj.power_consumption;

	return *this;
}

bool Trolleybus::operator==(const Trolleybus& other)							                    //оператор сравнения
{
    if (!(dynamic_cast<Passenger&>(*this) == dynamic_cast<const Passenger&>(other)))
        return false;
    if (other.power_consumption != 0.0 && this->power_consumption != other.power_consumption)
        return false;

    return true;
}

bool Trolleybus::operator>(const Trolleybus& other)		                                            //оператор больше
{
    if (reinterpret_cast<Passenger&>(*this) < reinterpret_cast<const Passenger&>(other))
        return false;
    if (other.power_consumption != 0.0 && this->power_consumption < other.power_consumption)
        return false;

    return true;
}

bool Trolleybus::operator<(const Trolleybus& other)	                            //оператор меньше
{
    return !(*this > other);
}

istream& operator>>(istream& in, Trolleybus& obj)								//оператор ввода
{
	in >> dynamic_cast<Passenger&>(obj);										//приведение к родительскому типу
	cout << "Введите энергопотребление: ";
	obj.power_consumption = inputFloat(in);
	return in;
}

ostream& operator<<(ostream& out, Trolleybus& obj)						        //оператор вывода
{
	out << dynamic_cast<Passenger&>(obj)									    //приведение к родительскому типу
		<< setw(6) << obj.power_consumption << setw(11) << " кВт*ч" << " |" << endl;

	return out;
}

ifstream& operator>>(ifstream& in, Trolleybus& obj)				                //оператор чтения из текстового файла
{
    in >> dynamic_cast<Passenger&>(obj);
    in >> obj.power_consumption;
    return in;
}

ofstream& operator<<(ofstream& out, Trolleybus& obj)			                //оператор записи в текстовый файл
{
    out << dynamic_cast<Passenger&>(obj);
    out << " " << obj.power_consumption << endl;
    return out;
}

fstream& operator>>(fstream& in, Trolleybus& obj)					            //оператор чтения из бинарного файла
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Trolleybus));
    return in;
}

fstream& operator<<(fstream& out, Trolleybus& obj)			                    //оператор записи в бинарный файл
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Trolleybus));
    return out;
}

int Trolleybus::display()														//вывод таблицы
{
	cout << left << setfill('=') << setw(96) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " | "
		<< setw(17) << "Кол-во пассажиров" << " | "
		<< setw(10) << "№ маршрута" << " | "
		<< setw(17) << "Энергопотребление" << " | " << endl
		<< setfill('=') << setw(96) << '=' << endl << setfill(' ');

    return 96;
}

bool Trolleybus::chooseParameters()                         //меню поиска для Trolleybus
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Энергопотребление" << endl << "6. Сброс параметров" << endl << "7. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 7);
    switch (select)
    {
    case 1:                                                 //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                                 //модель
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputString(cin));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //кол-во пассажиров
    {
        int tmp = 0;
        cout << "Значение: ";
        tmp = inputInt(cin, 0);
        this->set_passengers(tmp);
        break;
    }
    case 4:                                                 //маршрут
    {
        int tmp = 0;
        cout << "Значение: ";
        tmp = inputInt(cin, 0);
        this->set_route(tmp);
        break;
    }
    case 5:                                                 //энергопотребление
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        this->set_power_consumption(tmp);
        break;
    }
    case 6:                                                 //сброс параметров
    {
        *this = Trolleybus();
        break;
    }
    case 7:                                                 //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}

int Trolleybus::chooseSortParameter()				        //функция выбора поля сортировки
{
    int select = 0;

    cout << "Сортировка по: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Энергопотребление" << endl << "6. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 6);
    switch (select)
    {
    case 6:                                                 //отмена
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Trolleybus Trolleybus::copyParameter(int n)                 //функция копирования поля
{
    Trolleybus result;

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
        result.set_power_consumption(this->get_power_consumption());
        break;
    }
    }

    return result;
}
