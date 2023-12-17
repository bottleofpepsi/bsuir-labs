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

bool operator==(const Passenger& obj1, const Passenger& obj2)					//оператор сравнения
{
	if (!(dynamic_cast<const Vehicle&>(obj1) == dynamic_cast<const Vehicle&>(obj2)))
		return false;
	if (obj1.passengers != 0 && obj1.passengers != obj2.passengers)
		return false;
	if (obj1.route != 0 && obj1.route != obj2.route)
		return false;

	return true;
}

istream& operator>>(istream& in, Passenger& obj)								//оператор ввода
{
	in >> dynamic_cast<Vehicle&>(obj);											//приведение к родительскому типу
	cout << "Введите кол-во пассажиров: ";
	in >> obj.passengers;
	cout << "Введите маршрут: ";
	in >> obj.route;
	return in;
}

ostream& operator<<(ostream& out, const Passenger& obj)							//оператор вывода
{	
	out << dynamic_cast<const Vehicle&>(obj)									//приведение к родительскому типу
		<< setw(3) << obj.passengers << setw(14) << " чел" << " | "
		<< setw(10) << obj.route << " | ";

	return out;
}

void Passenger::display()														//шапка таблицы
{
	cout << left << setfill('=') << setw(76) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " | "
		<< setw(17) << "Кол-во пассажиров" << " | "
		<< setw(10) << "№ маршрута" << " | " << endl
		<< setfill('=') << setw(76) << '=' << endl << setfill(' ');
}

bool Passenger::chooseParameters()                                         //меню выбора параметров для Passenger
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Максимальное кол-во пассажиров" << endl << "4. Маршрут" << endl
        << "5. Сброс параметров" << endl << "6. Назад" << endl;

    cout << endl << "Ввод: ";
    cin >> select;
    switch (select)
    {
    case 1:                                         //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                         //модель
    {
        char tmp[15];
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_model(tmp);
        break;
    }
    case 3:                                         //кол-во пассажиров
    {
        int tmp = 0;
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_passengers(tmp);
        break;
    }
    case 4:                                         //маршрут
    {
        int tmp = 0;
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_route(tmp);
        break;
    }
    case 5:                                         //сброс параметров
    {
        *this = Passenger();
        break;
    }
    case 6:                                         //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}