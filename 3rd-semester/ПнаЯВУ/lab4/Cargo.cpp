#include "Cargo.h"

char* Cargo::get_load_type() { return load_type; }								//геттеры-сеттеры
void Cargo::set_load_type(const char* s) { strcpy_s(load_type, 15, s); }
char* Cargo::get_destination() { return destination; }
void Cargo::set_destination(const char* s) { strcpy_s(destination, 15, s); }

Cargo Cargo::operator=(const Cargo& obj)										//оператор присваивания
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			//приведение к родительскому типу
	strcpy_s(this->load_type, 15, obj.load_type);
	strcpy_s(this->destination, 15, obj.destination);

	return *this;
}

bool operator==(const Cargo& obj1, const Cargo& obj2)							//оператор сравнения
{
	if (!(dynamic_cast<const Vehicle&>(obj1) == dynamic_cast<const Vehicle&>(obj2)))
		return false;
	if (strcmp(obj1.destination, "") && strcmp(obj1.destination, obj2.destination))
		return false;
	if (strcmp(obj1.load_type, "") && strcmp(obj1.load_type, obj2.load_type))
		return false;

	return true;
}

istream& operator>>(istream& in, Cargo& obj)					//оператор ввода
{
	in >> dynamic_cast<Vehicle&>(obj);							//приведение к родительскому типу
	cout << "Введите тип груза: ";
	in.getline(obj.load_type, 15, '\n');
	cout << "Введите пункт назначения: ";
	in.getline(obj.destination, 15, '\n');
	return in;
}

ostream& operator<<(ostream& out, const Cargo& obj)				//оператор вывода
{
	out << dynamic_cast<const Vehicle&>(obj)					//приведение к родительскому типу
		<< setw(15) << obj.load_type << " | "
		<< setw(16) << obj.destination << " | ";

	return out;
}

void Cargo::display()											//шапка таблицы
{
	Vehicle::display();
	cout << setw(16) << " Тип груза" << " | "
		<< setw(15) << "Пункт назначения" << " |";
}

bool Cargo::chooseParameters()                                  //функция выбора параметров
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Тип груза" << endl << "4. Пункт назначения" << endl
        << "5. Сброс параметров" << endl << "6. Назад" << endl;

    cout << endl << "Ввод: ";
    cin >> select;
    switch (select)
    {
    case 1:                                         //макс. скорость
    {
        float tmp = 0;
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin >> tmp;
        this->set_max_speed(tmp);
        break;
    }
    case 2:                                         //модель
    {
        char tmp[15];
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_model(tmp);
        break;
    }
    case 3:                                         //тип груза
    {
        char tmp[15];
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_load_type(tmp);
        break;
    }
    case 4:                                         //пункт назначения
    {
        char tmp[15];
        cout << "Значение: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tmp, 15, '\n');
        this->set_destination(tmp);
        break;
    }
    case 5:                                         //сброс параметров
    {
        *this = Cargo();
        break;
    }
    case 6:                                         //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}
