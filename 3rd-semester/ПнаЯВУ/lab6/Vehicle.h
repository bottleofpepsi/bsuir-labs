#pragma once
#include "libs.h"
#include "InputException.h"

class Vehicle
{
protected:
	float max_speed;												//скорость
	char model[STR_LEN];											//название модели

public:
	Vehicle(float sp = 0.0, const char* m = "") : max_speed(sp)		//конструктор
	{
		strcpy_s(model, STR_LEN, m);
	}
	Vehicle(const Vehicle& vh) : max_speed(vh.max_speed)			//конструктор копирования
	{
		strcpy_s(this->model, STR_LEN, vh.model);
	}
	~Vehicle() {}													//деструктор

	float get_max_speed();											//геттеры-сеттеры
	void set_max_speed(float);
	char* get_model();
	void set_model(const char*);

	Vehicle operator=(const Vehicle&);								//прототип оператора присваивания

	friend bool operator== (const Vehicle&, const Vehicle&);		//прототип оператора равно

	friend istream& operator>>(istream&, Vehicle&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, Vehicle&);					//прототип оператора вывода
	friend ifstream& operator>>(ifstream&, Vehicle&);				//прототип оператора чтения из текстового файла
	friend ofstream& operator<<(ofstream&, Vehicle&);				//прототип оператора записи в текстовый файл
	friend fstream& operator>>(fstream&, Vehicle&);					//прототип оператора чтения из бинарного файла
	friend fstream& operator<<(fstream&, Vehicle&);					//прототип оператора записи в бинарный файл

	static int display();											//прототип функции вывода шапки таблицы		
	bool chooseParameters();										//прототип функции ввода параметров
};