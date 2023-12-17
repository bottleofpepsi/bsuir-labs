#include "Bus.h"

float Bus::get_fuel() { return fuel; }											//геттеры-сеттеры
void Bus::set_fuel(float f) { fuel = f; }

Bus Bus::operator=(const Bus& obj)												//оператор присваивания
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//приведение к родительскому типу
	this->fuel = obj.fuel;

	return *this;
}

istream& operator>>(istream& in, Bus& obj)										//оператор ввода
{
	in >> dynamic_cast<Passenger&>(obj) >> obj.fuel;							//приведение к родительскому типу
	return in;
}

ostream& operator<<(ostream& out, const Bus& obj)								//оператор вывода
{
	out << dynamic_cast<const Passenger&>(obj)									//приведение к родительскому типу
		<< setw(6) << obj.fuel << setw(8) << " л/100км" << " |" << endl;

	return out;
}

void Bus::display()																//шапка таблицы
{
	cout << left << setfill('=') << setw(93) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " | "
		<< setw(17) << "Кол-во пассажиров" << " | "
		<< setw(10) << "№ маршрута" << " | "
		<< setw(14) << "Расход топлива" << " | " << endl
		<< setfill('=') << setw(93) << '=' << endl << setfill(' ');
}