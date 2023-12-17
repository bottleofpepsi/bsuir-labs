#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class String
{
private:
	char* s;

public:
	String(const char* input = "")									//конструктор
	{
		s = new char[strlen(input) + 1];
		strcpy_s(s, strlen(input) + 1, input);
	}
	//String(const String& input)									//конструктор копирования
	//{
	//	this->s = new char[strlen(input.s) + 1];
	//	strcpy_s(this->s, strlen(input.s) + 1, input.s);
	//}
	String(String&& str1) noexcept : s(str1.s)						//конструктор перемещения
	{
		str1.s = nullptr;
	}
	~String()														//деструктор
	{
		delete[] s;
	}

	//String operator=(const String& ob);							//прототипы операторов присвиавания
	String& operator=(String&&) noexcept;
	String& operator=(const char* tmp) noexcept;

	friend istream& operator>>(istream&, String&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, const String&);			//прототип оператора вывода

	friend String operator+(const String&, const String&);			//прототипы операторов сложения
	friend String operator+(char*, const String&);
	friend String operator+(const String&, char*);

	String& operator+=(const String&);								//прототипы операторов сложения с присваиванием
	String& operator+=(const char*);

	friend bool operator== (const String&, const String&);			//прототипы операторов равно
	friend bool operator== (const String&, const char*);
	friend bool operator== (const char*, const String&);

	friend bool operator!= (const String&, const String&);			//прототипы операторов неравно
	friend bool operator!= (const String&, const char*);
	friend bool operator!= (const char*, const String&);

	char& operator[] (int);											//прототип оператора индексации
	String operator()(int, int);									//прототип метода выделения подстроки
};