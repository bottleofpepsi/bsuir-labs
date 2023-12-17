#pragma once
#include "Passenger.h"

class Bus : public Passenger
{
private:
	float fuel;														//размер топливного бака

public:
	Bus(float sp = 0.0, const char* m = "", int p = 0,						//конструктор
		int r = 0, float f = 0.0) : Passenger(sp, m, p, r), fuel(f) {};
	Bus(const Bus& b) : Passenger(b.max_speed, b.model, b.passengers,		//конструктор копирования
		b.route), fuel(b.fuel) {};
	~Bus() {};																//деструктор

	float get_fuel();												//геттеры-сеттеры
	void set_fuel(float);

	Bus operator=(const Bus&);										//прототип оператора присваивания

	friend bool operator== (const Bus&, const Bus&);				//прототип оператора равно

	friend istream& operator>>(istream&, Bus&);						//прототип оператора ввода
	friend ostream& operator<<(ostream&, Bus&);						//прототип оператора вывода
	friend ifstream& operator>>(ifstream&, Bus&);					//прототип оператора чтения из текстового файла
	friend ofstream& operator<<(ofstream&, Bus&);					//прототип оператора записи в текстовый файл
	friend fstream& operator>>(fstream&, Bus&);						//прототип оператора чтения из бинарного файла
	friend fstream& operator<<(fstream&, Bus&);						//прототип оператора записи в бинарный файл

	static int display();											//прототип функции вывода шапки таблицы		
	bool chooseParameters();										//прототип функции ввода параметров
};