#pragma once

#include <stdio.h>							//подключение библиотек
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include "oldheader.h"

struct stack								//стек
{
	int pos;								//позиция скобки в строке
	char bracket;							//вид скобки
	stack* next;							//указатель на следующий элемент
};

stack* allocate_memory();					//прототип функции выделения памяти для массива структур (кубов)
void push(stack**, int, char);				//прототип функции добавления эл-та в стек
int pop(stack**);							//прототип функции добавления эл-та в стек
void free_stack(stack*);					//прототип функции очистки стека
int* check(char*, stack*, int*);			//прототип функции поиска ошибок
void highlight(int*, char*);				//прототип функции подсветки ошибок