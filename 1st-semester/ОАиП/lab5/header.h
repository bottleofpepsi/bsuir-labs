#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int input_int();											//�������� ������� ����� ������ �����
int input_nat();											//�������� ������� ����� ������������ �����
int** allocate_memory(int, int);							//�������� ������� ��������� ������
void input_array(int**, int);								//�������� ������� ����� ��������� �������
int exeption(int**, int);									//�������� ������� ��������� ����������
void print_array(int**, int);								//�������� ������� ������ ������� �� �����
int** algorithm(int**, int);								//�������� ������� ��������� ���������
int result(int**, int);										//�������� ������� ������ ����������