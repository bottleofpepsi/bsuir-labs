#pragma once

#include <stdio.h>						//����������� ���������
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

union type								//�����������, ���������� ��� ���� �����
{
	struct triangle						//�����������
	{
		int h;							//������ ������������
		int b;							//����� ��������� ������������
	}tri;

	struct trapezium					//��������
	{
		int h;							//������ ��������
		int b1;							//����� ������� ��������� ��������
		int b2;							//����� ������� ��������� ��������
	}tra;

	struct circle						//����������
	{
		int r;							//������ ����������
	}cir;
};

struct shape							//���������-������		
{
	int name;							//��� ������, �������� �������������
	type t;						
	float s;							//������� ������
};

int input_nat();						//�������� ������� ����� ������������ �����
shape* allocate_memory(int);			//�������� ������� ��������� ������ ��� ������� ��������
void input_array(shape*, int);			//�������� ������� ���������� ����� ������� �����
void print_array(shape*, int);			//�������� ������� ������ ������� ��������
shape area(shape);
void result(shape*, int);				//�������� ������� ������ ������� ���������� �� �����
