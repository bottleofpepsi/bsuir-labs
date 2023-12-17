#pragma once
#include "Exception.h"
#include "Ring.cpp"

class IteratorExeption : public Exception						//ошибка итератора
{
private:
	string iteratorMessage;										//сообщение

public:
	IteratorExeption(const string errMes = "", const string itrMes = "") :						//конструктор
		Exception(errMes), iteratorMessage(itrMes) {}

	IteratorExeption(const IteratorExeption& exp) :												//конструктор копирования
		Exception(dynamic_cast<const Exception&>(exp)), iteratorMessage(exp.iteratorMessage) {}

	~IteratorExeption() {}																		//деструктор

	void printException() override;								//прототип функции вывода ошибки на экран
};	

template <typename T>
bool emptyContainer(Iterator<T> begin)
{
	try
	{
		if (begin == Iterator<T>())
			throw IteratorExeption("Ошибка итератора", "Добавьте данные, чтобы работать с ними");
		return false;
	}
	catch (IteratorExeption obj)
	{
		obj.printException();									//вывод ошибки
		system("pause");
	}

	return true;
}