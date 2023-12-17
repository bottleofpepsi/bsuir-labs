#include "header.h"																//����� � ����������� ������� � ������������ ������������
#include "oldheader.h"	

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int exit = 0;																//������ ��� �������� �� ����� �� ���������

	do
	{
		stack* head = nullptr;													//��������� �� ������� �����

		char str[100] = {};														//������� ������

		int* mistake;															//������ � ��������� ������
		int mcounter = 0;														//������� ������

		system("cls");

		get_string(str, 100);													//���� ������

		mistake = check(str, head, &mcounter);									//�������� ������ �� ������
		if (!mcounter)
			printf("\n������ �� �������!\n");
		else
		{
			printf("\n��������� ������:\n");
			highlight(mistake, str);											//��������� ������
		}

		free_stack(head);														//������� ������

		do
		{
			printf_s("\n����������? (y - �� / n - ���): ");									//������ �� ����������� ���������
			rewind(stdin);																	//������� ������ ��� ����������� ����� �������
			exit = getchar();																//��������� �������
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');

	return 0;
}