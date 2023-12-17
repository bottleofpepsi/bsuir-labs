#pragma once
#include "libs.h"
#include <cstring>
#include <string>
#include <Windows.h>

class Exception															//������
{
protected:
	string errorMessage;												//���������

public:
	Exception(const string errMes = "") : errorMessage(errMes) {}		//�����������
	Exception(const Exception& exp) : errorMessage(exp.errorMessage) {}	//����������� �����������
	~Exception() {}														//����������

	virtual void printException();										//�������� ������� ������ ������
};