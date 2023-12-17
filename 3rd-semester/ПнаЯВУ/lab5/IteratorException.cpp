#include "IteratorException.h"

void IteratorExeption::printException()				//функция вывода ошибки на экран
{
	Exception::printException();
	cout << iteratorMessage + "." << endl;
}