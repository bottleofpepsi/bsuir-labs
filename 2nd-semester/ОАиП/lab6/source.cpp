#include "header.h"																		//хэдеры с прототипами функций и необходимыми библиотеками
#include "oldheader.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	ring* head = nullptr;																//указатель на точку входа в кольцо

	while (1)
	{
		print_menu();																	//вывод меню на экран						

		switch (input_nat())															//выбор операции
		{
		case 1:																			//добавить группу
			printf("\nВведите фамилии студентов:\n");
			add_group(&head);
			break;
		case 2:																			//удалить группу
			if (!head) break;
			printf("\nВведите номер группы: ");
			delete_group(&head, input_nat());
			puts("Группа удалена!\n");
			break;
		case 3:																			//удалить группу с наименьшим кол-вом студентов и объединить её со следующей
			if (!head) break;
			delete_min_group(&head);
			puts("Группа удалена!\n");
			break;
		case 4:																			//добавить студента в группу
			if (!head) break;
			printf("\nВведите номер группы: ");
			add_students(head, input_nat());
			break;
		case 5:																			//удалить студента из группы
			if (!head) break;
			printf("\nВведите номер группы: ");
			delete_student(&head, input_nat());
			puts("Студент удалён!\n");
			break;
		case 6:																			//вывести на экран поток
			if (!head)
			{
				puts("Вы не добавили никаких групп!\n");
				break;
			}
			show_all(head);
			break;
		case 7:																			//вывести на экран группу
			if (!head)
			{
				puts("Вы не добавили никаких групп!\n");
				break;
			}
			printf("\nВведите номер группы: ");
			show_group(head, input_nat());
			break;
		case 8:																			//очистить таблицу групп
			if (!head) break;
			free_ring(&head);
			puts("Таблица очищена!\n");
			break;
		case 9:																			//выход из программы
			if (!head) 
				free_ring(&head);
			return 0;
		default: printf("Некорректный ввод!\n");
		}
	}

	return 0;
}