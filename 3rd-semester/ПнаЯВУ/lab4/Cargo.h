#pragma once
#include "Vehicle.h"

class Cargo : public Vehicle
{
protected:
	char load_type[15];												//��� �����
	char destination[15];											//����� ����������

public:
	Cargo(float sp = 0.0, const char* m = "", const char* lt = "",	//�����������
		const char* d = "") : Vehicle(sp, m)
	{
		strcpy_s(load_type, 15, lt);
		strcpy_s(destination, 15, d);
	}
	Cargo(const Cargo& c) : Vehicle(c.max_speed, c.model)			//����������� �����������
	{
		strcpy_s(this->load_type, 15, c.load_type);
		strcpy_s(this->destination, 15, c.destination);
	}
	~Cargo() {};													//����������

	char* get_load_type();											//�������-�������
	void set_load_type(const char*);
	char* get_destination();
	void set_destination(const char*);

	Cargo operator=(const Cargo&);									//�������� ��������� ������������

	friend bool operator== (const Cargo&, const Cargo&);			//�������� ��������� �����

	friend istream& operator>>(istream&, Cargo&);					//�������� ��������� �����
	friend ostream& operator<<(ostream&, const Cargo&);				//�������� ��������� ������
	void display();													//�������� ������� ������ �����
	bool chooseParameters();										//�������� ������� ������ ����������
};