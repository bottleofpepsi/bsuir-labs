#include "Bus.h"

float Bus::get_fuel() { return fuel; }											//�������-�������
void Bus::set_fuel(float f) { fuel = f; }

Bus Bus::operator=(const Bus& obj)												//�������� ������������
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//���������� � ������������� ����
	this->fuel = obj.fuel;

	return *this;
}

bool operator==(const Bus& obj1, const Bus& obj2)								//�������� ���������
{
	if (!(dynamic_cast<const Passenger&>(obj1) == dynamic_cast<const Passenger&>(obj2)))
		return false;
	if (obj1.fuel != 0.0 && obj1.fuel != obj2.fuel)
		return false;

	return true;
}

istream& operator>>(istream& in, Bus& obj)										//�������� �����
{
	in >> dynamic_cast<Passenger&>(obj);										//���������� � ������������� ����
	cout << "������� ������ �������: ";
	in >> obj.fuel;							
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

bool Bus::chooseParameters()                                                    //���� ����� ���������� ��� Bus
{
    Bus tempObj;
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. ������ �������" << endl << "6. ����� ����������" << endl << "7. �����" << endl;

    cout << endl << "����: ";
    cin >> select;
    switch (select)
    {
    case 1:                                     //����. ��������
    {
        float tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                     //������
    {
        char tmp[15];
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_model(tmp);
        break;
    }
    case 3:                                     //���-�� ����������
    {
        int tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_passengers(tmp);
        break;
    }
    case 4:                                     //�������
    {
        int tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_route(tmp);
        break;
    }
    case 5:                                     //������ �������
    {
        float tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_fuel(tmp);
        break;
    }
    case 6:                                     //����� ����������
    {
        *this = Bus();
        break;
    }
    case 7:                                     //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}