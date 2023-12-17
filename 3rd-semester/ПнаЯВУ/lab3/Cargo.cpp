#include "Cargo.h"

char* Cargo::get_load_type() { return load_type; }								//�������-�������
void Cargo::set_load_type(const char* s) { strcpy_s(load_type, 15, s); }
char* Cargo::get_destination() { return destination; }
void Cargo::set_destination(const char* s) { strcpy_s(destination, 15, s); }

Cargo Cargo::operator=(const Cargo& obj)										//�������� ������������
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			//���������� � ������������� ����
	strcpy_s(this->load_type, 15, obj.load_type);
	strcpy_s(this->destination, 15, obj.destination);

	return *this;
}

istream& operator>>(istream& in, Cargo& obj)									//�������� �����
{
	in >> dynamic_cast<Vehicle&>(obj);											//���������� � ������������� ����
	in.getline(obj.load_type, 15, '\n');
	in.getline(obj.destination, 15, '\n');
	return in;
}

ostream& operator<<(ostream& out, const Cargo& obj)								//�������� ������
{
	out << dynamic_cast<const Vehicle&>(obj)									//���������� � ������������� ����
		<< setw(15) << obj.load_type << " | "
		<< setw(16) << obj.destination << " | ";

	return out;
}

void Cargo::display()															//����� �������
{
	Vehicle::display();
	cout << setw(16) << " ��� �����" << " | "
		<< setw(15) << "����� ����������" << " |";
}