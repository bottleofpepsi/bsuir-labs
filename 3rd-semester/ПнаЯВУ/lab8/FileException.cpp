#include "FileException.h"

void FileException::printException()						//������� ������ ������ �� �����
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14 << 4 | 12);
	Exception::printException();
	cout << fileMessage + "." << endl;
	SetConsoleTextAttribute(h, 14 << 4 | 0);
}

string enterBinFileName()									//������� ����� ����� ��������� �����
{
	string fileName;

	while (true)
	{
		try
		{
			cout << "������� ��� �����: ";
			rewind(stdin);
			getline(cin, fileName);
			if (fileName.size() < 4 || fileName.substr(fileName.size() - 4, 4) != ".bin")
				throw FileException("������ �������� �����", "������� ���� � ����� � ����������� .bin");

			return fileName;
		}
		catch (FileException exp)
		{
			exp.printException();							//����� ������
		}
	}
}

string enterTxtFileName()									//������� ����� ����� ���������� �����
{
	string fileName;

	while (true)
	{
		try
		{
			cout << "������� ��� �����: ";
			rewind(stdin);
			getline(cin, fileName);
			if (fileName.size() < 4 || fileName.substr(fileName.size() - 4, 4) != ".txt")
				throw FileException("������ �������� �����", "������� ���� � ����� � ����������� .txt");

			return fileName;
		}
		catch (FileException exp)
		{
			exp.printException();							//����� ������
		}
	}
}