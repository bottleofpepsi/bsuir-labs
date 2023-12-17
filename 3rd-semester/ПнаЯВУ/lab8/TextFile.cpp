#include "TextFile.h"

bool TextFile::isOpen()							//функция проверки, открыт ли файл
{
	return (in.is_open() || out.is_open());
}

bool TextFile::exists()							//функция проверки, существует ли файл
{
	return (in.good() && out.good());
}

bool TextFile::isEOF()							//функция проверки, достигнут ли конец файла
{
	return (in.eof() || out.eof());
}

void TextFile::clear()							//функция очистки флага ошибки
{
	in.seekg(0);
	out.seekp(0);
	in.clear();
	out.clear();
}

void TextFile::openFileIn()						//функция открытия файла
{
	in.open(fileName, ios::in);
}

void TextFile::closeFileIn()					//функция закрытия файла
{
	if (isOpen())
		in.close();
}

void TextFile::openFileOut()					//функция открытия файла
{
	out.open(fileName, ios::out);
}

void TextFile::closeFileOut()					//функция закрытия файла
{
	if (isOpen())
		out.close();
}