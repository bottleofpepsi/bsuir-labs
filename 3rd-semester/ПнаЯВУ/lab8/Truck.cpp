#include "Truck.h"

float Truck::get_load() const { return load; }									//�������-�������
void Truck::set_load(float f) { load = f; }

Truck Truck::operator=(const Truck& obj)										//�������� ������������
{
	dynamic_cast<Cargo&>(*this) = dynamic_cast<const Cargo&>(obj);				//���������� � ������������� ����
	this->load = obj.load;

	return *this;
}

bool Truck::operator==(const Truck& other)							            //�������� ���������
{
	if (!(dynamic_cast<Cargo&>(*this) == dynamic_cast<const Cargo&>(other)))
		return false;
	if (other.load != 0.0 && this->load != other.load)
		return false;

	return true;
}

bool Truck::operator>(const Truck& other)                                       //�������� ������
{
    if (reinterpret_cast<Cargo&>(*this) < reinterpret_cast<const Cargo&>(other))
        return false;
    if (other.load != 0.0 && this->load < other.load)
        return false;

    return true;
}

bool Truck::operator<(const Truck& other)	                                    //�������� ������
{
    return !(*this > other);
}

bool operator>(const Truck& obj1, const Truck& obj2)							//�������� ������
{
    return reinterpret_cast<const Cargo&>(obj1) > reinterpret_cast<const Cargo&>(obj2);
}

bool operator<(const Truck& obj1, const Truck& obj2)							//�������� ������
{
    return reinterpret_cast<const Cargo&>(obj1) < reinterpret_cast<const Cargo&>(obj2);
}

istream& operator>>(istream& in, Truck& obj)								    //�������� �����
{
    in >> dynamic_cast<Cargo&>(obj);									        //���������� � ������������� ����
    cout << "������� ��� �����: ";
    obj.load = inputFloat(in);
    return in;
}

ostream& operator<<(ostream& out, const Truck& obj)							    //�������� ������
{
    out << dynamic_cast<const Cargo&>(obj) << setprecision(4)			        //���������� � ������������� ����
        << setw(5) << obj.load << " " << setw(3) << "�" << " |" << endl;

    return out;
}

ifstream& operator>>(ifstream& in, Truck& obj)					    //�������� ������ �� ���������� �����
{
    in >> dynamic_cast<Cargo&>(obj);
    in >> obj.load;
    return in;
}

ofstream& operator<<(ofstream& out, Truck& obj)			            //�������� ������ � ��������� ����
{
    out << dynamic_cast<Cargo&>(obj);
    out << " " << obj.load << endl;
    return out;
}

fstream& operator>>(fstream& in, Truck& obj)					    //�������� ������ �� ��������� �����
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Truck));
    return in;
}

fstream& operator<<(fstream& out, Truck& obj)				        //�������� ������ � �������� ����
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Truck));
    return out;
}

int Truck::display()											    //����� �������
{
	Cargo::display();
	cout << setw(9) << " ��� �����" << " |" << endl
		<< setfill('=') << setw(92) << '=' << endl << setfill(' ');

    return 92;
}

bool Truck::chooseParameters()                              //���� ����� ���������� ��� Truck
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ��� �����" << endl << "4. ����� ����������" << endl
        << "5. ��� �����" << endl << "6. ����� ����������" << endl << "7. �����" << endl;

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
        char tmp[15];
        cout << "��������: ";
        strcpy_s(tmp, 15, inputString(cin));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //��� �����
    {
        char tmp[15];
        cout << "��������: ";
        strcpy_s(tmp, 15, inputCyrillicString(cin));
        this->set_load_type(tmp);
        break;
    }
    case 4:                                                 //����� ����������
    {
        char tmp[15];
        cout << "��������: ";
        strcpy_s(tmp, 15, inputCyrillicString(cin));
        this->set_destination(tmp);
        break;
    }
    case 5:                                                 //��� �����
    {
        float tmp = 0;
        cout << "��������: ";
        tmp = inputFloat(cin, 0);
        this->set_load(tmp);
        break;
    }
    case 6:                                                 //����� ����������
    {
        *this = Truck();
        break;
    }
    case 7:                                                 //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}

int Truck::chooseSortParameter()							//������� ������ ���� ����������
{
    int select = 0;

    cout << "���������� ��: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ��� �����" << endl << "4. ����� ����������" << endl
        << "5. ��� �����" << endl << "6. �����" << endl;

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

Truck Truck::copyParameter(int n)   	                    //������� ����������� ����
{
    Truck result;

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
        result.set_load_type(this->get_load_type());
        break;
    }
    case 4:
    {
        result.set_destination(this->get_destination());
        break;
    }
    case 5:
    {
        result.set_load(this->get_load());
        break;
    }
    }

    return result;
}