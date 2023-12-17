#include "header.h"														//хэдер с прототипами функций и необходимыми библиотеками


int main()
{
	setlocale(LC_ALL, "Russian");

	int exit = 0;														//символ для проверки на выход из программы

	do
	{
		char* str,														//основная строка
			* str1,														//подстрока, которую требуется заменить
			* str2;														//подстрока, на которую требуется заменить str1
		int len = 0,													//длина строки str
			len1 = 0,													//длина строки str1
			len2 = 0;													//длина строки str2

		system("cls");													//очистка консоли

		printf("Введите размер строки str: ");
		len = input_nat();												//ввод длины строки str
		str = allocate_memory(len);										//выделение памяти для str
		printf("Введите строку str: ");
		get_string(str, len);											//ввод str

		printf("\nВведите размер строки str1: ");
		len1 = input_nat();												//ввод длины строки str1
		str1 = allocate_memory(len1);									//выделение памяти для str1
		printf("Введите строку str1: ");
		get_string(str1, len1);											//ввод str1

		printf("\nВведите размер строки str2: ");
		len2 = input_nat();												//ввод длины строки str2
		str2 = allocate_memory(len2);									//выделение памяти для str2
		printf("Введите строку str2: ");
		get_string(str2, len2);											//ввод str2

		str = replace(str, str1, str2);									//вызов функции замены всех вхождений подстроки str1 на str2
		printf("%s", str);												//вывод строки

		free(str);														//освобождение памяти
		free(str1);
		free(str2);

		do
		{
			printf_s("\nПродолжить? (y - да / n - нет): ");									//запрос на продолжение программы
			rewind(stdin);																	//очистка буфера для корректного ввода символа
			exit = getchar();																//получение символа
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');
	
	return 0;
}