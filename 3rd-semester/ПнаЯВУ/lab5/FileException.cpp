#include "FileException.h"

void FileException::printException()				//������� ������ ������ �� �����
{
	Exception::printException();
	cout << fileMessage + "." << endl;
}