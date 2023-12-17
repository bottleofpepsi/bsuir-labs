#pragma once

#include <stdio.h>	
#include <stdlib.h>										
#include <locale.h>	

int input_nat();										//прототип функции ввода размерности массива
int** allocate_memory(int n);							//прототип функции выделения памяти для двумерного динамического массива размером n
void spiral(int**, int n);								//прототип функции заполнения массива по спирали
void print_array(int**, int n);							//прототип функции вывода двумерного динамического массива размером n
