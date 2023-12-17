#pragma once
#include "libs.h"
#include "InputException.h"

class Vehicle
{
protected:
	float max_speed;												//��������
	char model[STR_LEN];											//�������� ������

public:
	Vehicle(float sp = 0.0, const char* m = "") : max_speed(sp)		//�����������
	{
		strcpy_s(model, STR_LEN, m);
	}
	Vehicle(const Vehicle& vh) : max_speed(vh.max_speed)			//����������� �����������
	{
		strcpy_s(this->model, STR_LEN, vh.model);
	}
	~Vehicle() {}													//����������

	float get_max_speed();											//�������-�������
	void set_max_speed(float);
	char* get_model();
	void set_model(const char*);

	Vehicle operator=(const Vehicle&);								//�������� ��������� ������������

	friend bool operator== (const Vehicle&, const Vehicle&);		//�������� ��������� �����

	friend istream& operator>>(istream&, Vehicle&);					//�������� ��������� �����
	friend ostream& operator<<(ostream&, Vehicle&);					//�������� ��������� ������
	friend ifstream& operator>>(ifstream&, Vehicle&);				//�������� ��������� ������ �� ���������� �����
	friend ofstream& operator<<(ofstream&, Vehicle&);				//�������� ��������� ������ � ��������� ����
	friend fstream& operator>>(fstream&, Vehicle&);					//�������� ��������� ������ �� ��������� �����
	friend fstream& operator<<(fstream&, Vehicle&);					//�������� ��������� ������ � �������� ����

	static int display();											//�������� ������� ������ ����� �������		
	bool chooseParameters();										//�������� ������� ����� ����������
};