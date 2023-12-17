#pragma once

#include <stdio.h>									//����������� ���������
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct stack										//c���
{
	char lastname[30];								//������� ��������
	stack* next;									//��������� �� ��������� �������
};

struct ring											//���������������� ������
{
	int count;										//���-�� ��������� � ������
	stack* group;									//������
	ring* next;										//��������� �� ��������� �������
};


ring* allocate_ring_memory();						//�������� ������� ��������� ������ ��� �������� ������
stack* allocate_stack_memory();						//�������� ������� ��������� ������ ��� �������� �����
void push(stack**, char*);							//�������� ������� ���������� �������� � ����
char* pop(stack**);									//�������� ������� �������� �������� �� �����
void free_stack(stack*);							//�������� ������� ������� �����
void free_ring(ring**);								//�������� ������� ������� ������
int input_stack(stack**);							//�������� ������� ����� ���������� � ����
ring* get_ptr(ring*, int);							//�������� ������� ��������� ��������� �� n-�� ������� ������
void add_group(ring**);								//�������� ������� �������� �������� ������
void delete_group(ring**, int);						//�������� ������� �������� �������� ������
ring* delete_min_group(ring**);						//�������� ������� �������� �������� ������ � ���������� ���-��� ��������� � ����������� �� ���������
void add_students(ring*, int);						//�������� ������� ���������� �������� � ���� n-��� ������
void delete_student(ring**, int);					//�������� ������� �������� �������� ����� n-��� ������
void show_all(ring*);								//�������� ������� ������ ���������� ���� ��������� ������
void show_group(ring*, int n);						//�������� ������� ������ ���������� ������ �������� ������ �� �����
void print_menu();									//�������� ������� ������ ���� �� �����