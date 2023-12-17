#include "header.h"
#include "oldheader.h"

ring* allocate_ring_memory()													//функция выделения памяти для элемента кольца
{
	ring* r;

	r = (ring*)calloc(1, sizeof(ring));
	if (!r) return 0;

	return r;
}

stack* allocate_stack_memory()													//функция выделения памяти для элемента стека
{
	stack* st;

	st = (stack*)calloc(1, sizeof(stack));

	if (!st) return 0;
	return st;
}

void push(stack** st, char* str)												//функция добавления элемента в стек
{
	stack* st1 = *st;															//сохранение верхнего элемента стека

	*st = allocate_stack_memory();												//выделение памяти для нового элемента
	if (!*st) return;

	strcpy_s((*st)->lastname, str);												//заполнение полей нового элемента

	(*st)->next = st1;															//перемещение указателя на вершину стека на новый элемент
	st1 = *st;
}

char* pop(stack** st)															//функция удаления последнего элемента из стека
{
	if (!*st) return nullptr;

	stack* st1;
	char ps[30] = {};

	st1 = *st;																	

	strcpy_s(ps, (*st)->lastname);												//сохранение значения удаляемого элемента

	*st = (*st)->next;															//перемещение указателя на вершину стека на следующий элемент
	free(st1);																	//очистка памяти удаляемого эл-та

	return ps;
}

void free_stack(stack* st)														//функция очистки стека
{
	while (st)																	//пока в стеке есть элементы, удалять их
		pop(&st);
}

int input_stack(stack** st)														//функция ввода информации в стек
{
	char str[30] = {};															
	int i = 0;																	

	while (1)
	{
		get_string(str, 30);													//ввод строки, содержащей фамилию очередного студента
		if (compare(str, "\0")) break;											//если встречена пустая строка, прервать ввод
		push(st, str);															//занесение нового элемента в стек
		i++;
	}

	return i;																	//кол-во занесённых элементов
}

ring* get_ptr(ring* head, int n)												//функция получения указателя на n-ый элемент кольца
{
	if (!head) return nullptr;

	while (n-- > 1)
		head = head->next;

	return head;
}

void add_group(ring** head)														//функция создания элемента кольца
{
	ring *r1,
		 *r2;

	if (!*head)																	//если это первый элементт кольца
	{
		r1 = allocate_ring_memory();											//выделение памяти
		r1->next = r1;															//замыкаем элемент сам на себя
		r1->count = input_stack(&(r1->group));									//заполнение стека
		*head = r1;
	}
	else																		//иначе
	{
		r1 = *head;
		while (r1->next != *head) r1 = r1->next;								//перемещение к элементу, находящемуся перед начальным
		r2 = allocate_ring_memory();											//выделение памяти
		r1->next = r2;
		r2->next = *head;
		r2->count = input_stack(&(r2->group));									//заполнение стека
	}
}

void delete_group(ring** head, int n)											//функция удаления элемента кольца
{
	if (!*head) return;

	ring* node = get_ptr(*head, n),
		* r1 = node->next;

	free_stack(node->group);													//очистка содержимого удаляемого элемента

	if (node->next == node)														//если удаляемый элемент — единственный в кольце
	{
		free(node);																//очистка памяти
		*head = nullptr;
		return;
	}
	if (node == *head) *head = (*head)->next;									//если удаляемый элемент — точка входа в кольцо, перемещаем точку входа на следующий

	while (r1->next != node) r1 = r1->next;										//удаление элемента
	r1->next = node->next;
	free(node);																	//очистка памяти
}

void free_ring(ring** head)														//функция очистки кольца
{
	while (*head)																//пока в кольце есть элементы, удалять их
		delete_group(head, 1);
}

ring* delete_min_group(ring** head)												//функция удаления элемента кольца с наименьшим кол-вом студентов и объединения со следующим
{
	if (!head) return 0;
	
	ring* r1 = *head,
		* node = r1;
	int k = 0;

	if (r1->next == r1)															//если в кольце только один элемент
		return 0;

	k = r1->count;
	node = r1;
	do
	{
		if (k > r1->count)														//если кол-во студентов в данной группе меньше, чем в предудущих
		{
			k = r1->count;														
			node = r1;															//фиксируем элемент кольца с наименьшим кол-вом элементов в стеке
		}
		r1 = r1->next;															//переход к следующему элементу
	} while (r1 != *head);														//обход кольца один раз

	if (node == *head) *head = (*head)->next;									//если удаляемый элемент — точка входа в кольцо, перемещаем точку входа на следующий

	while (node->group)															//перемещение элементов в соседний стек
	{
		push(&(node->next->group), pop(&(node->group)));						//удаление элемента из текущего стека и занесение информации в следующий стек
		node->next->count++;
	}

	r1 = node->next;															//удаление элемента
	while (r1->next != node) r1 = r1->next;
	r1->next = node->next;		

	free(node);																	//очистка памяти

	return *head;
}

void add_students(ring *head, int n)											//функция добавления элемента в стек n-ого кольца
{
	ring* node = get_ptr(head, n);

	node->count += input_stack(&(node->group));									//занесение информации в стек и увеличение счётчика кол-ва студентов
}

void delete_student(ring** head, int n)											//функция удаления элемента стека n-ого кольца
{
	if (!*head) return;
	
	ring* r1 = get_ptr(*head, n);
	stack* st1 = r1->group,
		 * st2;
	char str[30] = {};

	get_string(str, 30);														//ввод фамилии удаляемого студента

	if (compare(st1->lastname, str))
	{
		pop(&st1);
		r1->group = st1;
		r1->count--;															//уменьшение счётчика кол-ва студентов в группе
	}
	else
		while (st1->next)
		{
			if (compare(st1->next->lastname, str))
			{
				st2 = st1->next;
				st1->next = st2->next;											//удаление элемента 
				r1->count--;													//уменьшение счётчика кол-ва студентов в группе

				free(st2);														//очистка памяти
				break;
			}
			st1 = st1->next;
		}

	if (r1->count <= 0) delete_group(head, n);									//если был удалён последний элемент стека, удалить элемент кольца
}

void show_all(ring* head)														//функция вывода информации всех элементов кольца
{
	if (!head) return;

	ring* r1 = head;
	int i = 0;

	puts("");
	do																			//вывод информации очередного элемента
	{
		i++;
		show_group(head, i);
		r1 = r1->next;
	} while (r1 != head);
}

void show_group(ring* head, int n)												//функция вывода информации одного элемента кольца на экран
{
	if (!head) return;

	ring* r1 = get_ptr(head, n);
	stack* st1 = r1->group;

	puts("===========");
	printf("Группа №%d\n", n);
	puts("===========");
	while (st1)																	//пока стек не закончится
	{
		puts(st1->lastname);
		st1 = st1->next;														//перейти к следующему элементу
	}
	printf("\nСтудентов в группе: %d\n", r1->count);
	puts("");
}

void print_menu()																//функция вывода меню на экран
{
	printf("Меню:\n");
	printf("1 — Добавить группу\n");
	printf("2 — Удалить группу\n");
	printf("3 — Удалить группу с наименьшим кол-вом студентов и объединить её со следующей\n");
	printf("4 — Добавить студентов в группу\n");
	printf("5 — Удалить студента из группы\n");
	printf("6 — Информация о потоке\n");
	printf("7 — Информация о группе\n");
	printf("8 — Очистить таблицу\n");
	printf("9 — Выход\n\n");
	printf("Ввод: ");
}