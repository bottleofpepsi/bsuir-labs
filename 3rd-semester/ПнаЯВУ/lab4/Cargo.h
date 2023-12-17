#pragma once
#include "Vehicle.h"

class Cargo : public Vehicle
{
protected:
	char load_type[15];												//тип груза
	char destination[15];											//пункт назначения

public:
	Cargo(float sp = 0.0, const char* m = "", const char* lt = "",	//конструктор
		const char* d = "") : Vehicle(sp, m)
	{
		strcpy_s(load_type, 15, lt);
		strcpy_s(destination, 15, d);
	}
	Cargo(const Cargo& c) : Vehicle(c.max_speed, c.model)			//конструктор копирования
	{
		strcpy_s(this->load_type, 15, c.load_type);
		strcpy_s(this->destination, 15, c.destination);
	}
	~Cargo() {};													//деструктор

	char* get_load_type();											//геттеры-сеттеры
	void set_load_type(const char*);
	char* get_destination();
	void set_destination(const char*);

	Cargo operator=(const Cargo&);									//прототип оператора присваивания

	friend bool operator== (const Cargo&, const Cargo&);			//прототип оператора равно

	friend istream& operator>>(istream&, Cargo&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, const Cargo&);				//прототип оператора вывода
	void display();													//прототип функции вывода шапки
	bool chooseParameters();										//прототип функции выбора параметров
};