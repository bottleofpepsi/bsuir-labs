#pragma once
#include <iostream>
#include <iomanip>
using namespace std;


class matrix										//�������
{
	int** arr;
	int m, n;										//������� �������							

public:

	matrix(int a = 0, int b = 0) : m(a), n(b)		//����������� � �����������
	{
		arr = new int* [m];							//��������� ������ �� ������ AxB
		for (int i = 0; i < m; i++)
			arr[i] = new int[n];
	}

	matrix(const matrix& mat) : m(mat.m), n(mat.n)	//����������� �����������
	{
		this->arr = new int* [m];					//��������� ������
		for (int i = 0; i < m; i++)
		{
			this->arr[i] = new int[n];
			for (int j = 0; j < n; j++)
				this->arr[i][j] = mat.arr[i][j];	//����������� �������� ������ ������� � �����
		}
	}

	~matrix()										//����������
	{
		for (int i = 0; i < m; i++)					//������������ ������
			delete[] arr[i];
		delete[] arr;
	}

	//friend matrix operator* (const matrix& st1, const matrix& st2);	//�������� ���������� ��������� ���������
	matrix operator* (const matrix& st2);			//�������� ���������� ��������� ���������

	void input();									//�������� ������ ����� ��-���
	void output();									//�������� ������ ������ ��-��� �� �����
	matrix multiply(matrix);						//�������� ������ ��������� ������
	int exeption(matrix);							//�������� ������ �������� ������ �� �������������
};