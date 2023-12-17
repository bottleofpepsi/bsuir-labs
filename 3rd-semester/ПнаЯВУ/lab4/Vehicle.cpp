#include "Vehicle.h"

float Vehicle::get_max_speed() { return max_speed; }							//геттеры-сеттеры
void Vehicle::set_max_speed(float f) { max_speed = f; }
char* Vehicle::get_model() { return model; }
void Vehicle::set_model(const char* s) { strcpy_s(model, 15, s); }

Vehicle Vehicle::operator=(const Vehicle& obj)									//оператор присваивания
{
	this->max_speed = obj.max_speed;
	strcpy_s(this->model, 15, obj.model);

	return *this;
}

bool operator==(const Vehicle& obj1, const Vehicle& obj2)						//оператор сравнения
{
	if (obj1.max_speed != 0.0 && obj1.max_speed != obj2.max_speed)
		return false;
	if (strcmp(obj1.model, "") && strcmp(obj1.model, obj2.model))
		return false;

	return true;
}

istream& operator>>(istream& in, Vehicle& obj)									//оператор ввода
{
	cout << "Введите макс. скорость: ";
	in >> obj.max_speed;
	in.ignore(INT_MAX, '\n');
	cout << "Введите модель: ";
	in.getline(obj.model, 15, '\n');
	return in;
}

ostream& operator<<(ostream& out, const Vehicle& obj)							//оператор вывода
{
	out.precision(5);
	out << "| "
		<< setw(6) << obj.max_speed << " " << setw(14) << "км/ч" << " | "
		<< setw(15) << obj.model << " | ";

	return out;
}

void Vehicle::display()															//шапка таблицы
{
	cout << left << setfill('=') << setw(92) << '=' << endl << setfill(' ') 
		 << setw(21) << "| Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " |";
}

bool Vehicle::chooseParameters()                                                //меню выбора параметров для Vehicle
{
    int select = 0;

    cout << "Критерии поиска: " << endl
         << "1. Максимальная скорость" << endl << "2. Модель" << endl
         << "3. Сброс параметров" << endl << "4. Назад" << endl;

    cout << endl << "Ввод: ";
    cin >> select;
    switch (select)
    {
    case 1:                                     //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                     //модель
    {
        char tmp[15];
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_model(tmp);
        break;
    }
    case 3:                                     //сброс выбранных параметров
    {
        *this = Vehicle();
        break;
    }
    case 4:                                     //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}