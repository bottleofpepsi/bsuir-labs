#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
	float max_speed;												//��������
	char model[15];													//�������� ������

public:
	Vehicle(float sp = 0.0, const char* m = "") : max_speed(sp)		//�����������
	{
		strcpy_s(model, 15, m);
	}
	Vehicle(const Vehicle& vh) : max_speed(vh.max_speed)			//����������� �����������
	{
		strcpy_s(this->model, 15, vh.model);
	}
	~Vehicle() {}													//����������

	float get_max_speed();
	void set_max_speed(float);
	char* get_model();
	void set_model(const char*);

	Vehicle operator=(const Vehicle&);								//�������� ��������� ������������

	friend istream& operator>>(istream&, Vehicle&);					//�������� ��������� �����
	friend ostream& operator<<(ostream&, const Vehicle&);			//�������� ��������� ������
	void display();
};