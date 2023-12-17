#pragma once
#include "File.h"

class BinaryFile : public File								//�������� ����
{
	fstream fs;												//����� �����

public:
	BinaryFile(const string fname = "") : File(fname) {}	//�����������
	BinaryFile(const BinaryFile& bin) :						//����������� �����������
		File(dynamic_cast<const File&>(bin)) {}
	~BinaryFile()											//����������
	{
		if (isOpen())
			closeFile();									//�������� ������
	}

	bool isOpen();											//�������� ������� ��������, ������ �� ����
	bool exists();											//�������� ������� ��������, ���������� �� ����
	bool isEOF();											//�������� ������� ��������, ��������� �� ����� �����
	void clear();											//�������� ������� ������� ����� ������
	void openFile();										//�������� ������� �������� �����
	void closeFile();										//�������� ������� �������� �����
	void clearBinFile();									//�������� ������� ������� �����

	template <typename T>
	void readFromFile(T&);									//�������� ������� ������ ������� �� �����
	template <typename T>
	void writeInFile(T&);									//�������� ������� ������ ������� � ����
};

template <typename T>
void BinaryFile::readFromFile(T& obj)						//������� ������ ������� �� �����
{
	fs >> obj;
}

template <typename T>
void BinaryFile::writeInFile(T& obj)						//������� ������ ������� � ����
{
	fs << obj;
}