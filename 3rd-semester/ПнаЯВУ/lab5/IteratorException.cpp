#include "IteratorException.h"

void IteratorExeption::printException()				//������� ������ ������ �� �����
{
	Exception::printException();
	cout << iteratorMessage + "." << endl;
}