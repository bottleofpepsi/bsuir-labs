#pragma once
#include "Cargo.h"

class Truck : public Cargo
{
private:
	float load;														//грузоподъёмность

public:
	Truck(float sp = 0.0, const char* m = "", const char* lt = "",				//конструктор
		const char* d = "", float l = 0.0) : Cargo(sp, m, lt, d), load(l) {};

	Truck(const Truck& tr) : Cargo(dynamic_cast<const Cargo&>(tr)),				//конструктор копирования
			load(tr.load) {};

	~Truck() {};																//деструктор

	float get_load() const;											//геттеры-сеттеры
	void set_load(float);

	Truck operator=(const Truck&);									//прототип оператора присваивания

	bool operator==(const Truck&);									//прототип оператора равно
	bool operator>(const Truck&);									//прототип оператора больше
	bool operator<(const Truck&);									//прототип оператора меньше

	friend bool operator>(const Truck&, const Truck&);				//прототип оператора больше
	friend bool operator<(const Truck&, const Truck&);				//прототип оператора меньше

	friend istream& operator>>(istream&, Truck&);					//прототип оператора ввода
	friend ostream& operator<<(ostream&, const Truck&);				//прототип оператора вывода
	friend ifstream& operator>>(ifstream&, Truck&);					//прототип оператора чтения из текстового файла
	friend ofstream& operator<<(ofstream&, Truck&);					//прототип оператора записи в текстовый файл
	friend fstream& operator>>(fstream&, Truck&);					//прототип оператора чтения из бинарного файла
	friend fstream& operator<<(fstream&, Truck&);					//прототип оператора записи в бинарный файл

	static int display();											//прототип функции вывода шапки
	bool chooseParameters();										//прототип функции ввода параметров
	Truck copyParameter(int);										//прототип функции копирования поля
	static int chooseSortParameter();								//прототип функции выбора поля сортировки
};