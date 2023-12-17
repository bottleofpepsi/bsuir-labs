#pragma once
#include "Exception.h"
#include "BinaryFile.h"
#include "TextFile.h"

class FileException : public Exception						//ошибка файла
{
private:
	string fileMessage;										//сообщение

public:
	FileException(const string errMes = "", const string fileMes = "") :					//конструктор
		Exception(errMes), fileMessage(fileMes) {}
	FileException(const FileException& exp) :												//конструктор копирования
		Exception(dynamic_cast<const Exception&>(exp)), fileMessage(exp.fileMessage) {}
	~FileException() {}																		//деструктор

	void printException() override;							//прототип функции вывода ошибки на экран
};

string enterBinFileName();									//прототип функции ввода имени бинарного файла
string enterTxtFileName();									//прототип функции ввода имени текстового файла

template <typename T>
bool checkIfOpened(T& file)
{
	try
	{
		if (!file.exists())
			throw FileException("Ошибка открытия файла", "Файла с таким именем не существует");
		if (!file.isOpen())
			throw FileException("Ошибка открытия файла", "Невозможно открыть файл");

		return true;
	}
	catch (FileException exp)
	{
		exp.printException();							//вывод ошибки
		system("pause");
	}

	return false;
}