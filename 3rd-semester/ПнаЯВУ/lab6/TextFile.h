#pragma once
#include "File.h"

class TextFile : public File								//��������� ����
{
	ifstream in;											//������� �����
	ofstream out;											//�������� �����

public:
	TextFile(const string fname = "") : File(fname) {}		//�����������
	TextFile(const TextFile& txt) :							//����������� �����������
		File(dynamic_cast<const File&>(txt)) {}
	~TextFile()												//����������
	{
		if (isOpen())
		{
			closeFileIn();									//�������� �������
			closeFileOut();
		}
	}

	bool isOpen();											//�������� ������� ��������, ������ �� ����
	bool isEOF();											//�������� ������� ��������, ��������� �� ����� �����
	bool exists();											//�������� ������� ��������, ���������� �� ����
	void clear();											//�������� ������� ������� ����� ������
	void openFileIn();										//�������� ������� �������� �����
	void closeFileIn();										//�������� ������� �������� �����
	void openFileOut();										//�������� ������� �������� �����
	void closeFileOut();									//�������� ������� �������� �����

	template <typename T>
	void readFromFile(T&);									//�������� ������� ������ ������� �� �����
	template <typename T>
	void writeInFile(T&);									//�������� ������� ������ ������� � ����
};

template <typename T>
void TextFile::readFromFile(T& obj)							//������� ������ ������� �� �����
{
	in >> obj;
}

template <typename T>
void TextFile::writeInFile(T& obj)							//������� ������ ������� � ����
{
	out << obj;
}