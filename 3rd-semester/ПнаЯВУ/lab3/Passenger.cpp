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

istream& operator>>(istream& in, Passenger& obj)								//оператор ввода
{
	in >> dynamic_cast<Vehicle&>(obj) >> obj.passengers >> obj.route;			//приведение к родительскому типу
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