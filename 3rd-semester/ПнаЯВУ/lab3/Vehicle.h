#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
	float max_speed;												//скорость
	char model[15];													//название модели

public:
	Vehicle(float sp = 0.0, const char* m = "") : max_speed(sp)		//конструктор
	{
		strcpy_s(model, 15, m);
	}
	Vehicle(const Vehicle& vh) : max_speed(vh.max_speed)			//конструктор копирования
	{
		strcpy_s(this->model, 15, vh.model);
	}
	~Vehicle() {}													//деструктор

	float get_max_speed();
	void set_max_speed(float);
	char* get_model();
	void set_model(const char*);

	Vehicle operator=(const Vehicle&);								//прототип оператора присваивания

	friend istream& operator>>(istream&, Vehicle&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, const Vehicle&);			//прототип оператора вывода
	void display();
};