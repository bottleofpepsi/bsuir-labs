#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdarg.h>

int input_nat();												//прототип функции ввода натурального числа
char** allocate_memory(int);									//прототип функции выделения памяти для массива символьных строк
int* allocate_memory_int(int n);								//прототип функции выделения памяти для массива целых чисел
void get_string(char*);											//прототип функции ввода строки
void get_text(char**, int);										//прототип функции ввода текста
int number_of_words(char**);									//прототип функции нахождения кол-ва слов в тексте
int get_length(char*);											//прототип функции нахождения длины строки
char* copy(char*, int);											//прототип функции копирования одного слова из строки, начиная с n-го символа
int compare(int, ...);											//прототип функции сравнения двух строк
void hoor(char**, int*, int, int);								//прототип функции сортировки методом Хоара
void swap_int(int*, int, int);									//прототип функции замены двух чисел местами в массиве
void swap_str(char**, int, int);								//прототип функции замены двух строк местами в массиве
void find(char**, char**, int*);								//прототип функции нахождения повторяющихся слов
void result(char**, int*, int);									//прототип функции вывода результата