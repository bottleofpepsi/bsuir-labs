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
	obj.power_consumption = inputFloat(in);
	return in;
}

ostream& operator<<(ostream& out, Trolleybus& obj)						        //�������� ������
{
	out << dynamic_cast<Passenger&>(obj)									    //���������� � ������������� ����
		<< setw(6) << obj.power_consumption << setw(11) << " ���*�" << " |" << endl;

	return out;
}

ifstream& operator>>(ifstream& in, Trolleybus& obj)				                //�������� ������ �� ���������� �����
{
    in >> dynamic_cast<Passenger&>(obj);
    in >> obj.power_consumption;
    return in;
}

ofstream& operator<<(ofstream& out, Trolleybus& obj)			                //�������� ������ � ��������� ����
{
    out << dynamic_cast<Passenger&>(obj);
    out << " " << obj.power_consumption << endl;
    return out;
}

fstream& operator>>(fstream& in, Trolleybus& obj)					            //�������� ������ �� ��������� �����
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Trolleybus));
    return in;
}

fstream& operator<<(fstream& out, Trolleybus& obj)			                    //�������� ������ � �������� ����
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Trolleybus));
    return out;
}

int Trolleybus::display()														//����� �������
{
	cout << left << setfill('=') << setw(96) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "������������ ��������" << " | "
		<< setw(15) << "������" << " | "
		<< setw(17) << "���-�� ����������" << " | "
		<< setw(10) << "� ��������" << " | "
		<< setw(17) << "�����������������" << " | " << endl
		<< setfill('=') << setw(96) << '=' << endl << setfill(' ');

    return 96;
}

bool Trolleybus::chooseParameters()                         //���� ������ ��� Trolleybus
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. �����������������" << endl << "6. ����� ����������" << endl << "7. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 7);
    switch (select)
    {
    case 1:                                                 //����. ��������
    {
        float tmp = 0;
        cout << "��������: ";
        tmp = inputFloat(cin, 0);
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                                 //������
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputString(cin, STR_LEN));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //���-�� ����������
    {
        int tmp = 0;
        cout << "��������: ";
        tmp = inputInt(cin, 0);
        this->set_passengers(tmp);
        break;
    }
    case 4:                                                 //�������
    {
        int tmp = 0;
        cout << "��������: ";
        tmp = inputInt(cin, 0);
        this->set_route(tmp);
        break;
    }
    case 5:                                                 //�����������������
    {
        float tmp = 0;
        cout << "��������: ";
        tmp = inputFloat(cin, 0);
        this->set_power_consumption(tmp);
        break;
    }
    case 6:                                                 //����� ����������
    {
        *this = Trolleybus();
        break;
    }
    case 7:                                                 //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}