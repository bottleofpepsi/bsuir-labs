#include "Trolleybus.h"

float Trolleybus::get_power_consumption() { return power_consumption; }			//геттеры-сеттеры
void Trolleybus::set_power_consumption(float f) { power_consumption = f; }

Trolleybus Trolleybus::operator=(const Trolleybus& obj)							//оператор присваивания
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//приведение к родительскому типу
	this->power_consumption = obj.power_consumption;

	return *this;
}

istream& operator>>(istream& in, Trolleybus& obj)								//оператор ввода
{
	in >> dynamic_cast<Passenger&>(obj) >> obj.power_consumption;				//приведение к родительскому типу
	return in;
}

ostream& operator<<(ostream& out, const Trolleybus& obj)						//оператор вывода
{
	out << dynamic_cast<const Passenger&>(obj)									//приведение к родительскому типу
		<< setw(6) << obj.power_consumption << setw(11) << " кВт*ч" << " |" << endl;

	return out;
}

void Trolleybus::display()														//вывод таблицы
{
	cout << left << setfill('=') << setw(96) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " | "
		<< setw(17) << "Кол-во пассажиров" << " | "
		<< setw(10) << "№ маршрута" << " | "
		<< setw(17) << "Энергопотребление" << " | " << endl
		<< setfill('=') << setw(96) << '=' << endl << setfill(' ');
}