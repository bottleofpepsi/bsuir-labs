#include "FileException.h"

void FileException::printException()						//функция вывода ошибки на экран
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14 << 4 | 12);
	Exception::printException();
	cout << fileMessage + "." << endl;
	SetConsoleTextAttribute(h, 14 << 4 | 0);
}

string enterBinFileName()									//функция ввода имени бинарного файла
{
	string fileName;

	while (true)
	{
		try
		{
			cout << "Введите имя файла: ";
			rewind(stdin);
			getline(cin, fileName);
			if (fileName.size() < 4 || fileName.substr(fileName.size() - 4, 4) != ".bin")
				throw FileException("Ошибка открытия файла", "Укажите путь к файлу с расширением .bin");

			return fileName;
		}
		catch (FileException exp)
		{
			exp.printException();							//вывод ошибки
		}
	}
}

string enterTxtFileName()									//функция ввода имени текстового файла
{
	string fileName;

	while (true)
	{
		try
		{
			cout << "Введите имя файла: ";
			rewind(stdin);
			getline(cin, fileName);
			if (fileName.size() < 4 || fileName.substr(fileName.size() - 4, 4) != ".txt")
				throw FileException("Ошибка открытия файла", "Укажите путь к файлу с расширением .txt");

			return fileName;
		}
		catch (FileException exp)
		{
			exp.printException();							//вывод ошибки
		}
	}
}