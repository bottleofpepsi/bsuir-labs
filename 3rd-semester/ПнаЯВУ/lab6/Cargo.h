#pragma once
#include "Vehicle.h"

class Cargo : public Vehicle
{
protected:
	char load_type[STR_LEN];										//��� �����
	char destination[STR_LEN];										//����� ����������

public:
	Cargo(float sp = 0.0, const char* m = "", const char* lt = "",	//�����������
		const char* d = "") : Vehicle(sp, m)
	{
		strcpy_s(load_type, STR_LEN, lt);
		strcpy_s(destination, STR_LEN, d);
	}
	Cargo(const Cargo& c) : Vehicle(c.max_speed, c.model)			//����������� �����������
	{
		strcpy_s(this->load_type, STR_LEN, c.load_type);
		strcpy_s(this->destination, STR_LEN, c.destination);
	}
	~Cargo() {};													//����������

	char* get_load_type();											//�������-�������
	void set_load_type(const char*);
	char* get_destination();
	void set_destination(const char*);

	Cargo operator=(const Cargo&);									//�������� ��������� ������������

	friend bool operator== (const Cargo&, const Cargo&);			//�������� ��������� �����

	friend istream& operator>>(istream&, Cargo&);					//�������� ��������� �����
	friend ostream& operator<<(ostream&, Cargo&);					//�������� ��������� ������
	friend ifstream& operator>>(ifstream&, Cargo&);					//�������� ��������� ������ �� ���������� �����
	friend ofstream& operator<<(ofstream&, Cargo&);					//�������� ��������� ������ � ��������� ����
	friend fstream& operator>>(fstream&, Cargo&);					//�������� ��������� ������ �� ��������� �����
	friend fstream& operator<<(fstream&, Cargo&);					//�������� ��������� ������ � �������� ����

	static int display();											//�������� ������� ������ ����� �������		
	bool chooseParameters();										//�������� ������� ������ ����������
};