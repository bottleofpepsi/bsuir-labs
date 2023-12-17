#include "Trolleybus.h"

float Trolleybus::get_power_consumption() { return power_consumption; }			//�������-�������
void Trolleybus::set_power_consumption(float f) { power_consumption = f; }

Trolleybus Trolleybus::operator=(const Trolleybus& obj)							//�������� ������������
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//���������� � ������������� ����
	this->power_consumption = obj.power_consumption;

	return *this;
}

bool operator==(const Trolleybus& obj1, const Trolleybus& obj2)					//�������� ���������
{
	if (!(dynamic_cast<const Passenger&>(obj1) == dynamic_cast<const Passenger&>(obj2)))
		return false;
	if (obj1.power_consumption != 0.0 && obj1.power_consumption != obj2.power_consumption)
		return false;

	return true;
}


istream& operator>>(istream& in, Trolleybus& obj)								//�������� �����
{
	in >> dynamic_cast<Passenger&>(obj);										//���������� � ������������� ����
	cout << "������� �����������������: ";
	in >> obj.power_consumption;				
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

bool Trolleybus::chooseParameters()                                             //���� ������ ��� Trolleybus
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. �����������������" << endl << "6. ����� ����������" << endl << "7. �����" << endl;

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
    case 5:                                     //�����������������
    {
        float tmp = 0;
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_power_consumption(tmp);
        break;
    }
    case 6:                                     //����� ����������
    {
        *this = Trolleybus();
        break;
    }
    case 7:                                     //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}