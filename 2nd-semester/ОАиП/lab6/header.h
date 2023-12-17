#pragma once

#include <stdio.h>									//подключение библиотек
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct stack										//cтек
{
	char lastname[30];								//фамилия студента
	stack* next;									//указатель на следующий элемент
};

struct ring											//однонаправленное кольцо
{
	int count;										//кол-во студентов в группе
	stack* group;									//группа
	ring* next;										//указатель на следующий элемент
};


ring* allocate_ring_memory();						//прототип функции выделения памяти для элемента кольца
stack* allocate_stack_memory();						//прототип функции выделения памяти для элемента стека
void push(stack**, char*);							//прототип функции добавления элемента в стек
char* pop(stack**);									//прототип функции удаления элемента из стека
void free_stack(stack*);							//прототип функции очистки стека
void free_ring(ring**);								//прототип функции очистки кольца
int input_stack(stack**);							//прототип функции ввода информации в стек
ring* get_ptr(ring*, int);							//прототип функции получения указателя на n-ый элемент кольца
void add_group(ring**);								//прототип функции создания элемента кольца
void delete_group(ring**, int);						//прототип функции удаления элемента кольца
ring* delete_min_group(ring**);						//прототип функции удаления элемента кольца с наименьшим кол-вом студентов и объединения со следующим
void add_students(ring*, int);						//прототип функции добавления элемента в стек n-ого кольца
void delete_student(ring**, int);					//прототип функции удаления элемента стека n-ого кольца
void show_all(ring*);								//прототип функции вывода информации всех элементов кольца
void show_group(ring*, int n);						//прототип функции вывода информации одного элемента кольца на экран
void print_menu();									//прототип функции вывода меню на экран