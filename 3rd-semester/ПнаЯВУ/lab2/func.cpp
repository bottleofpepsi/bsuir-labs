#include "String.h"

String& String::operator=(String&& obj) noexcept				//перемещающий оператор присваивания
{
	if (&obj == this)											//проверка самокопирования
		return *this;

	delete[] this->s;											//очистка старой памяти

	this->s = obj.s;											//перемещение ресурсов
	obj.s = nullptr;

	return *this;
}

String& String::operator=(const char* tmp) noexcept				//перемещающий оператор присваивания
{
	if (!strcmp(tmp,this->s))									//проверка самокопирования
		return *this;

	delete[] this->s;											//очистка старой памяти

	this->s = new char[strlen(tmp) + 1];						//присваивание нового значения
	strcpy_s(this->s, strlen(tmp) + 1, tmp);					

	return *this;
}

//String String::operator=(const String& tmp)					//копирующий оператор присваивания
//{
//	if (tmp == *this)											//проверка самокопирования
//		return *this;
//
//	delete[] this->s;											//присваивание нового значения
//	this->s = new char[strlen(tmp.s) + 1];						
//	strcpy_s(this->s, strlen(tmp.s) + 1, tmp.s);				
//
//	return *this;
//}

istream& operator>>(istream& in, String& obj)					//оператор ввода
{
	char tmp[80];
	in.getline(tmp,80,'\n');
	obj = tmp;
	return in;
}

ostream& operator<<(ostream& out, const String& obj)			//оператор вывода
{
	return out << obj.s;
}

String operator+(const String& obj1, const String& obj2)		//оператор сложения двух объектов
{
	int len = strlen(obj1.s) + strlen(obj2.s);
	char* tmp = new char[len + 1];								//буферная строка

	strcpy_s(tmp, strlen(obj1.s) + 1, obj1.s);					//объединение двух строк в новую
	strcat_s(tmp, len + 1, obj2.s);

	return String(tmp);
}

String operator+(char* str, const String& obj)					//оператор сложения строки и объекта
{
	int len = strlen(str) + strlen(obj.s);
	char* tmp = new char[len + 1];								//буферная строка

	strcpy_s(tmp, strlen(str) + 1, str);						//объединение двух строк в новую
	strcat_s(tmp, len + 1, obj.s);

	return String(tmp);
}

String operator+(const String& obj, char* str)					//оператор сложения объекта и строки
{
	int len = strlen(obj.s) + strlen(str);
	char* tmp = new char[len + 1];								//буферная строка

	strcpy_s(tmp, strlen(obj.s) + 1, obj.s);					//объединение двух строк в новую
	strcat_s(tmp, len + 1, str);

	return String(tmp);
}

String& String::operator+=(const String& obj)					//оператор сложения с присваиванием
{
	return *this = *this + obj.s;
}

String& String::operator+=(const char* str)						//оператор сложения с присваиванием
{
	return *this = *this + str;
}

bool operator== (const String& obj1, const String& obj2)		//оператор равно для двух объектов
{
	if (!strcmp(obj1.s, obj2.s))
		return true;
	return false;
}

bool operator== (const String& obj, const char* str)			//оператор равно для объекта и строки
{
	if (!strcmp(obj.s, str))
		return true;
	return false;
}
bool operator== (const char* str, const String& obj)			//оператор равно для строки и объекта
{
	if (!strcmp(str, obj.s))
		return true;
	return false;
}

bool operator!= (const String& obj1, const String& obj2)		//оператор неравно для двух объектов
{
	if (!strcmp(obj1.s, obj2.s))
		return false;
	return true;
}

bool operator!= (const String& obj, const char* str)			//оператор неравно для объекта и строки
{
	if (!strcmp(obj.s, str))
		return false;
	return true;
}
bool operator!= (const char* str, const String& obj)			//оператор неравно для строки и объекта
{
	if (!strcmp(str, obj.s))
		return false;
	return true;
}

char& String::operator[] (int k)								//оператор индексации
{
	return this->s[k];
}

String String::operator()(int start, int n)						//метож выделения подстроки
{
	char tmp[80];

	if (start > (int)strlen(this->s))							//если начальный символ находится вне строки						
		return String("");

	char* st = this->s;											//установка указателя в начало подстроки
	st += start - 1;

	strcpy_s(tmp, 80, st);										//копирование подстроки
	tmp[n] = '\0';

	return String(tmp);
}