#pragma once

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>										//����������, ����������� �������� ������������ ������

int input_int();										//�������� ������� ����� ������ �����
int input_nat();										//�������� ������� ����� ������������ �����
int* allocate_memory(int);								//�������� ������� ��������� ������
void input_array(int*, int);							//�������� ������� ����� ��������� �������
void print_array(int*, int);							//�������� ������� ������ ��������� ������� �� �����
int positive(int* a, int n);							//�������� ������� ������������ ������������� ��-��� �������
int negative(int* a, int n);							//�������� ������� ������������ ������������� ��-��� �������