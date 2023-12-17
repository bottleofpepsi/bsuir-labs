#pragma once
#include "Exception.h"
#include "BinaryFile.h"
#include "TextFile.h"

class FileException : public Exception						//������ �����
{
private:
	string fileMessage;										//���������

public:
	FileException(const string errMes = "", const string fileMes = "") :					//�����������
		Exception(errMes), fileMessage(fileMes) {}
	FileException(const FileException& exp) :												//����������� �����������
		Exception(dynamic_cast<const Exception&>(exp)), fileMessage(exp.fileMessage) {}
	~FileException() {}																		//����������

	void printException() override;							//�������� ������� ������ ������ �� �����
};

string enterBinFileName();									//�������� ������� ����� ����� ��������� �����
string enterTxtFileName();									//�������� ������� ����� ����� ���������� �����

template <typename T>
bool checkIfOpened(T& file)
{
	try
	{
		if (!file.exists())
			throw FileException("������ �������� �����", "����� � ����� ������ �� ����������");
		if (!file.isOpen())
			throw FileException("������ �������� �����", "���������� ������� ����");

		return true;
	}
	catch (FileException exp)
	{
		exp.printException();							//����� ������
		system("pause");
	}

	return false;
}