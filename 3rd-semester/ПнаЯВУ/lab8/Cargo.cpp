#include "Cargo.h"

char* Cargo::get_load_type() { return load_type; }						            //геттеры-сеттеры
void Cargo::set_load_type(const char* s) { strcpy_s(load_type, STR_LEN, s); }
char* Cargo::get_destination() { return destination; }
void Cargo::set_destination(const char* s) { strcpy_s(destination, STR_LEN, s); }

Cargo Cargo::operator=(const Cargo& obj)										    //оператор присваивания
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			    //приведение к родительскому типу
	strcpy_s(this->load_type, STR_LEN, obj.load_type);
	strcpy_s(this->destination, STR_LEN, obj.destination);

	return *this;
}

bool Cargo::operator==(const Cargo& other)							                //оператор сравнения
{
	if (!(dynamic_cast<Vehicle&>(*this) == dynamic_cast<const Vehicle&>(other)))
		return false;
	if (strcmp(other.destination, "") && strcmp(this->destination, other.destination))
		return false;
	if (strcmp(other.load_type, "") && strcmp(this->load_type, other.load_type))
		return false;

	return true;
}

bool Cargo::operator>(const Cargo& other)		                                    //оператор больше
{
    if (reinterpret_cast<Vehicle&>(*this) < reinterpret_cast<const Vehicle&>(other))
        return false;
    if (strcmp(other.destination, "") && strcmp(this->destination, other.destination) <= 0)
        return false;
    if (strcmp(other.load_type, "") && strcmp(this->load_type, other.load_type) <=0)
        return false;

    return true;
}

bool Cargo::operator<(const Cargo& other)	                        //оператор меньше
{
    return !(*this > other);
}

bool operator>(const Cargo& obj1, const Cargo& obj2)				//оператор больше
{
    return reinterpret_cast<const Vehicle&>(obj1) > reinterpret_cast<const Vehicle&>(obj2);
}

bool operator<(const Cargo& obj1, const Cargo& obj2)				//оператор меньше
{
    return reinterpret_cast<const Vehicle&>(obj1) < reinterpret_cast<const Vehicle&>(obj2);
}

istream& operator>>(istream& in, Cargo& obj)						//оператор ввода
{
    in >> dynamic_cast<Vehicle&>(obj);								//приведение к родительскому типу
    cout << "Введите тип груза: ";
    strcpy_s(obj.load_type, STR_LEN, inputCyrillicString(in));
    cout << "Введите пункт назначения: ";
    strcpy_s(obj.destination, STR_LEN, inputCyrillicString(in));
    return in;
}

ostream& operator<<(ostream& out, const Cargo& obj)				    //оператор вывода
{
    out << dynamic_cast<const Vehicle&>(obj)				        //приведение к родительскому типу
        << setw(15) << obj.load_type << " | "
        << setw(16) << obj.destination << " | ";

    return out;
}

ifstream& operator>>(ifstream& in, Cargo& obj)					    //оператор чтения из текстового файла
{
    in >> dynamic_cast<Vehicle&>(obj);
    in.get();
    in.getline(obj.load_type, STR_LEN, '|');
    in.get();
    in.getline(obj.destination, STR_LEN, '|');
    return in;
}

ofstream& operator<<(ofstream& out, Cargo& obj)			            //оператор записи в текстовый файл
{
    out << dynamic_cast<Vehicle&>(obj);
    out << " " << obj.load_type << "| " << obj.destination << "|";
    return out;
}

fstream& operator>>(fstream& in, Cargo& obj)					    //оператор чтения из бинарного файла
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Cargo));
    return in;
}

fstream& operator<<(fstream& out, Cargo& obj)				        //оператор записи в бинарный файл
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Cargo));
    return out;
}

int Cargo::display()												//шапка таблицы
{
	Vehicle::display();
	cout << setw(16) << " Тип груза" << " | "
		<< setw(15) << "Пункт назначения" << " |";

    return 92;
}

bool Cargo::chooseParameters()                                      //функция выбора параметров
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Тип груза" << endl << "4. Пункт назначения" << endl
        << "5. Сброс параметров" << endl << "6. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 6);
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
        strcpy_s(tmp, STR_LEN, inputString(cin));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //тип груза
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin));
        this->set_load_type(tmp);
        break;
    }
    case 4:                                                 //пункт назначения
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin));
        this->set_destination(tmp);
        break;
    }
    case 5:                                                 //сброс параметров
    {
        *this = Cargo();
        break;
    }
    case 6:                                                 //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}

int Cargo::chooseSortParameter()							//функция выбора поля сортировки
{
    int select = 0;

    cout << "Сортировка по: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Тип груза" << endl << "4. Пункт назначения" << endl
        << "5. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 5);
    switch (select)
    {
    case 5:                                                 //отмена
    {
        return 0;
    }
    default:
    {
        return select;
    }
    }
}

Cargo Cargo::copyParameter(int n)   	                    //функция копирования поля
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