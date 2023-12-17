#pragma once
#include "Passenger.h"

class Trolleybus : public Passenger
{
private:
	float power_consumption;										//энергопотребление

public:
	Trolleybus(float sp = 0.0, const char* m = "", int p = 0,								//конструктор
		int r = 0, float pc = 0.0) : Passenger(sp, m, p, r), power_consumption(pc) {};
	Trolleybus(const Trolleybus& tr) : Passenger(tr.max_speed, tr.model, tr.passengers,		//конструктор копирования
		tr.route), power_consumption(tr.power_consumption) {};
	~Trolleybus() {};												//деструктор

	float get_power_consumption();
	void set_power_consumption(float);

	Trolleybus operator=(const Trolleybus&);						//прототип оператора присваивания

	friend istream& operator>>(istream&, Trolleybus&);				//прототип оператора ввода
	friend ostream& operator<<(ostream&, const Trolleybus&);		//прототип оператора вывода
	void display();
};