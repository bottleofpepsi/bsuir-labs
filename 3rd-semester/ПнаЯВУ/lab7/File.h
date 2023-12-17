#pragma once
#include "libs.h"

class File														//����
{
protected:
	string fileName;											//��� �����

public:
	File(const string fname = "") : fileName(fname) {}			//�����������
	File(const File& file) : fileName(file.fileName) {}			//����������� �����������
	~File() {}													//����������

	string getFileName();										//������
	void setFileName(string);									//������
};