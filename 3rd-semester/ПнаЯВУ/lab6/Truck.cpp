#include "Truck.h"

float Truck::get_load() { return load; }										//�������-�������
void Truck::set_load(float f) { load = f; }

Truck Truck::operator=(const Truck& obj)										//�������� ������������
{
	dynamic_cast<Cargo&>(*this) = dynamic_cast<const Cargo&>(obj);				//���������� � ������������� ����
	this->load = obj.load;

	return *this;
}

bool operator==(const Truck& obj1, const Truck& obj2)							//�������� ���������
{
	if (!(dynamic_cast<const Cargo&>(obj1) == dynamic_cast<const Cargo&>(obj2)))
		return false;
	if (obj1.load != 0.0 && obj1.load != obj2.load)
		return false;

	return true;
}

istream& operator>>(istream& in, Truck& obj)								//�������� �����
{
    in >> dynamic_cast<Cargo&>(obj);									    //���������� � ������������� ����
    cout << "������� ��� �����: ";
    obj.load = inputFloat(in);
    return in;
}

ostream& operator<<(ostream& out, Truck& obj)							    //�������� ������
{
    out << dynamic_cast<Cargo&>(obj) << setprecision(4)					    //���������� � ������������� ����
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
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputString(cin, STR_LEN));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //��� �����
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin, STR_LEN));
        this->set_load_type(tmp);
        break;
    }
    case 4:                                                 //����� ����������
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin, STR_LEN));
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