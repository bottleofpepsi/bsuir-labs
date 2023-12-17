#include "header.h"																		//������ � ����������� ������� � ������������ ������������
#include "oldheader.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	ring* head = nullptr;																//��������� �� ����� ����� � ������

	while (1)
	{
		print_menu();																	//����� ���� �� �����						

		switch (input_nat())															//����� ��������
		{
		case 1:																			//�������� ������
			printf("\n������� ������� ���������:\n");
			add_group(&head);
			break;
		case 2:																			//������� ������
			if (!head) break;
			printf("\n������� ����� ������: ");
			delete_group(&head, input_nat());
			puts("������ �������!\n");
			break;
		case 3:																			//������� ������ � ���������� ���-��� ��������� � ���������� � �� ���������
			if (!head) break;
			delete_min_group(&head);
			puts("������ �������!\n");
			break;
		case 4:																			//�������� �������� � ������
			if (!head) break;
			printf("\n������� ����� ������: ");
			add_students(head, input_nat());
			break;
		case 5:																			//������� �������� �� ������
			if (!head) break;
			printf("\n������� ����� ������: ");
			delete_student(&head, input_nat());
			puts("������� �����!\n");
			break;
		case 6:																			//������� �� ����� �����
			if (!head)
			{
				puts("�� �� �������� ������� �����!\n");
				break;
			}
			show_all(head);
			break;
		case 7:																			//������� �� ����� ������
			if (!head)
			{
				puts("�� �� �������� ������� �����!\n");
				break;
			}
			printf("\n������� ����� ������: ");
			show_group(head, input_nat());
			break;
		case 8:																			//�������� ������� �����
			if (!head) break;
			free_ring(&head);
			puts("������� �������!\n");
			break;
		case 9:																			//����� �� ���������
			if (!head) 
				free_ring(&head);
			return 0;
		default: printf("������������ ����!\n");
		}
	}

	return 0;
}