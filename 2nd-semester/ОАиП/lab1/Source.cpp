#include "header.h"																	//хэдер с прототипами функций и необходимыми библиотеками


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int exit = 0;																	//символ для проверки на выход из программы

	system("cls");

	cube* array;																	//массив кубов
	cube* array_new;																//массив искомых кубов
	char** colours;																	//массив цветов

	char str[50] = {};																//строка для ввода критериев поиска

	int k = 0,																		//кол-во кубов
		k1 = 0,																		//кол-во искомых кубов
		n = 0,																		//кол-во цветов
		select = 0;

	printf("Введите количество кубов: ");
	k = input_nat();																//ввод кол-ва кубов
	array = allocate_memory(k);														//выделение памяти для массива кубов

	if (array)																		//еслм память была выделена
	{
		printf("\nВведите данные о кубах (длина ребра, цвет, материал):\n");
		input_array(array, k);														//заполнение полей массива кубов
		print_array(array, k);														//вывод входных данных на экран
	}

	do
	{
		printf("Меню: \n1 — Посчитать объём кубов каждого цвета \n2 — Поиск кубов по желаемым критериям\n");
		select = input_nat();														//выбор операции

		switch (select)
		{
			case 1:																	//вычисление общего объёма кубов каждого цвета	
			{
				colours = allocate_memory_char(k);									//выделение памяти для массива цветов
				n = number_of_colours(array, k, colours); 
				result(cube_volume(array, k, colours, n), colours, n);

				free(colours);														//очистка памяти
				break;									
			}
			case 2:																	//поиск кубов по желаемым критериям
			{
				array_new = allocate_memory(k);										//выделение памяти для массива искомых кубов
				printf("\nКакие кубы вы хотите найти? (Длина ребра, цвет, материал)\n");
				get_string(str);													//ввод критериев
				k1 = cube_search(array, array_new, k, str);							//поиск кубов по введённым критериям
				if (k1)																
				{
					array_new = reallocate_memory(array_new, k1);					//перевыделение памяти с учётом настоящих размеров массивов
					print_array(array_new, k1);										//вывод результата		
					printf("Кол-во таких кубов: %d\n", k1);
				}
				else
					printf("Такие кубы не найдены!\n");

				free(array_new);													//очистка памяти
				break;
			}
			default: printf("Некорректный ввод!\n");
		}
		do
		{
			printf_s("\nПовторить? (y - да / n - нет): ");							//запрос на продолжение программы
			rewind(stdin);															//очистка буфера для корректного ввода символа
			exit = getchar();														//получение символа
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');

	free(array);																	//очистка памяти

	return 0;
}