#pragma once
#include "Vehicle.h"

class Cargo : public Vehicle
{
protected:
	char load_type[STR_LEN];										//тип груза
	char destination[STR_LEN];										//пункт назначения

public:
	Cargo(float sp = 0.0, const char* m = "", const char* lt = "",	//конструктор
		const char* d = "") : Vehicle(sp, m)
	{
		strcpy_s(load_type, STR_LEN, lt);
		strcpy_s(destination, STR_LEN, d);
	}
	Cargo(const Cargo& c) : Vehicle(c.max_speed, c.model)			//конструктор копирования
	{
		strcpy_s(this->load_type, STR_LEN, c.load_type);
		strcpy_s(this->destination, STR_LEN, c.destination);
	}
	~Cargo() {};													//деструктор

	char* get_load_type();											//геттеры-сеттеры
	void set_load_type(const char*);
	char* get_destination();
	void set_destination(const char*);

	Cargo operator=(const Cargo&);									//прототип оператора присваивания

	friend bool operator== (const Cargo&, const Cargo&);			//прототип оператора равно

	friend istream& operator>>(istream&, Cargo&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, Cargo&);					//прототип оператора вывода
	friend ifstream& operator>>(ifstream&, Cargo&);					//прототип оператора чтения из текстового файла
	friend ofstream& operator<<(ofstream&, Cargo&);					//прототип оператора записи в текстовый файл
	friend fstream& operator>>(fstream&, Cargo&);					//прототип оператора чтения из бинарного файла
	friend fstream& operator<<(fstream&, Cargo&);					//прототип оператора записи в бинарный файл

	static int display();											//прототип функции вывода шапки таблицы		
	bool chooseParameters();										//прототип функции выбора параметров
};