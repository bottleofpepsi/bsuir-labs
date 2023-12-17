#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class String
{
private:
	char* s;

public:
	String(const char* input = "")									//�����������
	{
		s = new char[strlen(input) + 1];
		strcpy_s(s, strlen(input) + 1, input);
	}
	//String(const String& input)									//����������� �����������
	//{
	//	this->s = new char[strlen(input.s) + 1];
	//	strcpy_s(this->s, strlen(input.s) + 1, input.s);
	//}
	String(String&& str1) noexcept : s(str1.s)						//����������� �����������
	{
		str1.s = nullptr;
	}
	~String()														//����������
	{
		delete[] s;
	}

	//String operator=(const String& ob);							//��������� ���������� ������������
	String& operator=(String&&) noexcept;
	String& operator=(const char* tmp) noexcept;

	friend istream& operator>>(istream&, String&);					//�������� ��������� �����
	friend ostream& operator<<(ostream&, const String&);			//�������� ��������� ������

	friend String operator+(const String&, const String&);			//��������� ���������� ��������
	friend String operator+(char*, const String&);
	friend String operator+(const String&, char*);

	String& operator+=(const String&);								//��������� ���������� �������� � �������������
	String& operator+=(const char*);

	friend bool operator== (const String&, const String&);			//��������� ���������� �����
	friend bool operator== (const String&, const char*);
	friend bool operator== (const char*, const String&);

	friend bool operator!= (const String&, const String&);			//��������� ���������� �������
	friend bool operator!= (const String&, const char*);
	friend bool operator!= (const char*, const String&);

	char& operator[] (int);											//�������� ��������� ����������
	String operator()(int, int);									//�������� ������ ��������� ���������
};