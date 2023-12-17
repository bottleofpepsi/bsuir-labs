#pragma once
#include "Vehicle.h"

class Passenger : public Vehicle
{
protected:
	int passengers;													//кол-во пассажиров
	int route;														//маршрут

public:
	Passenger(float sp = 0.0, const char* m = "", int p = 0,				//конструктор
		int r = 0) : Vehicle(sp, m), passengers(p), route(r) {};
	Passenger(const Passenger& pas) : Vehicle(pas.max_speed, pas.model),	//конструктор копирования
		passengers(pas.passengers), route(pas.route) {};
	~Passenger() {};														//деструктор

	int get_passengers();											//геттеры-сеттеры
	void set_passengers(int);
	int get_route();
	void set_route(int);

	Passenger operator=(const Passenger&);							//прототип оператора присваивания

	friend bool operator== (const Passenger&, const Passenger&);	//прототип оператора равно

	friend istream& operator>>(istream&, Passenger&);				//прототип оператора ввода
	friend ostream& operator<<(ostream&, Passenger&);				//прототип оператора вывода
	friend ifstream& operator>>(ifstream&, Passenger&);				//прототип оператора чтения из текстового файла
	friend ofstream& operator<<(ofstream&, Passenger&);				//прототип оператора записи в текстовый файл
	friend fstream& operator>>(fstream&, Passenger&);				//прототип оператора чтения из бинарного файла
	friend fstream& operator<<(fstream&, Passenger&);				//прототип оператора записи в бинарный файл

	static int display();											//прототип функции вывода шапки таблицы		
	bool chooseParameters();										//прототип функции ввода параметров
};