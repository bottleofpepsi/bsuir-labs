#pragma once
#include "Exception.h"

class IteratorExeption : public Exception						//������ ���������
{
private:
	string iteratorMessage;										//���������

public:
	IteratorExeption(const string errMes = "", const string itrMes = "") :						//�����������
		Exception(errMes), iteratorMessage(itrMes) {}

	IteratorExeption(const IteratorExeption& exp) :												//����������� �����������
		Exception(dynamic_cast<const Exception&>(exp)), iteratorMessage(exp.iteratorMessage) {}

	~IteratorExeption() {}																		//����������

	void printException() override;								//�������� ������� ������ ������ �� �����
};	