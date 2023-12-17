#pragma once
#include "Cargo.h"

class Truck : public Cargo
{
private:
	float load;														//����������������

public:
	Truck(float sp = 0.0, const char* m = "", const char* lt = "",				//�����������
		const char* d = "", float l = 0.0) : Cargo(sp, m, lt, d), load(l) {};

	Truck(const Truck& tr) : Cargo(tr.max_speed, tr.model, tr.load_type,		//����������� �����������
		tr.destination), load(tr.load) {};

	~Truck() {};													//����������

	float get_load();
	void set_load(float);

	Truck operator=(const Truck&);									//�������� ��������� ������������

	friend istream& operator>>(istream&, Truck&);					//�������� ��������� �����
	friend ostream& operator<<(ostream&, const Truck&);				//�������� ��������� ������
	void display();
};