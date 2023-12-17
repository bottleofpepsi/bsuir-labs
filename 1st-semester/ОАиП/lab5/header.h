#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int input_int();											//прототип функции ввода целого числа
int input_nat();											//прототип функции ввода натурального числа
int** allocate_memory(int, int);							//прототип функции выделения памяти
void input_array(int**, int);								//прототип функции ввода элементов массива
int exeption(int**, int);									//прототип функции обработки исключения
void print_array(int**, int);								//прототип функции вывода массива на экран
int** algorithm(int**, int);								//прототип функции основного алгоритма
int result(int**, int);										//прототип функции вывода результата