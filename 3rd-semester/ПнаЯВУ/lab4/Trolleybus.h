#pragma once
#include "Passenger.h"

class Trolleybus : public Passenger
{
private:
	float power_consumption;										//�����������������

public:
	Trolleybus(float sp = 0.0, const char* m = "", int p = 0,								//�����������
		int r = 0, float pc = 0.0) : Passenger(sp, m, p, r), power_consumption(pc) {};
	Trolleybus(const Trolleybus& tr) : Passenger(tr.max_speed, tr.model, tr.passengers,		//����������� �����������
		tr.route), power_consumption(tr.power_consumption) {};
	~Trolleybus() {};																		//����������
		
	float get_power_consumption();									//�������-�������
	void set_power_consumption(float);

	Trolleybus operator=(const Trolleybus&);						//�������� ��������� ������������

	friend bool operator== (const Trolleybus&, const Trolleybus&);	//�������� ��������� �����

	friend istream& operator>>(istream&, Trolleybus&);				//�������� ��������� �����
	friend ostream& operator<<(ostream&, const Trolleybus&);		//�������� ��������� ������
	void display();													//�������� ������� ������ ����� �������
	bool chooseParameters();										//�������� ������� ����� ����������
};