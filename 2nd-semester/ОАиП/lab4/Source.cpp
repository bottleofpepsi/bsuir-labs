#include "header.h"																	//хэдер с прототипами функций и необходимыми библиотеками


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	cube* array = nullptr;																//массив кубов
	cube* array_new;																	//массив искомых кубов
	char** colours;																		//массив цветов

	char str[50] = {};																	//строка для ввода критериев поиска
	char name[] = "binary.bin";															//имя файла

	int k = 0,																			//кол-во кубов
		k1 = 0,																			//кол-во искомых кубов
		n = 0,																			//кол-во цветов
		select = 0;

	while (1)
	{
		printf("Меню: \n1 — Ввод данных с клавиатуры \n2 — Запись в текстовый файл");		
		printf("\n3 — Дозапись в текстовый файл \n4 — Запись в бинарный файл");
		printf("\n5 — Дозапись в бинарный файл \n6 — Чтение из бинарного файла");
		printf("\n7 — Вычисление объёма кубов \n8 — Поиск кубов по критериям\n9 — Выход\n");

		printf("\nВвод: ");
		select = input_nat();															//выбор операции
		switch (select)
		{
		case 1:																			//ввод данных с клавиатуры
			printf("\nВведите количество кубов: ");
			k = input_nat();															//ввод кол-ва кубов
			array = allocate_memory(k);													//выделение памяти для массива кубов

			if (array)																	//еслм память была выделена
			{
				printf("\nВведите данные о кубах (длина ребра, цвет, материал):\n");
				input_array(array, k);													//заполнение полей массива кубов
				print_array(array, k);													//вывод входных данных на экран
			}
			break;
		case 2:																			//запись данных в текстовый файл
			if (!array)
			{
				printf("Таблица данных пуста!\n\n");
				break;
			}
			txt_output(array, k, 0);													//вызов функции записи структуры в текстовый файл
			break;
		case 3:																			//дозапись данных в текстовый файл
			if (!array)
			{
				printf("Таблица данных пуста!\n\n");
				break;
			}
			txt_output(array, k, 1);													//вызов функции дозаписи структуры в текстовый файл
			break;
		case 4:																			//запись данных в бинарный файл
			if (!array)
			{
				printf("Таблица данных пуста!\n\n");
				break;
			}
			bin_output(array, k, name, 0);												//вызов функции записи структуры в бинарный файл
			break;
		case 5:																			//дозапись данных в бинарный файл
			if (!array)
			{
				printf("Таблица данных пуста!\n\n");
				break;
			}
			bin_output(array, k, name, 1);												//вызов функции дозаписи структур в бинарный файл
			break;
		case 6:																			//чтение данных из бинарного файла
			array = bin_input(&k, name);												//вызов функции чтения структур из бинарный файл
			print_array(array, k);														//вывод результат на экран
			break;
		case 7:																			//вычисление общего объёма кубов каждого цвета	
			colours = allocate_memory_char(k);											//выделение памяти для массива цветов
			n = number_of_colours(array, k, colours);
			result(cube_volume(array, k, colours, n), colours, n);

			free(colours);																//очистка памяти
			break;
		case 8:																			//поиск кубов по желаемым критериям
			array_new = allocate_memory(k);												//выделение памяти для массива искомых кубов
			printf("\nКакие кубы вы хотите найти? (Длина ребра, цвет, материал)\n");

			rewind(stdin);																//очистка буфера
			fgets(str, 50, stdin);														//ввод критериев
			k1 = cube_search(array, array_new, k, str);									//поиск кубов по введённым критериям
			if (k1)
			{
				array_new = reallocate_memory(array_new, k1);							//перевыделение памяти с учётом настоящих размеров массивов
				print_array(array_new, k1);												//вывод результата		
				printf("Кол-во таких кубов: %d\n", k1);
			}
			else
				printf("Такие кубы не найдены!\n");

			free(array_new);															//очистка памяти
			break;
		case 9:
			if (array)
				free(array);															//очистка памяти
			return 0;
		default: printf("Некорректный ввод!\n");
		}
	}

	return 0;
}