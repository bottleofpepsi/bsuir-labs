#pragma once

#include <stdio.h>	
#include <stdlib.h>										
#include <locale.h>	

int input_nat();										//�������� ������� ����� ����������� �������
int** allocate_memory(int n);							//�������� ������� ��������� ������ ��� ���������� ������������� ������� �������� n
void spiral(int**, int n);								//�������� ������� ���������� ������� �� �������
void print_array(int**, int n);							//�������� ������� ������ ���������� ������������� ������� �������� n
