#pragma once
#include "Cargo.h"

class Truck : public Cargo
{
private:
	float load;														//грузоподъёмность

public:
	Truck(float sp = 0.0, const char* m = "", const char* lt = "",				//конструктор
		const char* d = "", float l = 0.0) : Cargo(sp, m, lt, d), load(l) {};

	Truck(const Truck& tr) : Cargo(tr.max_speed, tr.model, tr.load_type,		//конструктор копирования
		tr.destination), load(tr.load) {};

	~Truck() {};													//деструктор

	float get_load();
	void set_load(float);

	Truck operator=(const Truck&);									//прототип оператора присваивания

	friend istream& operator>>(istream&, Truck&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, const Truck&);				//прототип оператора вывода
	void display();
};