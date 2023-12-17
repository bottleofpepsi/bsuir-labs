#pragma once

#include <stdio.h>							//подключение библиотек
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

int input_nat();							//прототип функции ввода натурального числа
int* allocate_memory_int(int);				//прототип функции выделения памяти для двумерного массива чисел
int* reallocate_memory_int(int*, int);		//функция выделения памяти для массива двумерных чисел
char** allocate_memory_char(int);			//прототип функции выделения памяти для массива строк
void get_string(char*, int max);			//прототип функции ввода строки
int get_length(const char*);				//прототип функции определения длины строки
char* copy(char*, int);						//прототип функции копирования одного слова из строки, начиная с n-го символа
int compare(const char*, const char*);		//прототип функции сравнения двух строк
void sort(int*, int);						//прототип функции сортировки массива#pragma once
