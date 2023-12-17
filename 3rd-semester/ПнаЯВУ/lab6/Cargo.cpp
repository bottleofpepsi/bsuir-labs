#include "Cargo.h"

char* Cargo::get_load_type() { return load_type; }								//геттеры-сеттеры
void Cargo::set_load_type(const char* s) { strcpy_s(load_type, STR_LEN, s); }
char* Cargo::get_destination() { return destination; }
void Cargo::set_destination(const char* s) { strcpy_s(destination, STR_LEN, s); }

Cargo Cargo::operator=(const Cargo& obj)										//оператор присваивания
{
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<const Vehicle&>(obj);			//приведение к родительскому типу
	strcpy_s(this->load_type, STR_LEN, obj.load_type);
	strcpy_s(this->destination, STR_LEN, obj.destination);

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

istream& operator>>(istream& in, Cargo& obj)						//оператор ввода
{
    in >> dynamic_cast<Vehicle&>(obj);								//приведение к родительскому типу
    cout << "Введите тип груза: ";
    strcpy_s(obj.load_type, STR_LEN, inputCyrillicString(in, STR_LEN));
    cout << "Введите пункт назначения: ";
    strcpy_s(obj.destination, STR_LEN, inputCyrillicString(in, STR_LEN));
    return in;
}

ostream& operator<<(ostream& out, Cargo& obj)						//оператор вывода
{
    out << dynamic_cast<Vehicle&>(obj)								//приведение к родительскому типу
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
        strcpy_s(tmp, STR_LEN, inputString(cin, STR_LEN));
        this->set_model(tmp);
        break;
    }
    case 3:                                                 //тип груза
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin, STR_LEN));
        this->set_load_type(tmp);
        break;
    }
    case 4:                                                 //пункт назначения
    {
        char tmp[STR_LEN];
        cout << "Значение: ";
        strcpy_s(tmp, STR_LEN, inputCyrillicString(cin, STR_LEN));
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