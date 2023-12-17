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

bool operator==(const Passenger& obj1, const Passenger& obj2)					//�������� ���������
{
	if (!(dynamic_cast<const Vehicle&>(obj1) == dynamic_cast<const Vehicle&>(obj2)))
		return false;
	if (obj1.passengers != 0 && obj1.passengers != obj2.passengers)
		return false;
	if (obj1.route != 0 && obj1.route != obj2.route)
		return false;

	return true;
}

istream& operator>>(istream& in, Passenger& obj)								//�������� �����
{
	in >> dynamic_cast<Vehicle&>(obj);											//���������� � ������������� ����
	cout << "������� ���-�� ����������: ";
	in >> obj.passengers;
	cout << "������� �������: ";
	in >> obj.route;
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

bool Passenger::chooseParameters()                                         //���� ������ ���������� ��� Passenger
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. ����� ����������" << endl << "6. �����" << endl;

    cout << endl << "����: ";
    cin >> select;
    switch (select)
    {
    case 1:                                         //����. ��������
    {
        float tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                         //������
    {
        char tmp[15];
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_model(tmp);
        break;
    }
    case 3:                                         //���-�� ����������
    {
        int tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_passengers(tmp);
        break;
    }
    case 4:                                         //�������
    {
        int tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_route(tmp);
        break;
    }
    case 5:                                         //����� ����������
    {
        *this = Passenger();
        break;
    }
    case 6:                                         //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}