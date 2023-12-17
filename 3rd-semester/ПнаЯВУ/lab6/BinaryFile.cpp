#include "BinaryFile.h"

bool BinaryFile::isOpen() { return fs.is_open(); }		//функция проверки, открыт ли файл
bool BinaryFile::isEOF() { return fs.eof(); }			//функция проверки, достигнут ли конец файла
bool BinaryFile::exists() { return fs.good(); }			//функция проверки, существует ли файл

void BinaryFile::clear()								//функция очистки флага ошибки
{
	fs.seekg(0);
	fs.clear();
}

void BinaryFile::openFile()								//функция открытия файла
{
	fs.open(fileName, ios::binary | ios::in | ios::out);
}

void BinaryFile::closeFile()							//функция закрытия файла
{
	if (isOpen())
		fs.close();			
}

void BinaryFile::clearBinFile()							//функция очистки файла
{
	fs.open(fileName, ios::binary | ios::in | ios::out | ios::trunc);
	fs.close();
}