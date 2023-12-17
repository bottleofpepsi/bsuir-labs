#pragma once

#include <stdio.h>							//����������� ���������
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include "oldheader.h"

struct stack								//����
{
	int pos;								//������� ������ � ������
	char bracket;							//��� ������
	stack* next;							//��������� �� ��������� �������
};

stack* allocate_memory();					//�������� ������� ��������� ������ ��� ������� �������� (�����)
void push(stack**, int, char);				//�������� ������� ���������� ��-�� � ����
int pop(stack**);							//�������� ������� ���������� ��-�� � ����
void free_stack(stack*);					//�������� ������� ������� �����
int* check(char*, stack*, int*);			//�������� ������� ������ ������
void highlight(int*, char*);				//�������� ������� ��������� ������