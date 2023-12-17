#include "header.h"																//хэдер с прототипами функций и необходимыми библиотеками
#include "oldheader.h"	

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int exit = 0;																//символ для проверки на выход из программы

	do
	{
		stack* head = nullptr;													//указатель на вершину стека

		char str[100] = {};														//входная строка

		int* mistake;															//массив с индексами ошибок
		int mcounter = 0;														//счётчик ошибок

		system("cls");

		get_string(str, 100);													//ввод строки

		mistake = check(str, head, &mcounter);									//проверка строки на ошибки
		if (!mcounter)
			printf("\nОшибок не найдено!\n");
		else
		{
			printf("\nНайденные ошибки:\n");
			highlight(mistake, str);											//подсветка ошибок
		}

		free_stack(head);														//очистка памяти

		do
		{
			printf_s("\nПродолжить? (y - да / n - нет): ");									//запрос на продолжение программы
			rewind(stdin);																	//очистка буфера для корректного ввода символа
			exit = getchar();																//получение символа
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');

	return 0;
}