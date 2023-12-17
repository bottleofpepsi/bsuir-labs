#include "header.h"																//хэдер с прототипами функций и необходимыми библиотеками

int input_nat()																	//функция ввода натурального числа
{
	int n = 0;																	//размерность массива
	int k = 1;																	//вспомогательная переменная для проверки на ввод целого числа

	do																			//ввод размерности массива с проверкой на целое число
	{
		rewind(stdin);															//очистка буфера
		k = scanf_s("%d", &n);

		if (!k || n <= 0)
			printf("Должно быть введено натуральное число!\n");
	} while (!k || n <= 0);														//если введено не целое число, цикл повторяется

	return n;
}

cube* allocate_memory(int n)													//функция выделения памяти для массива структур (кубов)
{
	int i = 0;
	cube* array;																//массив кубов

	array = (cube*)calloc(n, sizeof(cube));
	if (!array)																	//если память не была выделена
	{
		printf("Память не была выделена!");
		return 0;
	}

	return array;																//возврат массива структур
}

int** allocate_memory_int(int n, int m)											//функция выделения памяти для массива двумерных чисел
{
	int** array,
		  i = 0;

	array = (int**)calloc(n, sizeof(int*));										//выделение памяти
	if (!array) return 0;

	for (i = 0; i < n; i++)
	{
		*(array + i) = (int*)calloc(m, sizeof(int));
		if (!*(array + i)) return 0;
	}

	return array;
}

char** allocate_memory_char(int k)												//функция выделения памяти для массива строк
{
	char** array;
	int i = 0;

	array = (char**)calloc(k, sizeof(char*));
	if (!array) return nullptr;													//если память не выделилась

	for (i = 0; i < k; i++)														//выделение памяти для i-той строки
	{
		*(array + i) = (char*)calloc(50, sizeof(char));
	}

	return array;
}

cube* reallocate_memory(cube* array, int k)										//функция перевыделения памяти
{
	cube* temp;																	//буфферный массив

	temp = (cube*)realloc(array, k * sizeof(cube));								
	if (temp) array = temp;

	return array;
}

void get_string(char* str)														//функция ввода строки
{
	int i = 0;

	if (str)
	{
		rewind(stdin);															//очистка буфера
		while (i < 50)
		{
			*(str + i) = getchar();												//ввод очередного символа
			if (*(str + i) == '\n')												//если ввод строки окончен досрочно нажатием Enter, то цикл прерывается
				break;
			i++;
		}
		*(str + i) = '\0';														//размещение нуль-символа в конце строки
	}
}

int get_length(const char* str)													//функция определения длины строки
{
	int i = 0;																	//счётчик кол-ва символов в строке

	while (*(str + i) != '\0') i++;												//увеличивать счётчик, пока не будет встречен нуль-символ

	return i;
}

int compare(const char* str, const char* str1)									//функция сравнения двух строк
{
	int i = 0;

	if (get_length(str) != get_length(str1)) return 0;							//если длины строк отличаются, то выполнение функции прекращается

	for (i = 0; i < get_length(str); i++)
		if (*(str + i) != *(str1 + i)) return 0;								//если хотя бы один символ не совпадает, то выполнение функции прекращается

	return 1;																	//функция возвращает 1 при успешном выполнении и 0 при неудачном
}

char* copy(char* str, int k)													//функция копирования одного слова из строки, начиная с n-го символа
{
	#define ch *(str + k + p)													//макрос для упрощения восприятия кода

	char* word;																	//символьная строка, содержащая слово
	int p = 0,																	//длина этой строки
		i = 0;

	while (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ','
		&& ch != ':' && ch != ';' && ch != '\0' && ch != EOF) p++;				//пока не встречен знак препинания
	word = (char*)calloc(p, sizeof(char));										//выделение памяти для массива

	if (word)																	//если память была выделена
	{
		for (i = 0; i < p; i++)
			*(word + i) = *(str + k + i);										//копирование очередного символа
		*(word + i) = '\0';														//размещение нуль-символа в конце строки
	}

	return word;
}






















































void input_array(cube* array, int n)											//функция заполнения полей массива кубов
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		(array + i)->length = input_nat();										//ввод длины ребра i-ого куба
		get_string((array + i)->colour);										//ввод цвета i-ого куба
		get_string((array + i)->material);										//ввод материала i-ого куба
	}
}

