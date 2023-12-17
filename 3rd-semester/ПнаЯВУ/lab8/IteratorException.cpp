#include "IteratorException.h"

void IteratorExeption::printException()				//функция вывода ошибки на экран
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14 << 4 | 12);
	Exception::printException();
	cout << iteratorMessage + "." << endl;
	SetConsoleTextAttribute(h, 14 << 4 | 0);
}