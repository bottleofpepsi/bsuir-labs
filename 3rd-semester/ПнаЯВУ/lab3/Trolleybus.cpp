#include "Trolleybus.h"

float Trolleybus::get_power_consumption() { return power_consumption; }			//�������-�������
void Trolleybus::set_power_consumption(float f) { power_consumption = f; }

Trolleybus Trolleybus::operator=(const Trolleybus& obj)							//�������� ������������
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//���������� � ������������� ����
	this->power_consumption = obj.power_consumption;

	return *this;
}

istream& operator>>(istream& in, Trolleybus& obj)								//�������� �����
{
	in >> dynamic_cast<Passenger&>(obj) >> obj.power_consumption;				//���������� � ������������� ����
	return in;
}

ostream& operator<<(ostream& out, const Trolleybus& obj)						//�������� ������
{
	out << dynamic_cast<const Passenger&>(obj)									//���������� � ������������� ����
		<< setw(6) << obj.power_consumption << setw(11) << " ���*�" << " |" << endl;

	return out;
}

void Trolleybus::display()														//����� �������
{
	cout << left << setfill('=') << setw(96) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "������������ ��������" << " | "
		<< setw(15) << "������" << " | "
		<< setw(17) << "���-�� ����������" << " | "
		<< setw(10) << "� ��������" << " | "
		<< setw(17) << "�����������������" << " | " << endl
		<< setfill('=') << setw(96) << '=' << endl << setfill(' ');
}