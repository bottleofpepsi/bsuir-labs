#include "TextFile.h"

bool TextFile::isOpen() { return (in.is_open() || out.is_open()); }		//������� ��������, ������ �� ����
bool TextFile::isEOF() { return (in.eof() || out.eof()); }				//������� ��������, ��������� �� ����� �����
bool TextFile::exists() { return (in.good() && out.good()); }			//������� ��������, ���������� �� ����

void TextFile::clear()							//������� ������� ����� ������
{
	in.seekg(0);
	out.seekp(0);
	in.clear();
	out.clear();
}

void TextFile::openFileIn()						//������� �������� �����
{
	in.open(fileName, ios::in);
}

void TextFile::closeFileIn()					//������� �������� �����
{
	if (isOpen())
		in.close();
}

void TextFile::openFileOut()					//������� �������� �����
{
	out.open(fileName, ios::out);
}

void TextFile::closeFileOut()					//������� �������� �����
{
	if (isOpen())
		out.close();
}