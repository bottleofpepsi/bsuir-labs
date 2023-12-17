#include "Truck.h"

float Truck::get_load() { return load; }										//�������-�������
void Truck::set_load(float f) { load = f; }

Truck Truck::operator=(const Truck& obj)										//�������� ������������
{
	dynamic_cast<Cargo&>(*this) = dynamic_cast<const Cargo&>(obj);				//���������� � ������������� ����
	this->load = obj.load;

	return *this;
}

istream& operator>>(istream& in, Truck& obj)									//�������� �����
{
	in >> dynamic_cast<Cargo&>(obj) >> obj.load;								//���������� � ������������� ����
	return in;
}

ostream& operator<<(ostream& out, const Truck& obj)								//�������� ������
{
	out << dynamic_cast<const Cargo&>(obj) << setprecision(4)					//���������� � ������������� ����
		<< setw(5) << obj.load << " " << setw(3) << "�" << " |" << endl;

	return out;
}

void Truck::display()															//����� �������
{
	Cargo::display();
	cout << setw(9) << " ��� �����" << " |" << endl
		<< setfill('=') << setw(92) << '=' << endl << setfill(' ');
}