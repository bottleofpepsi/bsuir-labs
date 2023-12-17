#pragma once

#include <stdio.h>							//����������� ���������
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

int input_nat();							//�������� ������� ����� ������������ �����
int* allocate_memory_int(int);				//�������� ������� ��������� ������ ��� ���������� ������� �����
int* reallocate_memory_int(int*, int);		//������� ��������� ������ ��� ������� ��������� �����
char** allocate_memory_char(int);			//�������� ������� ��������� ������ ��� ������� �����
void get_string(char*, int max);			//�������� ������� ����� ������
int get_length(const char*);				//�������� ������� ����������� ����� ������
char* copy(char*, int);						//�������� ������� ����������� ������ ����� �� ������, ������� � n-�� �������
int compare(const char*, const char*);		//�������� ������� ��������� ���� �����
void sort(int*, int);						//�������� ������� ���������� �������#pragma once
