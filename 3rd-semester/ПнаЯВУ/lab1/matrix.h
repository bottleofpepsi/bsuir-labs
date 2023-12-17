#pragma once
#include <iostream>
#include <iomanip>
using namespace std;


class matrix										//матрица
{
	int** arr;
	int m, n;										//размеры массива							

public:

	matrix(int a = 0, int b = 0) : m(a), n(b)		//конструктор с параметрами
	{
		arr = new int* [m];							//выделение памяти на массив AxB
		for (int i = 0; i < m; i++)
			arr[i] = new int[n];
	}

	matrix(const matrix& mat) : m(mat.m), n(mat.n)	//конструктор копирования
	{
		this->arr = new int* [m];					//выделение памяти
		for (int i = 0; i < m; i++)
		{
			this->arr[i] = new int[n];
			for (int j = 0; j < n; j++)
				this->arr[i][j] = mat.arr[i][j];	//копирование значений старой матрицы в новую
		}
	}

	~matrix()										//деструктор
	{
		for (int i = 0; i < m; i++)					//освобождение памяти
			delete[] arr[i];
		delete[] arr;
	}

	//friend matrix operator* (const matrix& st1, const matrix& st2);	//прототип перегрузки оператора умножения
	matrix operator* (const matrix& st2);			//прототип перегрузки оператора умножения

	void input();									//прототип метода ввода эл-тов
	void output();									//прототип метода вывода эл-тов на экран
	matrix multiply(matrix);						//прототип метода умножения матриц
	int exeption(matrix);							//прототип метода проверки матриц на совместимость
};