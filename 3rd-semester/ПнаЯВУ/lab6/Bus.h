#pragma once
#include "Passenger.h"

class Bus : public Passenger
{
private:
	float fuel;														//������ ���������� ����

public:
	Bus(float sp = 0.0, const char* m = "", int p = 0,						//�����������
		int r = 0, float f = 0.0) : Passenger(sp, m, p, r), fuel(f) {};
	Bus(const Bus& b) : Passenger(b.max_speed, b.model, b.passengers,		//����������� �����������
		b.route), fuel(b.fuel) {};
	~Bus() {};																//����������

	float get_fuel();												//�������-�������
	void set_fuel(float);

	Bus operator=(const Bus&);										//�������� ��������� ������������

	friend bool operator== (const Bus&, const Bus&);				//�������� ��������� �����

	friend istream& operator>>(istream&, Bus&);						//�������� ��������� �����
	friend ostream& operator<<(ostream&, Bus&);						//�������� ��������� ������
	friend ifstream& operator>>(ifstream&, Bus&);					//�������� ��������� ������ �� ���������� �����
	friend ofstream& operator<<(ofstream&, Bus&);					//�������� ��������� ������ � ��������� ����
	friend fstream& operator>>(fstream&, Bus&);						//�������� ��������� ������ �� ��������� �����
	friend fstream& operator<<(fstream&, Bus&);						//�������� ��������� ������ � �������� ����

	static int display();											//�������� ������� ������ ����� �������		
	bool chooseParameters();										//�������� ������� ����� ����������
};