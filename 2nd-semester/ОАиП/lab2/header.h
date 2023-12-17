#pragma once

#include <stdio.h>						//подключение библиотек
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

union type								//объединение, содержащее все типы фигур
{
	struct triangle						//треугольник
	{
		int h;							//высота треугольника
		int b;							//длина основания треугольника
	}tri;

	struct trapezium					//трапеция
	{
		int h;							//высота трапеции
		int b1;							//длина первого основания трапеции
		int b2;							//длина второго основания трапеции
	}tra;

	struct circle						//окружность
	{
		int r;							//радиус окружности
	}cir;
};

struct shape							//структура-фигура		
{
	int name;							//тип фигуры, вводимый пользователем
	type t;						
	float s;							//площадь фигуры
};

int input_nat();						//прототип функции ввода натурального числа
shape* allocate_memory(int);			//прототип функции выделения памяти для массива структур
void input_array(shape*, int);			//прототип функции заполнения полей массива фигур
void print_array(shape*, int);			//прототип функции вывода входных значений
shape area(shape);
void result(shape*, int);				//прототип функции вывода таблицы результата на экран
