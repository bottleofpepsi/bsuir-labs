#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int input_nat();								//�������� ������� ����� ������������ �����
char* allocate_memory(int);						//�������� ������� ��������� ������
void get_string(char*, int);					//�������� ������� ����� ������
int get_length(char*);							//�������� ������� ����������� ����� ������
int compare(char*, char*, int);					//�������� ������� ��������, �������� �� str1 ���������� ������ str, ������� � k-�� �������
char* replace(char*, char*, char*);				//�������� ������� ������ ���� ��������� ��������� str1 �� str2 � ������ str