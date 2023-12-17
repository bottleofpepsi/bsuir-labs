#include "Cargo.h"

char* Cargo::get_load_type() { return load_type; }						            //�������-�������
void Cargo::set_load_type(const char* s) { strcpy_s(load_type, STR_LEN, s); }
char* Cargo::get_destination() { return destination; }
void Cargo::set_destination(const char* s) { strcpy_s(destination, STR_LEN, s); }

Cargo Cargo::operator=(const Cargo& obj)										    //�������� ������������
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			    //���������� � ������������� ����
	strcpy_s(this->load_type, STR_LEN, obj.load_type);
	strcpy_s(this->destination, STR_LEN, obj.destination);

	return *this;
}

bool Cargo::operator==(const Cargo& other)							                //�������� ���������
{
	if (!(dynamic_cast<Vehicle&>(*this) == dynamic_cast<const Vehicle&>(other)))
		return false;
	if (strcmp(other.destination, "") && strcmp(this->destination, other.destination))
		return false;
	if (strcmp(other.load_type, "") && strcmp(this->load_type, other.load_type))
		return false;

	return true;
}

bool Cargo::operator>(const Cargo& other)		                                    //�������� ������
{
    if (reinterpret_cast<Vehicle&>(*this) < reinterpret_cast<const Vehicle&>(other))
        return false;
    if (strcmp(other.destination, "") && strcmp(this->destination, other.destination) <= 0)
        return false;
    if (strcmp(other.load_type, "") && strcmp(this->load_type, other.load_type) <=0)
        return false;

    return true;
}

bool Cargo::operator<(const Cargo& other)	                        //�������� ������
{
    return !(*this > other);
}

bool operator>(const Cargo& obj1, const Cargo& obj2)				//�������� ������
{
    return reinterpret_cast<const Vehicle&>(obj1) > reinterpret_cast<const Vehicle&>(obj2);
}

bool operator<(const Cargo& obj1, const Cargo& obj2)				//�������� ������
{
    return reinterpret_cast<const Vehicle&>(obj1) < reinterpret_cast<const Vehicle&>(obj2);
}

istream& operator>>(istream& in, Cargo& obj)						//�������� �����
{
    in >> dynamic_cast<Vehicle&>(obj);								//���������� � ������������� ����
    cout << "������� ��� �����: ";
    strcpy_s(obj.load_type, STR_LEN, inputCyrillicString(in));
    cout << "������� ����� ����������: ";
    strcpy_s(obj.destination, STR_LEN, inputCyrillicString(in));
    return in;
}

ostream& operator<<(ostream& out, const Cargo& obj)				    //�������� ������
{
    out << dynamic_cast<const Vehicle&>(obj)				        //���������� � ������������� ����
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
        strcpy_s(tmp, STR_LEN, inputString(cin));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //��� �����
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin));
        this->set_load_type(tmp);
        break;
    }
    case 4:                                                 //����� ����������
    {
        char tmp[STR_LEN];
        cout << "��������: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin));
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

int Cargo::chooseSortParameter()							//������� ������ ���� ����������
{
    int select = 0;

    cout << "���������� ��: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ��� �����" << endl << "4. ����� ����������" << endl
        << "5. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 5);
    switch (select)
    {
    case 5:                                                 //������
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Cargo Cargo::copyParameter(int n)   	                    //������� ����������� ����
{
    Cargo result;

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
    }

    return result;
}