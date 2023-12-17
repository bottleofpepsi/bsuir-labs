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
	obj.passengers = inputInt(in);
	cout << "������� �������: ";
	obj.route = inputInt(in);
	return in;
}

ostream& operator<<(ostream& out, Passenger& obj)							    //�������� ������
{	
	out << dynamic_cast<Vehicle&>(obj)									        //���������� � ������������� ����
		<< setw(3) << obj.passengers << setw(14) << " ���" << " | "
		<< setw(10) << obj.route << " | ";

	return out;
}

ifstream& operator>>(ifstream& in, Passenger& obj)				                //�������� ������ �� ���������� �����
{
    in >> dynamic_cast<Vehicle&>(obj);
    in >> obj.passengers >> obj.route;
    return in;
}

ofstream& operator<<(ofstream& out, Passenger& obj)			                    //�������� ������ � ��������� ����
{
    out << dynamic_cast<Vehicle&>(obj);
    out << " " << obj.passengers << " " << obj.route;
    return out;
}

fstream& operator>>(fstream& in, Passenger& obj)					            //�������� ������ �� ��������� �����
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Passenger));
    return in;
}

fstream& operator<<(fstream& out, Passenger& obj)			                    //�������� ������ � �������� ����
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Passenger));
    return out;
}

int Passenger::display()														//����� �������
{
	cout << left << setfill('=') << setw(76) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "������������ ��������" << " | "
		<< setw(15) << "������" << " | "
		<< setw(17) << "���-�� ����������" << " | "
		<< setw(10) << "� ��������" << " | " << endl
		<< setfill('=') << setw(76) << '=' << endl << setfill(' ');

    return 76;
}

bool Passenger::chooseParameters()                      //���� ������ ���������� ��� Passenger
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. ����� ����������" << endl << "6. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 6);
    switch (select)
    {
    case 1:                                             //����. ��������
    {
        float tmp = 0;
        cout << "��������: ";
        tmp = inputFloat(cin, 0);
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                             //������
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputString(cin, STR_LEN));
        this->set_model(tmp);
        break;
    }
    case 3:                                             //���-�� ����������
    {
        int tmp = 0;
        cout << "��������: ";
        tmp = inputInt(cin, 0);
        this->set_passengers(tmp);
        break;
    }
    case 4:                                             //�������
    {
        int tmp = 0;
        cout << "��������: ";
        tmp = inputInt(cin, 0);
        this->set_route(tmp);
        break;
    }
    case 5:                                             //����� ����������
    {
        *this = Passenger();
        break;
    }
    case 6:                                             //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}