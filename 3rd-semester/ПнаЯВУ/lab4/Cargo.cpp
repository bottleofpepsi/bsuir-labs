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

bool operator==(const Cargo& obj1, const Cargo& obj2)							//�������� ���������
{
	if (!(dynamic_cast<const Vehicle&>(obj1) == dynamic_cast<const Vehicle&>(obj2)))
		return false;
	if (strcmp(obj1.destination, "") && strcmp(obj1.destination, obj2.destination))
		return false;
	if (strcmp(obj1.load_type, "") && strcmp(obj1.load_type, obj2.load_type))
		return false;

	return true;
}

istream& operator>>(istream& in, Cargo& obj)					//�������� �����
{
	in >> dynamic_cast<Vehicle&>(obj);							//���������� � ������������� ����
	cout << "������� ��� �����: ";
	in.getline(obj.load_type, 15, '\n');
	cout << "������� ����� ����������: ";
	in.getline(obj.destination, 15, '\n');
	return in;
}

ostream& operator<<(ostream& out, const Cargo& obj)				//�������� ������
{
	out << dynamic_cast<const Vehicle&>(obj)					//���������� � ������������� ����
		<< setw(15) << obj.load_type << " | "
		<< setw(16) << obj.destination << " | ";

	return out;
}

void Cargo::display()											//����� �������
{
	Vehicle::display();
	cout << setw(16) << " ��� �����" << " | "
		<< setw(15) << "����� ����������" << " |";
}

bool Cargo::chooseParameters()                                  //������� ������ ����������
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ��� �����" << endl << "4. ����� ����������" << endl
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
    case 3:                                         //��� �����
    {
        char tmp[15];
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_load_type(tmp);
        break;
    }
    case 4:                                         //����� ����������
    {
        char tmp[15];
        cout << "��������: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_destination(tmp);
        break;
    }
    case 5:                                         //����� ����������
    {
        *this = Cargo();
        break;
    }
    case 6:                                         //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}
