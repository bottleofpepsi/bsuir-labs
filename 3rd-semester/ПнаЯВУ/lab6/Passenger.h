#pragma once
#include "Vehicle.h"

class Passenger : public Vehicle
{
protected:
	int passengers;													//���-�� ����������
	int route;														//�������

public:
	Passenger(float sp = 0.0, const char* m = "", int p = 0,				//�����������
		int r = 0) : Vehicle(sp, m), passengers(p), route(r) {};
	Passenger(const Passenger& pas) : Vehicle(pas.max_speed, pas.model),	//����������� �����������
		passengers(pas.passengers), route(pas.route) {};
	~Passenger() {};														//����������

	int get_passengers();											//�������-�������
	void set_passengers(int);
	int get_route();
	void set_route(int);

	Passenger operator=(const Passenger&);							//�������� ��������� ������������

	friend bool operator== (const Passenger&, const Passenger&);	//�������� ��������� �����

	friend istream& operator>>(istream&, Passenger&);				//�������� ��������� �����
	friend ostream& operator<<(ostream&, Passenger&);				//�������� ��������� ������
	friend ifstream& operator>>(ifstream&, Passenger&);				//�������� ��������� ������ �� ���������� �����
	friend ofstream& operator<<(ofstream&, Passenger&);				//�������� ��������� ������ � ��������� ����
	friend fstream& operator>>(fstream&, Passenger&);				//�������� ��������� ������ �� ��������� �����
	friend fstream& operator<<(fstream&, Passenger&);				//�������� ��������� ������ � �������� ����

	static int display();											//�������� ������� ������ ����� �������		
	bool chooseParameters();										//�������� ������� ����� ����������
};