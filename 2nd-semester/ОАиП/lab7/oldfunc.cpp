#include "oldheader.h"	

int input_nat()																	//функция ввода натурального числа
{
	int n = 0;																	//размерность массива
	int k = 1;																	//вспомогательная переменная для проверки на ввод целого числа

	do																			//ввод размерности массива с проверкой на целое число
	{
		rewind(stdin);															//очистка буфера
		k = scanf_s("%d", &n);

		if (!k || n < 0)
			printf("Должно быть введено натуральное число!\n");
	} while (!k || n < 0);														//если введено не целое число, цикл повторяется

	return n;
}

int* allocate_memory_int(int m)													//функция выделения памяти для массива двумерных чисел
{
	int* array;

	array = (int*)calloc(m, sizeof(int));
	if (!array) return nullptr;

	return array;
}

int* reallocate_memory_int(int* array, int m)									//функция перевыделения памяти для массива двумерных чисел
{
	int* tmp;

	tmp = (int*)realloc(array, m * sizeof(int));
	if (!tmp) array = tmp;

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

void get_string(char* str, int max)												//функция ввода строки
{
	if (str)
	{
		rewind(stdin);															//очистка буфера
		fgets(str, max, stdin);
		*(str + get_length(str)) = '\0';										//размещение нуль-символа в конце строки
	}
}

int get_length(const char* str)													//функция определения длины строки
{
	int i = 0;																	//счётчик кол-ва символов в строке

	while (*(str + i) != '\0' && *(str + i) != '\n') i++;						//увеличивать счётчик, пока не будет встречен нуль-символ

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
#define ch *(str + k + p)														//макрос для упрощения восприятия кода

	char* word;																	//символьная строка, содержащая слово
	int p = 0,																	//длина этой строки
		i = 0;

	while (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ','
		&& ch != ':' && ch != ';' && ch != '\0' && ch != '\n' && ch != EOF) p++;	//пока не встречен знак препинания
	word = (char*)calloc(p, sizeof(char));											//выделение памяти для массива

	if (word)																	//если память была выделена
	{
		for (i = 0; i < p; i++)
			*(word + i) = *(str + k + i);										//копирование очередного символа
		*(word + i) = '\0';														//размещение нуль-символа в конце строки
	}

	return word;
}

void sort(int* arr, int k)														//функция сортировки массива пузырьком
{
	int i = 0,
		j = 0,
		temp = 0;

	for (i = 0; i < k - 1; i++)
		for (j = 0; j < k - i - 1; j++)
			if (*(arr + j) > *(arr + j + 1))
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
}