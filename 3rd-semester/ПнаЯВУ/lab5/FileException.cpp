#include "FileException.h"

void FileException::printException()				//функция вывода ошибки на экран
{
	Exception::printException();
	cout << fileMessage + "." << endl;
}