#include "Vehicle.h"

float Vehicle::get_max_speed() { return max_speed; }							//�������-�������
void Vehicle::set_max_speed(float f) { max_speed = f; }
char* Vehicle::get_model() { return model; }
void Vehicle::set_model(const char* s) { strcpy_s(model, 15, s); }

Vehicle Vehicle::operator=(const Vehicle& obj)									//�������� ������������
{
	this->max_speed = obj.max_speed;
	strcpy_s(this->model, STR_LEN, obj.model);

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
	obj.max_speed = inputFloat(in, 0);
	cout << "������� ������: ";	
	strcpy_s(obj.model, STR_LEN, inputString(in, STR_LEN));
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

bool Vehicle::chooseParameters()                            //���� ������ ���������� ��� Vehicle
{
    int select = 0;

    cout << "�������� ������: " << endl
        << "1. ������������ ��������" << endl << "2. ������" << endl
        << "3. ����� ����������" << endl << "4. �����" << endl;

    cout << endl << "����: ";
    select = inputInt(cin, 1, 4);
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
    case 3:                                                 //����� ��������� ����������
    {
        *this = Vehicle();
        break;
    }
    case 4:                                                 //����� ���������� �������
    {
        return true;                                                            
    }
    }

    return false;
}