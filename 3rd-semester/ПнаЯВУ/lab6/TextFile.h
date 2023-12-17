#pragma once
#include "File.h"

class TextFile : public File								//текстовый файл
{
	ifstream in;											//входной поток
	ofstream out;											//выходной поток

public:
	TextFile(const string fname = "") : File(fname) {}		//конструктор
	TextFile(const TextFile& txt) :							//конструктор копирования
		File(dynamic_cast<const File&>(txt)) {}
	~TextFile()												//деструктор
	{
		if (isOpen())
		{
			closeFileIn();									//закрытие потоков
			closeFileOut();
		}
	}

	bool isOpen();											//прототип функции проверки, открыт ли файл
	bool isEOF();											//прототип функции проверки, достигнут ли конец файла
	bool exists();											//прототип функции проверки, существует ли файл
	void clear();											//прототип функции очистки флага ошибки
	void openFileIn();										//прототип функции открытия файла
	void closeFileIn();										//прототип функции закрытия файла
	void openFileOut();										//прототип функции открытия файла
	void closeFileOut();									//прототип функции закрытия файла

	template <typename T>
	void readFromFile(T&);									//прототип функции чтения объекта из файла
	template <typename T>
	void writeInFile(T&);									//прототип функции записи объекта в файл
};

template <typename T>
void TextFile::readFromFile(T& obj)							//функция чтения объекта из файла
{
	in >> obj;
}

template <typename T>
void TextFile::writeInFile(T& obj)							//функция записи объекта в файл
{
	out << obj;
}