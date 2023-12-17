#include "Vehicle.h"

float Vehicle::get_max_speed() { return max_speed; }							//геттеры-сеттеры
void Vehicle::set_max_speed(float f) { max_speed = f; }
char* Vehicle::get_model() { return model; }
void Vehicle::set_model(const char* s) { strcpy_s(model, 15, s); }

Vehicle Vehicle::operator=(const Vehicle& obj)									//оператор присваивания
{
	this->max_speed = obj.max_speed;
	strcpy_s(this->model, STR_LEN, obj.model);

	return *this;
}

bool Vehicle::operator==(const Vehicle& other)						            //оператор сравнения
{
    if (other.max_speed != 0.0 && this->max_speed != other.max_speed)
        return false;
    if (strcmp(other.model, "") && strcmp(this->model, other.model))
        return false;

    return true;
}

bool Vehicle::operator>(const Vehicle& other)		                            //оператор больше
{
    if (other.max_speed != 0.0 && this->max_speed < other.max_speed)
        return false;
    if (strcmp(other.model, "") && strcmp(this->model, other.model) <= 0)
        return false;

    return true;
}
bool Vehicle::operator<(const Vehicle& other)						            //оператор меньше
{
    return !(*this > other);
}

istream& operator>>(istream& in, Vehicle& obj)									//оператор ввода
{
    cout << "Введите макс. скорость: ";
    obj.max_speed = inputFloat(in, 0);
    cout << "Введите модель: ";
    strcpy_s(obj.model, STR_LEN, inputString(in, STR_LEN));
    return in;
}

ostream& operator<<(ostream& out, Vehicle& obj)							        //оператор вывода
{
    out.precision(5);
    out << "| "
        << setw(6) << obj.max_speed << " " << setw(14) << "км/ч" << " | "
        << setw(15) << obj.model << " | ";
    return out;
}

ifstream& operator>>(ifstream& in, Vehicle& obj)				                //оператор чтения из текстового файла
{
    in >> obj.max_speed;
    in.get();
    in.getline(obj.model, STR_LEN, '|');
    return in;
}

ofstream& operator<<(ofstream& out, Vehicle& obj)			                    //оператор записи в текстовый файл
{
    out << obj.max_speed << " " << obj.model << "|";
    return out;
}

fstream& operator>>(fstream& in, Vehicle& obj)					                //оператор чтения из бинарного файла
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Vehicle));
    return in;
}

fstream& operator<<(fstream& out, Vehicle& obj)			                        //оператор записи в бинарный файл
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Vehicle));
    return out;
}

int Vehicle::display()															//шапка таблицы
{
	cout << left << setfill('=') << setw(92) << '=' << endl << setfill(' ') 
		 << setw(21) << "| Максимальная скорость" << " | "
		<< setw(15) << "Модель" << " |";

    return 92;
}

bool Vehicle::chooseParameters()                            //меню выбора параметров для Vehicle
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Сброс параметров" << endl << "4. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 4);
    switch (select)
    {
    case 1:                                                 //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                                 //модель
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputString(cin, STR_LEN));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //сброс выбранных параметров
    {
        *this = Vehicle();
        break;
    }
    case 4:                                                 //выбор параметров окончен
    {
        return true;                                                            
    }
    }

    return false;
}

int Vehicle::chooseSortParameter()							//функция выбора поля сортировки
{
    int select = 0;

    cout << "Сортировка по: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 3);
    switch (select)
    {
    case 3:                                                 //отмена
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Vehicle Vehicle::copyParameter(int n)   	                //функция копирования поля
{
    Vehicle result;

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
    }

    return result;
}
