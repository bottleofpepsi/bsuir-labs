#include "Passenger.h"

int Passenger::get_passengers() { return passengers; }							//�������-�������
void Passenger::set_passengers(int i) { passengers = i; }
int Passenger::get_route() { return route; }
void Passenger::set_route(int i) { route = i; }

Passenger Passenger::operator=(const Passenger& obj)							//�������� ������������
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			//���������� � ������������� ����
	this->passengers = obj.passengers;
	this->route = obj.route;

	return *this;
}

istream& operator>>(istream& in, Passenger& obj)								//�������� �����
{
	in >> dynamic_cast<Vehicle&>(obj) >> obj.passengers >> obj.route;			//���������� � ������������� ����
	return in;
}

ostream& operator<<(ostream& out, const Passenger& obj)							//�������� ������
{	
	out << dynamic_cast<const Vehicle&>(obj)									//���������� � ������������� ����
		<< setw(3) << obj.passengers << setw(14) << " ���" << " | "
		<< setw(10) << obj.route << " | ";

	return out;
}

void Passenger::display()														//����� �������
{
	cout << left << setfill('=') << setw(76) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "������������ ��������" << " | "
		<< setw(15) << "������" << " | "
		<< setw(17) << "���-�� ����������" << " | "
		<< setw(10) << "� ��������" << " | " << endl
		<< setfill('=') << setw(76) << '=' << endl << setfill(' ');
}