#include "Truck.h"

float Truck::get_load() { return load; }										//геттеры-сеттеры
void Truck::set_load(float f) { load = f; }

Truck Truck::operator=(const Truck& obj)										//оператор присваивани€
{
	dynamic_cast<Cargo&>(*this) = dynamic_cast<const Cargo&>(obj);				//приведение к родительскому типу
	this->load = obj.load;

	return *this;
}

istream& operator>>(istream& in, Truck& obj)									//оператор ввода
{
	in >> dynamic_cast<Cargo&>(obj) >> obj.load;								//приведение к родительскому типу
	return in;
}

ostream& operator<<(ostream& out, const Truck& obj)								//оператор вывода
{
	out << dynamic_cast<const Cargo&>(obj) << setprecision(4)					//приведение к родительскому типу
		<< setw(5) << obj.load << " " << setw(3) << "т" << " |" << endl;

	return out;
}

void Truck::display()															//шапка таблицы
{
	Cargo::display();
	cout << setw(9) << " ¬ес груза" << " |" << endl
		<< setfill('=') << setw(92) << '=' << endl << setfill(' ');
}