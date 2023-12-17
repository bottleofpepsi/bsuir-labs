#pragma once

#include <stdio.h>							//����������� ���������
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct cube									//���������-���
{
	int length;								//����� ����� ����
	char colour[15];						//���� ����
	char material[15];						//�������� ����
};

int input_nat();							//�������� ������� ����� ������������ �����
cube* allocate_memory(int);					//�������� ������� ��������� ������ ��� ������� �������� (�����)
int** allocate_memory_int(int, int);		//�������� ������� ��������� ������ ��� ���������� ������� �����
char** allocate_memory_char(int);			//�������� ������� ��������� ������ ��� ������� �����
cube* reallocate_memory(cube*, int);		//�������� ������� ������������� ������
void get_string(char*, int max);
int get_length(const char*);				//�������� ������� ����������� ����� ������
char* copy(char*, int);						//�������� ������� ����������� ������ ����� �� ������, ������� � n-�� �������
int compare(const char*, const char*);		//�������� ������� ��������� ���� �����
void input_array(cube*, int);				//�������� ������� ���������� ����� ������� �����
void print_array(cube*, int);				//�������� ������� ������ ������� ��������
void txt_output(cube*, int, int);			//�������� ������� ������ ������� � ��������� ����
cube* bin_input(int*, char*);				//�������� ������� ������ ������� �� ��������� �����
void bin_output(cube*, int, char*, int);	//�������� ������� ������ ������� � �������� ����
int number_of_colours(cube*, int, char**);	//�������� ������� �������� ���������� ������
int** cube_volume(cube*, int, char**, int);	//�������� ������� �������� ���-�� ����� �� ������
int cube_search(cube*, cube*, int, char*);	//�������� ������� ������ ����� �� ���������
void result(int**, char**, int);			//�������� ������� ������ ����������
