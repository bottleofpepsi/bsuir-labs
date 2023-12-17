#include "Bus.h"

float Bus::get_fuel() { return fuel; }											//�������-�������
void Bus::set_fuel(float f) { fuel = f; }

Bus Bus::operator=(const Bus& obj)												//�������� ������������
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//���������� � ������������� ����
	this->fuel = obj.fuel;

	return *this;
}

istream& operator>>(istream& in, Bus& obj)										//�������� �����
{
	in >> dynamic_cast<Passenger&>(obj) >> obj.fuel;							//���������� � ������������� ����
	return in;
}

ostream& operator<<(ostream& out, const Bus& obj)								//�������� ������
{
	out << dynamic_cast<const Passenger&>(obj)									//���������� � ������������� ����
		<< setw(6) << obj.fuel << setw(8) << " �/100��" << " |" << endl;

	return out;
}

void Bus::display()																//����� �������
{
	cout << left << setfill('=') << setw(93) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "������������ ��������" << " | "
		<< setw(15) << "������" << " | "
		<< setw(17) << "���-�� ����������" << " | "
		<< setw(10) << "� ��������" << " | "
		<< setw(14) << "������ �������" << " | " << endl
		<< setfill('=') << setw(93) << '=' << endl << setfill(' ');
}