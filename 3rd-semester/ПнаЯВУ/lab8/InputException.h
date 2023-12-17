#pragma once
#include "Exception.h"

class InputException : public Exception									//������ �����
{
private:
	string inputMessage;												//���������

public:
	InputException(const string errMes = "", const string inpMes = "") :					//�����������
		Exception(errMes), inputMessage(inpMes) {}
	InputException(const InputException& exp) :												//����������� �����������
		Exception(dynamic_cast<const Exception&>(exp)), inputMessage(exp.inputMessage) {}
	~InputException() {}																	//����������

	void printException() override;										//�������� ������� ������ ������ �� �����
};

int inputInt(istream&, int min = INT_MIN, int max = INT_MAX);			//�������� ������� ����� ������ �����
float inputFloat(istream&, float min = FLT_MIN, float max = FLT_MAX);	//�������� ������� ����� ������������� �����
char* inputString(istream&);											//�������� ������� ����� ������
char* inputCyrillicString(istream&);									//�������� ������� ����� ������������� ������
char* inputLatinicString(istream&);										//�������� ������� ����� ��������� ������