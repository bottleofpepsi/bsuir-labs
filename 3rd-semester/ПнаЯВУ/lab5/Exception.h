#pragma once
#include "libs.h"
#include <cstring>
#include <string>
#include <Windows.h>

class Exception															//ошибка
{
protected:
	string errorMessage;												//сообщение

public:
	Exception(const string errMes = "") : errorMessage(errMes) {}		//конструктор
	Exception(const Exception& exp) : errorMessage(exp.errorMessage) {}	//конструктор копирования
	~Exception() {}														//деструктор

	virtual void printException();										//прототип функции вывода ошибки
};