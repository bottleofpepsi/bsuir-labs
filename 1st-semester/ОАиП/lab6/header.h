#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int input_nat();								//прототип функции ввода натурального числа
char* allocate_memory(int);						//прототип функции выделения памяти
void get_string(char*, int);					//прототип функции ввода строки
int get_length(char*);							//прототип функции определения длины строки
int compare(char*, char*, int);					//прототип функции проверки, является ли str1 подстрокой строки str, начиная с k-го символа
char* replace(char*, char*, char*);				//прототип функции замены всех вхождений подстроки str1 на str2 в строке str