#pragma once
#include "Exception.h"

class FileException : public Exception							//ошибка файла
{
private:
	string fileMessage;											//сообщение

public:
	FileException(const string errMes = "", const string fileMes = "") :					//конструктор
		Exception(errMes), fileMessage(fileMes) {}
	FileException(const FileException& exp) :												//конструктор копирования
		Exception(dynamic_cast<const Exception&>(exp)), fileMessage(exp.fileMessage) {}
	~FileException() {}																		//деструктор

	void printException() override;								//прототип функции вывода ошибки на экран
};