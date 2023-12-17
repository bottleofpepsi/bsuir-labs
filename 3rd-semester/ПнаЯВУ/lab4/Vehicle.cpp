#include "Vehicle.h"

float Vehicle::get_max_speed() { return max_speed; }							//�������-�������
void Vehicle::set_max_speed(float f) { max_speed = f; }
char* Vehicle::get_model() { return model; }
void Vehicle::set_model(const char* s) { strcpy_s(model, 15, s); }

Vehicle Vehicle::operator=(const Vehicle& obj)									//�������� ������������
{
	this->max_speed = obj.max_speed;
	strcpy_s(this->model, 15, obj.model);

	return *this;
}

bool operator==(const Vehicle& obj1, const Vehicle& obj2)						//�������� ���������
{
	if (obj1.max_speed != 0.0 && obj1.max_speed != obj2.max_speed)
		return false;
	if (strcmp(obj1.model, "") && strcmp(obj1.model, obj2.model))
		return false;

	return true;
}

istream& operator>>(istream& in, Vehicle& obj)									//�������� �����
{
	cout << "������� ����. ��������: ";
	in >> obj.max_speed;
	in.ignore(INT_MAX, '\n');
	cout << "������� ������: ";
	in.getline(obj.model, 15, '\n');
	return in;
}

ostream& operator<<(ostream& out, const Vehicle& obj)							//�������� ������
{
	out.precision(5);
	out << "| "
		<< setw(6) << obj.max_speed << " " << setw(14) << "��/�" << " | "
		<< setw(15) << obj.model << " | ";

	return out;
}

void Vehicle::display()															//����� �������
{
	cout << left << setfill('=') << setw(92) << '=' << endl << setfill(' ') 
		 << setw(21) << "| ������������ ��������" << " | "
		<< setw(15) << "������" << " |";
}

bool Vehicle::chooseParameters()                                                //���� ������ ���������� ��� Vehicle
{
    int select = 0;

    cout << "�������� ������: " << endl
         << "1. ������������ ��������" << endl << "2. ������" << endl
         << "3. ����� ����������" << endl << "4. �����" << endl;

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
    case 3:                                     //����� ��������� ����������
    {
        *this = Vehicle();
        break;
    }
    case 4:                                     //����� ���������� �������
    {
        return true;
    }
    }

    return false;
}