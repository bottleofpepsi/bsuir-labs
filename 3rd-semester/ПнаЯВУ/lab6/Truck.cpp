#include "Truck.h"

float Truck::get_load() { return load; }										//геттеры-сеттеры
void Truck::set_load(float f) { load = f; }

Truck Truck::operator=(const Truck& obj)										//оператор присваивания
{
	dynamic_cast<Cargo&>(*this) = dynamic_cast<const Cargo&>(obj);				//приведение к родительскому типу
	this->load = obj.load;

	return *this;
}

bool operator==(const Truck& obj1, const Truck& obj2)							//оператор сравнения
{
	if (!(dynamic_cast<const Cargo&>(obj1) == dynamic_cast<const Cargo&>(obj2)))
		return false;
	if (obj1.load != 0.0 && obj1.load != obj2.load)
		return false;

	return true;
}

istream& operator>>(istream& in, Truck& obj)								//оператор ввода
{
    in >> dynamic_cast<Cargo&>(obj);									    //приведение к родительскому типу
    cout << "Введите вес груза: ";
    obj.load = inputFloat(in);
    return in;
}

ostream& operator<<(ostream& out, Truck& obj)							    //оператор вывода
{
    out << dynamic_cast<Cargo&>(obj) << setprecision(4)					    //приведение к родительскому типу
        << setw(5) << obj.load << " " << setw(3) << "т" << " |" << endl;

    return out;
}

ifstream& operator>>(ifstream& in, Truck& obj)					    //оператор чтения из текстового файла
{
    in >> dynamic_cast<Cargo&>(obj);
    in >> obj.load;
    return in;
}

ofstream& operator<<(ofstream& out, Truck& obj)			            //оператор записи в текстовый файл
{
    out << dynamic_cast<Cargo&>(obj);
    out << " " << obj.load << endl;
    return out;
}

fstream& operator>>(fstream& in, Truck& obj)					    //оператор чтения из бинарного файла
{
    in.read(reinterpret_cast<char*>(&obj), sizeof(Truck));
    return in;
}

fstream& operator<<(fstream& out, Truck& obj)				        //оператор записи в бинарный файл
{
    out.write(reinterpret_cast<char*>(&obj), sizeof(Truck));
    return out;
}

int Truck::display()											    //шапка таблицы
{
	Cargo::display();
	cout << setw(9) << " Вес груза" << " |" << endl
		<< setfill('=') << setw(92) << '=' << endl << setfill(' ');

    return 92;
}

bool Truck::chooseParameters()                              //меню ввода параметров для Truck
{
    int select = 0;

    cout << "Критерии поиска: " << endl
        << "1. Максимальная скорость" << endl << "2. Модель" << endl
        << "3. Тип груза" << endl << "4. Пункт назначения" << endl
        << "5. Вес груза" << endl << "6. Сброс параметров" << endl << "7. Назад" << endl;

    cout << endl << "Ввод: ";
    select = inputInt(cin, 1, 7);
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
    case 5:                                                 //вес груза
    {
        float tmp = 0;
        cout << "Значение: ";
        tmp = inputFloat(cin, 0);
        this->set_load(tmp);
        break;
    }
    case 6:                                                 //сброс параметров
    {
        *this = Truck();
        break;
    }
    case 7:                                                 //выбор параметров окончен
    {
        return true;
    }
    }

    return false;
}