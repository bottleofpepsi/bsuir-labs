#pragma once

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>										//библиотека, позволяющая выделять динамическую память

int input_int();										//прототип функции ввода целого числа
int input_nat();										//прототип функции ввода натурального числа
int* allocate_memory(int);								//прототип функции выделения памяти
void input_array(int*, int);							//прототип функции ввода элементов массива
void print_array(int*, int);							//прототип функции вывода элементов массива на экран
int positive(int* a, int n);							//прототип функции суммирования положительных эл-тов массива
int negative(int* a, int n);							//прототип функции суммирования отрицательных эл-тов массива