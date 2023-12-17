#pragma once
#include "Exception.h"

class InputException : public Exception									//ошибка ввода
{
private:
	string inputMessage;												//сообщение

public:
	InputException(const string errMes = "", const string inpMes = "") :					//конструктор
		Exception(errMes), inputMessage(inpMes) {}
	InputException(const InputException& exp) :												//конструктор копирования
		Exception(dynamic_cast<const Exception&>(exp)), inputMessage(exp.inputMessage) {}
	~InputException() {}																	//деструктор

	void printException() override;										//прототип функции вывода ошибки на экран
};

int inputInt(istream&, int min = INT_MIN, int max = INT_MAX);			//прототип функции ввода целого числа
float inputFloat(istream&, float min = FLT_MIN, float max = FLT_MAX);	//прототип функции ввода вещественного числа
char* inputString(istream&);											//прототип функции ввода строки
char* inputCyrillicString(istream&);									//прототип функции ввода кириллической строки
char* inputLatinicString(istream&);										//прототип функции ввода латинской строки