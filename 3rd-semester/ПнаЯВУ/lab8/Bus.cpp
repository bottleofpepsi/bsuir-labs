#include "Bus.h"

float Bus::get_fuel() { return fuel; }											        //�������-�������
void Bus::set_fuel(float f) { fuel = f; }

Bus Bus::operator=(const Bus& obj)												        //�������� ������������
{
	dynamic_cast<Passenger&>(*this) = dynamic_cast<const Passenger&>(obj);		        //���������� � ������������� ����
	this->fuel = obj.fuel;

	return *this;
}

bool Bus::operator==(const Bus& other)							                        //�������� ���������
{
    if (!(dynamic_cast<Passenger&>(*this) == dynamic_cast<const Passenger&>(other)))
        return false;
    if (other.fuel != 0.0 && this->fuel != other.fuel)
        return false;

    return true;
}

bool Bus::operator>(const Bus& other)		                                            //�������� ������
{
    if (reinterpret_cast<Passenger&>(*this) < reinterpret_cast<const Passenger&>(other))
        return false;
    if (other.fuel != 0.0 && this->fuel < other.fuel)
        return false;

    return true;
}

bool Bus::operator<(const Bus& other)	                                    //�������� ������
{
    return !(*this > other);
}

istream& operator>>(istream& in, Bus& obj)									//�������� �����
{
	in >> dynamic_cast<Passenger&>(obj);								    //���������� � ������������� ����
	cout << "������� ������ �������: ";
	obj.fuel = inputFloat(in);
	return in;
}

ostream& operator<<(ostream& out, Bus& obj)								    //�������� ������
{
	out << dynamic_cast<Passenger&>(obj)									//���������� � ������������� ����
		<< setw(6) << obj.fuel << setw(8) << " �/100��" << " |" << endl;

	return out;
}

ifstream& operator>>(ifstream& in, Bus& obj)				                //�������� ������ �� ���������� �����
{
    in >> dynamic_cast<Passenger&>(obj);
    in >> obj.passengers >> obj.route;
    return in;
}

ofstream& operator<<(ofstream& out, Bus& obj)			                    //�������� ������ � ��������� ����
{
    out << dynamic_cast<Passenger&>(obj);
    out << " " << obj.fuel << endl;
    return out;
}

fstream& operator>>(fstream& in, Bus& obj)					                //�������� ������ �� ��������� �����
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Bus));
    return in;
}

fstream& operator<<(fstream& out, Bus& obj)			                        //�������� ������ � �������� ����
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Bus));
    return out;
}

int Bus::display()															//����� �������
{
	cout << left << setfill('=') << setw(93) << '=' << endl << setfill(' ') << "| "
		<< setw(21) << "������������ ��������" << " | "
		<< setw(15) << "������" << " | "
		<< setw(17) << "���-�� ����������" << " | "
		<< setw(10) << "� ��������" << " | "
		<< setw(14) << "������ �������" << " | " << endl
		<< setfill('=') << setw(93) << '=' << endl << setfill(' ');

    return 93;
}

bool Bus::chooseParameters()                            //���� ����� ���������� ��� Bus
{
    Bus tempObj;
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. ������ �������" << endl << "6. ����� ����������" << endl << "7. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 7);
    switch (select)
    {
    case 1:                                             //����. ��������
    {
        float tmp = 0;
        cout << "��������: ";
        tmp = inputFloat(cin, 0);
        tempObj.set_max_speed(tmp);
        break;
    }
    case 2:                                             //������
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputString(cin));
        tempObj.set_model(tmp);
        break;
    }
    case 3:                                             //���-�� ����������
    {
        int tmp = 0;
        cout << "��������: ";
        tmp = inputInt(cin, 0);
        tempObj.set_passengers(tmp);
        break;
    }
    case 4:                                             //�������
    {
        int tmp = 0;
        cout << "��������: ";
        tmp = inputInt(cin, 0);
        tempObj.set_route(tmp);
        break;
    }
    case 5:                                             //������ �������
    {
        float tmp = 0;
        cout << "��������: ";
        tmp = inputFloat(cin, 0);
        tempObj.set_fuel(tmp);
        break;
    }
    case 6:                                             //����� ����������
    {
        *this = Bus();
        break;
    }
    case 7:                                             //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}

int Bus::chooseSortParameter()					        //������� ������ ���� ����������
{
    int select = 0;

    cout << "���������� ��: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ������������ ���-�� ����������" << endl << "4. �������" << endl
        << "5. ������ �������" << endl << "6. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 6);
    switch (select)
    {
    case 6:                                             //������
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Bus Bus::copyParameter(int n)   	                    //������� ����������� ����
{
    Bus result;

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
        result.set_fuel (this->get_fuel());
        break;
    }
    }

    return result;
}
