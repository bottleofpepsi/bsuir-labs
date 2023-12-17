#pragma once
#include "File.h"

class BinaryFile : public File								//бинарный файл
{
	fstream fs;												//поток файла

public:
	BinaryFile(const string fname = "") : File(fname) {}	//конструктор
	BinaryFile(const BinaryFile& bin) :						//конструктор копирования
		File(dynamic_cast<const File&>(bin)) {}
	~BinaryFile()											//деструктор
	{
		if (isOpen())
			closeFile();									//закрытие потока
	}

	bool isOpen();											//прототип функции проверки, открыт ли файл
	bool exists();											//прототип функции проверки, существует ли файл
	bool isEOF();											//прототип функции проверки, достигнут ли конец файла
	void clear();											//прототип функции очистки флага ошибки
	void openFile();										//прототип функции открытия файла
	void closeFile();										//прототип функции закрытия файла
	void clearBinFile();									//прототип функции очистки файла

	template <typename T>
	void readFromFile(T&);									//прототип функции чтения объекта из файла
	template <typename T>
	void writeInFile(T&);									//прототип функции записи объекта в файл
};

template <typename T>
void BinaryFile::readFromFile(T& obj)						//функция чтения объекта из файла
{
	fs >> obj;
}

template <typename T>
void BinaryFile::writeInFile(T& obj)						//функция записи объекта в файл
{
	fs << obj;
}