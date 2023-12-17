#pragma once

#include <stdio.h>							//подключение библиотек
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct cube									//структура-куб
{
	int length;								//длина ребра куба
	char colour[15];						//цвет куба
	char material[15];						//материал куба
};

int input_nat();							//прототип функции ввода натурального числа
cube* allocate_memory(int);					//прототип функции выделения памяти для массива структур (кубов)
int** allocate_memory_int(int, int);		//прототип функции выделения памяти для двумерного массива чисел
char** allocate_memory_char(int);			//прототип функции выделения памяти для массива строк
cube* reallocate_memory(cube*, int);		//прототип функции перевыделения памяти
void get_string(char*, int max);
int get_length(const char*);				//прототип функции определения длины строки
char* copy(char*, int);						//прототип функции копирования одного слова из строки, начиная с n-го символа
int compare(const char*, const char*);		//прототип функции сравнения двух строк
void input_array(cube*, int);				//прототип функции заполнения полей массива кубов
void print_array(cube*, int);				//прототип функции вывода входных значений
void txt_output(cube*, int, int);			//прототип функции записи таблицы в текстовый файл
cube* bin_input(int*, char*);				//прототип функции чтения таблицы из бинарного файла
void bin_output(cube*, int, char*, int);	//прототип функции записи таблицы в бинарный файл
int number_of_colours(cube*, int, char**);	//прототип функции подсчёта количества цветов
int** cube_volume(cube*, int, char**, int);	//прототип функции подсчёта кол-ва кубов по цветам
int cube_search(cube*, cube*, int, char*);	//прототип функции поиска кубов по критериям
void result(int**, char**, int);			//прототип функции вывода результата
