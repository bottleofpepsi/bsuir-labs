#include "Cargo.h"

char* Cargo::get_load_type() { return load_type; }								//�������-�������
void Cargo::set_load_type(const char* s) { strcpy_s(load_type, STR_LEN, s); }
char* Cargo::get_destination() { return destination; }
void Cargo::set_destination(const char* s) { strcpy_s(destination, STR_LEN, s); }

Cargo Cargo::operator=(const Cargo& obj)										//�������� ������������
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			//���������� � ������������� ����
	strcpy_s(this->load_type, STR_LEN, obj.load_type);
	strcpy_s(this->destination, STR_LEN, obj.destination);

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

istream& operator>>(istream& in, Cargo& obj)						//�������� �����
{
    in >> dynamic_cast<Vehicle&>(obj);								//���������� � ������������� ����
    cout << "������� ��� �����: ";
    strcpy_s(obj.load_type, STR_LEN, inputCyrillicString(in, STR_LEN));
    cout << "������� ����� ����������: ";
    strcpy_s(obj.destination, STR_LEN, inputCyrillicString(in, STR_LEN));
    return in;
}

ostream& operator<<(ostream& out, Cargo& obj)						//�������� ������
{
    out << dynamic_cast<Vehicle&>(obj)								//���������� � ������������� ����
        << setw(15) << obj.load_type << " | "
        << setw(16) << obj.destination << " | ";

    return out;
}

ifstream& operator>>(ifstream& in, Cargo& obj)					    //�������� ������ �� ���������� �����
{
    in >> dynamic_cast<Vehicle&>(obj);
    in.get();
    in.getline(obj.load_type, STR_LEN, '|');
    in.get();
    in.getline(obj.destination, STR_LEN, '|');
    return in;
}

ofstream& operator<<(ofstream& out, Cargo& obj)			            //�������� ������ � ��������� ����
{
    out << dynamic_cast<Vehicle&>(obj);
    out << " " << obj.load_type << "| " << obj.destination << "|";
    return out;
}

fstream& operator>>(fstream& in, Cargo& obj)					    //�������� ������ �� ��������� �����
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Cargo));
    return in;
}

fstream& operator<<(fstream& out, Cargo& obj)				        //�������� ������ � �������� ����
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Cargo));
    return out;
}

int Cargo::display()												//����� �������
{
	Vehicle::display();
	cout << setw(16) << " ��� �����" << " | "
		<< setw(15) << "����� ����������" << " |";

    return 92;
}

bool Cargo::chooseParameters()                                      //������� ������ ����������
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ��� �����" << endl << "4. ����� ����������" << endl
        << "5. ����� ����������" << endl << "6. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 6);
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
    case 5:                                                 //����� ����������
    {
        *this = Cargo();
        break;
    }
    case 6:                                                 //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}