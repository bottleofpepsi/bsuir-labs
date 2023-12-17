#include "Vehicle.h"

float Vehicle::get_max_speed() { return max_speed; }							//�������-�������
void Vehicle::set_max_speed(float f) { max_speed = f; }
char* Vehicle::get_model() { return model; }
void Vehicle::set_model(const char* s) { strcpy_s(model, 15, s); }

Vehicle Vehicle::operator=(const Vehicle& obj)									//�������� ������������
{
	this->max_speed = obj.max_speed;
	strcpy_s(this->model, 15, obj.model);

	return *this;
}

istream& operator>>(istream& in, Vehicle& obj)									//�������� �����
{
	in >> obj.max_speed;
	cin.ignore(INT_MAX, '\n');
	in.getline(obj.model, 15, '\n');
	return in;
}

ostream& operator<<(ostream& out, const Vehicle& obj)							//�������� ������
{
	out.precision(5);
	out << "| "
		<< setw(6) << obj.max_speed << " " << setw(14) << "��/�" << " | "
		<< setw(15) << obj.model << " | ";

	return out;
}

void Vehicle::display()															//����� �������
{
	cout << left << setfill('=') << setw(92) << '=' << endl << setfill(' ') 
		 << setw(21) << "| ������������ ��������" << " | "
		<< setw(15) << "������" << " |";
}