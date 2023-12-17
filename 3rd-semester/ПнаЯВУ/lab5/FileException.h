#pragma once
#include "Exception.h"

class FileException : public Exception							//������ �����
{
private:
	string fileMessage;											//���������

public:
	FileException(const string errMes = "", const string fileMes = "") :					//�����������
		Exception(errMes), fileMessage(fileMes) {}
	FileException(const FileException& exp) :												//����������� �����������
		Exception(dynamic_cast<const Exception&>(exp)), fileMessage(exp.fileMessage) {}
	~FileException() {}																		//����������

	void printException() override;								//�������� ������� ������ ������ �� �����
};