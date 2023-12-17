#include "String.h"

String& String::operator=(String&& obj) noexcept				//������������ �������� ������������
{
	if (&obj == this)											//�������� ���������������
		return *this;

	delete[] this->s;											//������� ������ ������

	this->s = obj.s;											//����������� ��������
	obj.s = nullptr;

	return *this;
}

String& String::operator=(const char* tmp) noexcept				//������������ �������� ������������
{
	if (!strcmp(tmp,this->s))									//�������� ���������������
		return *this;

	delete[] this->s;											//������� ������ ������

	this->s = new char[strlen(tmp) + 1];						//������������ ������ ��������
	strcpy_s(this->s, strlen(tmp) + 1, tmp);					

	return *this;
}

//String String::operator=(const String& tmp)					//���������� �������� ������������
//{
//	if (tmp == *this)											//�������� ���������������
//		return *this;
//
//	delete[] this->s;											//������������ ������ ��������
//	this->s = new char[strlen(tmp.s) + 1];						
//	strcpy_s(this->s, strlen(tmp.s) + 1, tmp.s);				
//
//	return *this;
//}

istream& operator>>(istream& in, String& obj)					//�������� �����
{
	char tmp[80];
	in.getline(tmp,80,'\n');
	obj = tmp;
	return in;
}

ostream& operator<<(ostream& out, const String& obj)			//�������� ������
{
	return out << obj.s;
}

String operator+(const String& obj1, const String& obj2)		//�������� �������� ���� ��������
{
	int len = strlen(obj1.s) + strlen(obj2.s);
	char* tmp = new char[len + 1];								//�������� ������

	strcpy_s(tmp, strlen(obj1.s) + 1, obj1.s);					//����������� ���� ����� � �����
	strcat_s(tmp, len + 1, obj2.s);

	return String(tmp);
}

String operator+(char* str, const String& obj)					//�������� �������� ������ � �������
{
	int len = strlen(str) + strlen(obj.s);
	char* tmp = new char[len + 1];								//�������� ������

	strcpy_s(tmp, strlen(str) + 1, str);						//����������� ���� ����� � �����
	strcat_s(tmp, len + 1, obj.s);

	return String(tmp);
}

String operator+(const String& obj, char* str)					//�������� �������� ������� � ������
{
	int len = strlen(obj.s) + strlen(str);
	char* tmp = new char[len + 1];								//�������� ������

	strcpy_s(tmp, strlen(obj.s) + 1, obj.s);					//����������� ���� ����� � �����
	strcat_s(tmp, len + 1, str);

	return String(tmp);
}

String& String::operator+=(const String& obj)					//�������� �������� � �������������
{
	return *this = *this + obj.s;
}

String& String::operator+=(const char* str)						//�������� �������� � �������������
{
	return *this = *this + str;
}

bool operator== (const String& obj1, const String& obj2)		//�������� ����� ��� ���� ��������
{
	if (!strcmp(obj1.s, obj2.s))
		return true;
	return false;
}

bool operator== (const String& obj, const char* str)			//�������� ����� ��� ������� � ������
{
	if (!strcmp(obj.s, str))
		return true;
	return false;
}
bool operator== (const char* str, const String& obj)			//�������� ����� ��� ������ � �������
{
	if (!strcmp(str, obj.s))
		return true;
	return false;
}

bool operator!= (const String& obj1, const String& obj2)		//�������� ������� ��� ���� ��������
{
	if (!strcmp(obj1.s, obj2.s))
		return false;
	return true;
}

bool operator!= (const String& obj, const char* str)			//�������� ������� ��� ������� � ������
{
	if (!strcmp(obj.s, str))
		return false;
	return true;
}
bool operator!= (const char* str, const String& obj)			//�������� ������� ��� ������ � �������
{
	if (!strcmp(str, obj.s))
		return false;
	return true;
}

char& String::operator[] (int k)								//�������� ����������
{
	return this->s[k];
}

String String::operator()(int start, int n)						//����� ��������� ���������
{
	char tmp[80];

	if (start > (int)strlen(this->s))							//���� ��������� ������ ��������� ��� ������						
		return String("");

	char* st = this->s;											//��������� ��������� � ������ ���������
	st += start - 1;

	strcpy_s(tmp, 80, st);										//����������� ���������
	tmp[n] = '\0';

	return String(tmp);
}