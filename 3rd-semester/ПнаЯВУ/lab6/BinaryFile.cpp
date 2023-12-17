#include "BinaryFile.h"

bool BinaryFile::isOpen() { return fs.is_open(); }		//������� ��������, ������ �� ����
bool BinaryFile::isEOF() { return fs.eof(); }			//������� ��������, ��������� �� ����� �����
bool BinaryFile::exists() { return fs.good(); }			//������� ��������, ���������� �� ����

void BinaryFile::clear()								//������� ������� ����� ������
{
	fs.seekg(0);
	fs.clear();
}

void BinaryFile::openFile()								//������� �������� �����
{
	fs.open(fileName, ios::binary | ios::in | ios::out);
}

void BinaryFile::closeFile()							//������� �������� �����
{
	if (isOpen())
		fs.close();			
}

void BinaryFile::clearBinFile()							//������� ������� �����
{
	fs.open(fileName, ios::binary | ios::in | ios::out | ios::trunc);
	fs.close();
}