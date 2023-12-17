#pragma once
#include "Exception.h"
#include "Ring.cpp"

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

template <typename T>
bool emptyContainer(Iterator<T> begin)
{
	try
	{
		if (begin == Iterator<T>())
			throw IteratorExeption("������ ���������", "�������� ������, ����� �������� � ����");
		return false;
	}
	catch (IteratorExeption obj)
	{
		obj.printException();									//����� ������
		system("pause");
	}

	return true;
}