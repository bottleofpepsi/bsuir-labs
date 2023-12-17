#include "header.h"
#include "oldheader.h"

ring* allocate_ring_memory()													//������� ��������� ������ ��� �������� ������
{
	ring* r;

	r = (ring*)calloc(1, sizeof(ring));
	if (!r) return 0;

	return r;
}

stack* allocate_stack_memory()													//������� ��������� ������ ��� �������� �����
{
	stack* st;

	st = (stack*)calloc(1, sizeof(stack));

	if (!st) return 0;
	return st;
}

void push(stack** st, char* str)												//������� ���������� �������� � ����
{
	stack* st1 = *st;															//���������� �������� �������� �����

	*st = allocate_stack_memory();												//��������� ������ ��� ������ ��������
	if (!*st) return;

	strcpy_s((*st)->lastname, str);												//���������� ����� ������ ��������

	(*st)->next = st1;															//����������� ��������� �� ������� ����� �� ����� �������
	st1 = *st;
}

char* pop(stack** st)															//������� �������� ���������� �������� �� �����
{
	if (!*st) return nullptr;

	stack* st1;
	char ps[30] = {};

	st1 = *st;																	

	strcpy_s(ps, (*st)->lastname);												//���������� �������� ���������� ��������

	*st = (*st)->next;															//����������� ��������� �� ������� ����� �� ��������� �������
	free(st1);																	//������� ������ ���������� ��-��

	return ps;
}

void free_stack(stack* st)														//������� ������� �����
{
	while (st)																	//���� � ����� ���� ��������, ������� ��
		pop(&st);
}

int input_stack(stack** st)														//������� ����� ���������� � ����
{
	char str[30] = {};															
	int i = 0;																	

	while (1)
	{
		get_string(str, 30);													//���� ������, ���������� ������� ���������� ��������
		if (compare(str, "\0")) break;											//���� ��������� ������ ������, �������� ����
		push(st, str);															//��������� ������ �������� � ����
		i++;
	}

	return i;																	//���-�� ��������� ���������
}

ring* get_ptr(ring* head, int n)												//������� ��������� ��������� �� n-�� ������� ������
{
	if (!head) return nullptr;

	while (n-- > 1)
		head = head->next;

	return head;
}

void add_group(ring** head)														//������� �������� �������� ������
{
	ring *r1,
		 *r2;

	if (!*head)																	//���� ��� ������ �������� ������
	{
		r1 = allocate_ring_memory();											//��������� ������
		r1->next = r1;															//�������� ������� ��� �� ����
		r1->count = input_stack(&(r1->group));									//���������� �����
		*head = r1;
	}
	else																		//�����
	{
		r1 = *head;
		while (r1->next != *head) r1 = r1->next;								//����������� � ��������, ������������ ����� ���������
		r2 = allocate_ring_memory();											//��������� ������
		r1->next = r2;
		r2->next = *head;
		r2->count = input_stack(&(r2->group));									//���������� �����
	}
}

void delete_group(ring** head, int n)											//������� �������� �������� ������
{
	if (!*head) return;

	ring* node = get_ptr(*head, n),
		* r1 = node->next;

	free_stack(node->group);													//������� ����������� ���������� ��������

	if (node->next == node)														//���� ��������� ������� � ������������ � ������
	{
		free(node);																//������� ������
		*head = nullptr;
		return;
	}
	if (node == *head) *head = (*head)->next;									//���� ��������� ������� � ����� ����� � ������, ���������� ����� ����� �� ���������

	while (r1->next != node) r1 = r1->next;										//�������� ��������
	r1->next = node->next;
	free(node);																	//������� ������
}

void free_ring(ring** head)														//������� ������� ������
{
	while (*head)																//���� � ������ ���� ��������, ������� ��
		delete_group(head, 1);
}

ring* delete_min_group(ring** head)												//������� �������� �������� ������ � ���������� ���-��� ��������� � ����������� �� ���������
{
	if (!head) return 0;
	
	ring* r1 = *head,
		* node = r1;
	int k = 0;

	if (r1->next == r1)															//���� � ������ ������ ���� �������
		return 0;

	k = r1->count;
	node = r1;
	do
	{
		if (k > r1->count)														//���� ���-�� ��������� � ������ ������ ������, ��� � ����������
		{
			k = r1->count;														
			node = r1;															//��������� ������� ������ � ���������� ���-��� ��������� � �����
		}
		r1 = r1->next;															//������� � ���������� ��������
	} while (r1 != *head);														//����� ������ ���� ���

	if (node == *head) *head = (*head)->next;									//���� ��������� ������� � ����� ����� � ������, ���������� ����� ����� �� ���������

	while (node->group)															//����������� ��������� � �������� ����
	{
		push(&(node->next->group), pop(&(node->group)));						//�������� �������� �� �������� ����� � ��������� ���������� � ��������� ����
		node->next->count++;
	}

	r1 = node->next;															//�������� ��������
	while (r1->next != node) r1 = r1->next;
	r1->next = node->next;		

	free(node);																	//������� ������

	return *head;
}

void add_students(ring *head, int n)											//������� ���������� �������� � ���� n-��� ������
{
	ring* node = get_ptr(head, n);

	node->count += input_stack(&(node->group));									//��������� ���������� � ���� � ���������� �������� ���-�� ���������
}

void delete_student(ring** head, int n)											//������� �������� �������� ����� n-��� ������
{
	if (!*head) return;
	
	ring* r1 = get_ptr(*head, n);
	stack* st1 = r1->group,
		 * st2;
	char str[30] = {};

	get_string(str, 30);														//���� ������� ���������� ��������

	if (compare(st1->lastname, str))
	{
		pop(&st1);
		r1->group = st1;
		r1->count--;															//���������� �������� ���-�� ��������� � ������
	}
	else
		while (st1->next)
		{
			if (compare(st1->next->lastname, str))
			{
				st2 = st1->next;
				st1->next = st2->next;											//�������� �������� 
				r1->count--;													//���������� �������� ���-�� ��������� � ������

				free(st2);														//������� ������
				break;
			}
			st1 = st1->next;
		}

	if (r1->count <= 0) delete_group(head, n);									//���� ��� ����� ��������� ������� �����, ������� ������� ������
}

void show_all(ring* head)														//������� ������ ���������� ���� ��������� ������
{
	if (!head) return;

	ring* r1 = head;
	int i = 0;

	puts("");
	do																			//����� ���������� ���������� ��������
	{
		i++;
		show_group(head, i);
		r1 = r1->next;
	} while (r1 != head);
}

void show_group(ring* head, int n)												//������� ������ ���������� ������ �������� ������ �� �����
{
	if (!head) return;

	ring* r1 = get_ptr(head, n);
	stack* st1 = r1->group;

	puts("===========");
	printf("������ �%d\n", n);
	puts("===========");
	while (st1)																	//���� ���� �� ����������
	{
		puts(st1->lastname);
		st1 = st1->next;														//������� � ���������� ��������
	}
	printf("\n��������� � ������: %d\n", r1->count);
	puts("");
}

void print_menu()																//������� ������ ���� �� �����
{
	printf("����:\n");
	printf("1 � �������� ������\n");
	printf("2 � ������� ������\n");
	printf("3 � ������� ������ � ���������� ���-��� ��������� � ���������� � �� ���������\n");
	printf("4 � �������� ��������� � ������\n");
	printf("5 � ������� �������� �� ������\n");
	printf("6 � ���������� � ������\n");
	printf("7 � ���������� � ������\n");
	printf("8 � �������� �������\n");
	printf("9 � �����\n\n");
	printf("����: ");
}