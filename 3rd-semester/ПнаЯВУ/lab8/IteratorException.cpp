#include "IteratorException.h"

void IteratorExeption::printException()				//������� ������ ������ �� �����
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14 << 4 | 12);
	Exception::printException();
	cout << iteratorMessage + "." << endl;
	SetConsoleTextAttribute(h, 14 << 4 | 0);
}