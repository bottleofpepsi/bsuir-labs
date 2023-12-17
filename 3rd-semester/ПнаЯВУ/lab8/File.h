#pragma once
#include "libs.h"

class File														//файл
{
protected:
	string fileName;											//имя файла

public:
	File(const string fname = "") : fileName(fname) {}			//конструктор
	File(const File& file) : fileName(file.fileName) {}			//конструктор копирования
	~File() {}													//деструктор

	string getFileName();										//геттер
	void setFileName(string);									//сеттер
};