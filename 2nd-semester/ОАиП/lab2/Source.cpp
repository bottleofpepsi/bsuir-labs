#include "header.h"																	//хэдер с прототипами функций и необходимыми библиотеками


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int exit = 0;																	//символ для проверки на выход из программы

	do
	{
		system("cls");

		shape* array;																//массив фигур
		int n = 0;																	//кол-во фигур
		
		printf("Введите число количества фигур: ");
		n = input_nat();
		array = allocate_memory(n);													//выделение памяти для массива фигур

		if (array)
		{
			input_array(array, n);													//ввод данных о фигурах
			print_array(array, n);													//вывод введённых данных в виде таблицы

			for (int i = 0; i < n; i++)												//подсчёт площади каждой фигуры
				*(array + i) = area(*(array + i));
			result(array, n);														//вывод результата в виде таблицы
		}

		do
		{
			printf_s("\nПродолжить? (y - да / n - нет): ");							//запрос на продолжение программы
			rewind(stdin);															//очистка буфера для корректного ввода символа
			exit = getchar();														//получение символа
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');

	return 0;
}