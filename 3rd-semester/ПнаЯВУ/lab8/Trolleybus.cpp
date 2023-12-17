#include "Trolleybus.h"

float Trolleybus::get_power_consumption() { return power_consumption; }			//�������-�������
void Trolleybus::set_power_consumption(float f) { power_consumption = f; }

Trolleybus Trolleybus::operator=(const Trolleybus& obj)							//�������� ������������
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		//���������� � ������������� ����
	this->power_consumption = obj.power_consumption;

	return *this;
}

bool Trolleybus::operator==(const Trolleybus& other)							                    //�������� ���������
{
    if (!(dynamic_cast<Passenger&>(*this) == dynamic_cast<const Passenger&>(other)))
        return false;
    if (other.power_consumption != 0.0 && this->power_consumption != other.power_consumption)
        return false;

    return true;
}

bool Trolleybus::operator>(const Trolleybus& other)		                                            //�������� ������
{
    if (reinterpret_cast<Passenger&>(*this) < reinterpret_cast<const Passenger&>(other))
        return false;
    if (other.power_consumption != 0.0 && this->power_consumption < other.power_consumption)
        return false;

    return true;
}

bool Trolleybus::operator<(const Trolleybus& other)	                            //�������� ������
{
    return !(*this > other);
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
        strcpy_s(tmp, STR_LEN, inputString(cin));
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

int Trolleybus::chooseSortParameter()				        //������� ������ ���� ����������
{
    int select = 0;

    cout << "���������� ��: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. �����������������" << endl << "6. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 6);
    switch (select)
    {
    case 6:                                                 //������
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Trolleybus Trolleybus::copyParameter(int n)                 //������� ����������� ����
{
    Trolleybus result;

    switch (n)
    {
    case 1:
    {
        result.set_max_speed(this->get_max_speed());
        break;
    }
    case 2:
    {
        result.set_model(this->get_model());
        break;
    }
    case 3:
    {
        result.set_passengers(this->get_passengers());
        break;
    }
    case 4:
    {
        result.set_route(this->get_route());
        break;
    }
    case 5:
    {
        result.set_power_consumption(this->get_power_consumption());
        break;
    }
    }

    return result;
}