void print_array(cube* array, int n)											//функция вывода входных значений
{
	int i = 0;

	puts("\n================================================");					//оформление в виде таблицы
	puts("================================================\n");

	printf("Длина ребра: | Цвет:      | Материал:\n\n");

	for (i = 0; i < n; i++)
		printf("%-3d см       | %-10s | %-10s\n", (array + i) -> length, (array + i) -> colour, (array + i) -> material);	//вывод длины ребра, цвета и материала очередного куба

	puts("\n================================================");
	puts("================================================\n");
}

int number_of_colours(cube* cubes, int k, char** colours)						//функция подсчёта количества цветов
{
	int n = 0,																	//кол-во цветов
		i = 0,
		j = 0,
		flag = 0;

	while (i != k)
	{
		for (j = 0; j < n; j++)
			if(compare((cubes + i)->colour, *(colours + j))) flag = 1;			//проверка, если цвет уже есть в массиве
		if (!flag)																//если цвет очередного куба ещё не записан
		{
			*(colours + n) = (cubes + i)->colour;								//запись цвета в массив
			n++;																//увеличение счётчика кол-ва цветов
		}
		i++;
		flag = 0;
	}

	return n;
}

int** cube_volume(cube* cubes, int k, char** colours, int n)					//функция подсчёта кол-ва кубов по цветам
{
	int** array,																//массив, содержащий кол-во кубов и общий объём для каждого цвета
		i = 0,
		j = 0;

	array = allocate_memory_int(n, 2);											//выделение памяти для массива
	if (!array) return 0;

	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n; j++)
			if (compare((cubes + i)->colour, *(colours + j)))							
			{
				**(array + j) += 1;												//увеличения счётчика кол-ва кубов определённого цвета
				*(*(array + j) + 1) += pow((cubes + i)->length, 3);				//суммирование объёма очередного куба с общим объёмом
			}
	}

	return array;	
}

int cube_search(cube* cubes, cube* array, int k, char* str)						//функция поиска кубов по критериям
{
	int i = 0,
		j = 0,
		t = 0,																	//кол-во искомых кубов
		sign = 0,																
		length = 0;																//длина искомых кубов
	char* search_criteria[4];													//массив свойств искомого куба (длина ребра, цвет, материал)
	int arr[4] = {0};															

	for (i = 0; i < 4; i++)														//чтение строки с критериями поиска
	{
		search_criteria[i] = copy(str, j);										//запись очередного критерия в массив
		if (compare(search_criteria[i], "-\0"))									//если поиск по этому свойству не выполняется
			arr[i] = 1;
		
		j += get_length(search_criteria[i]);									//пропуск найденного слова
		while (*(str + j) == ' ') j++;											//пропуск пробелов до следующего слова
	}

	if (compare(search_criteria[0], "Больше\0") || compare(search_criteria[0], ">\0"))				//если нужно найти кубы с длиной больше введённой
		sign = 1;
	if (compare(search_criteria[0], "Меньше\0") || compare(search_criteria[0], "<\0"))				//если нужно найти кубы с длиной меньше введённой
		sign = -1;
	if (compare(search_criteria[0], "Равно\0") || compare(search_criteria[0], "=\0"))				//если нужно найти кубы с введённой длиной
		sign = 0;
		
	length = atoi(search_criteria[1]);											//преобразование введённой длины ребра из строки в число

	for (i = 0; i < k; i++)
		if ((compare(search_criteria[2], (cubes + i)->colour) || arr[2]) &&		
			(compare(search_criteria[3], (cubes + i)->material) || arr[3]) &&
			((sign == 1 && (cubes + i)->length > length) || (sign == -1 && (cubes + i)->length < length) || (sign == 0 && (cubes + i)->length == length) || arr[1]))
		{
			*(array + t) = *(cubes + i);										//копирование структуры в новый массив структур
			t++;																//подсчёт кол-ва искомых кубов		
		}

	return t;
}

void result(int** array, char** colours, int n)									//функция вывода результата
{
	int i = 0;

	puts("\n================================================");					//оформление в виде таблицы
	puts("================================================\n");

	printf("Цвет:      | Кол-во: | Объём:\n\n");

	for (i = 0; i < n; i++)
		printf("%-10s | %-4d    | %-5d см^3\n", *(colours + i), **(array + i), *(*(array + i) + 1));	//вывод цвета, кол-ва кубов такого цвета, общий объём этих кубов

	puts("\n================================================");
	puts("================================================\n");
}