#include "Passenger.h"

int Passenger::get_passengers() { return passengers; }							//геттеры-сеттеры
void Passenger::set_passengers(int i) { passengers = i; }
int Passenger::get_route() { return route; }
void Passenger::set_route(int i) { route = i; }

Passenger Passenger::operator=(const Passenger& obj)							//оператор присваивания
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			//приведение к родительскому типу
	this->passengers = obj.passengers;
	this->route = obj.route;

	return *this;
}

bool Passenger::operator==(const Passenger& other)							    //оператор сравнения
{
    if (!(dynamic_cast<Vehicle&>(*this) == dynamic_cast<const Vehicle&>(other)))
        return false;
    if (other.passengers != 0 && this->passengers != other.passengers)
        return false;
    if (other.route != 0 && this->route != other.route)
        return false;

    return true;
}

bool Passenger::operator>(const Passenger& other)		                        //оператор больше
{
    if (reinterpret_cast<Vehicle&>(*this) < reinterpret_cast<const Vehicle&>(other))
        return false;
    if (other.passengers != 0 && this->passengers < other.passengers)
        return false;
    if (other.route != 0 && this->route < other.route)
        return false;

    return true;
}

bool Passenger::operator<(const Passenger& other)	                        //оператор меньше
{
    return !(*this > other);
}

istream& operator>>(istream& in, Passenger& obj)							//оператор ввода
{
	in >> dynamic_cast<Vehicle&>(obj);										//приведение к родительскому типу
	cout << "Введите кол-во пассажиров: ";
	obj.passengers = inputInt(in);
	cout << "Введите маршрут: ";
	obj.route = inputInt(in);
	return in;
}

ostream& operator<<(ostream& out, Passenger& obj)						    //оператор вывода
{	
	out << dynamic_cast<Vehicle&>(obj)									    //приведение к родительскому типу
		<< setw(3) << obj.passengers << setw(14) << " чел" << " | "
		<< setw(10) << obj.route << " | ";

	return out;
}

ifstream& operator>>(ifstream& in, Passenger& obj)				            //оператор чтения из текстового файла
{
    in >> dynamic_cast<Vehicle&>(obj);
    in >> obj.passengers >> obj.route;
    return in;
}

ofstream& operator<<(ofstream& out, Passenger& obj)			                //оператор записи в текстовый файл
{
    out << dynamic_cast<Vehicle&>(obj);
    out << " " << obj.passengers << " " << obj.route;
    return out;
}

fstream& operator>>(fstream& in, Passenger& obj)					        //оператор чтения из бинарного файла
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Passenger));
    return in;
}

fstream& operator<<(fstream& out, Passenger& obj)			                //оператор записи в бинарный файл
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Passenger));
    return out;
}

int Passenger::display()												    //шапка таблицы
{
	cout << left << setfill('=') << setw(76) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " | "
		<< setw(17) << "Кол-во пассажиров" << " | "
		<< setw(10) << "№ маршрута" << " | " << endl
		<< setfill('=') << setw(76) << '=' << endl << setfill(' ');

    return 76;
}

bool Passenger::chooseParameters()                      //меню выбора параметров для Passenger
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Сброс параметров" << endl << "6. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 6);
    switch (select)
    {
    case 1:                                             //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                             //модель
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputString(cin));
        this->set_model(tmp);
        break;
    }
    case 3:                                             //кол-во пассажиров
    {
        int tmp = 0;
        cout << "Значение: ";
        tmp = inputInt(cin, 0);
        this->set_passengers(tmp);
        break;
    }
    case 4:                                             //маршрут
    {
        int tmp = 0;
        cout << "Значение: ";
        tmp = inputInt(cin, 0);
        this->set_route(tmp);
        break;
    }
    case 5:                                             //сброс параметров
    {
        *this = Passenger();
        break;
    }
    case 6:                                             //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}

int Passenger::chooseSortParameter()					//функция выбора поля сортировки
{
    int select = 0;

    cout << "Сортировка по: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 5);
    switch (select)
    {
    case 5:                                             //отмена
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Passenger Passenger::copyParameter(int n)   	        //функция копирования поля
{
    Passenger result;

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
    }

    return result;
}
