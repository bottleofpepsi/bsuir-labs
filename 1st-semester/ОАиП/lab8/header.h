#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdarg.h>

int input_nat();												//�������� ������� ����� ������������ �����
char** allocate_memory(int);									//�������� ������� ��������� ������ ��� ������� ���������� �����
int* allocate_memory_int(int n);								//�������� ������� ��������� ������ ��� ������� ����� �����
void get_string(char*);											//�������� ������� ����� ������
void get_text(char**, int);										//�������� ������� ����� ������
int number_of_words(char**);									//�������� ������� ���������� ���-�� ���� � ������
int get_length(char*);											//�������� ������� ���������� ����� ������
char* copy(char*, int);											//�������� ������� ����������� ������ ����� �� ������, ������� � n-�� �������
int compare(int, ...);											//�������� ������� ��������� ���� �����
void hoor(char**, int*, int, int);								//�������� ������� ���������� ������� �����
void swap_int(int*, int, int);									//�������� ������� ������ ���� ����� ������� � �������
void swap_str(char**, int, int);								//�������� ������� ������ ���� ����� ������� � �������
void find(char**, char**, int*);								//�������� ������� ���������� ������������� ����
void result(char**, int*, int);									//�������� ������� ������ ����������