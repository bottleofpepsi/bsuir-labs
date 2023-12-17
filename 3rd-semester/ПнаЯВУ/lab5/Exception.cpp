#include "Exception.h"

void Exception::printException()					//функция вывода ошибки на экран
{
	cout << "Error: " + errorMessage + ". ";
}