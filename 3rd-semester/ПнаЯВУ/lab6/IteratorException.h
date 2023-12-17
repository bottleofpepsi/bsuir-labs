#pragma once
#include "Exception.h"

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