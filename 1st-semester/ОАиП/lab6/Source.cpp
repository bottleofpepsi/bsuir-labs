#include "header.h"														//����� � ����������� ������� � ������������ ������������


int main()
{
	setlocale(LC_ALL, "Russian");

	int exit = 0;														//������ ��� �������� �� ����� �� ���������

	do
	{
		char* str,														//�������� ������
			* str1,														//���������, ������� ��������� ��������
			* str2;														//���������, �� ������� ��������� �������� str1
		int len = 0,													//����� ������ str
			len1 = 0,													//����� ������ str1
			len2 = 0;													//����� ������ str2

		system("cls");													//������� �������

		printf("������� ������ ������ str: ");
		len = input_nat();												//���� ����� ������ str
		str = allocate_memory(len);										//��������� ������ ��� str
		printf("������� ������ str: ");
		get_string(str, len);											//���� str

		printf("\n������� ������ ������ str1: ");
		len1 = input_nat();												//���� ����� ������ str1
		str1 = allocate_memory(len1);									//��������� ������ ��� str1
		printf("������� ������ str1: ");
		get_string(str1, len1);											//���� str1

		printf("\n������� ������ ������ str2: ");
		len2 = input_nat();												//���� ����� ������ str2
		str2 = allocate_memory(len2);									//��������� ������ ��� str2
		printf("������� ������ str2: ");
		get_string(str2, len2);											//���� str2

		str = replace(str, str1, str2);									//����� ������� ������ ���� ��������� ��������� str1 �� str2
		printf("%s", str);												//����� ������

		free(str);														//������������ ������
		free(str1);
		free(str2);

		do
		{
			printf_s("\n����������? (y - �� / n - ���): ");									//������ �� ����������� ���������
			rewind(stdin);																	//������� ������ ��� ����������� ����� �������
			exit = getchar();																//��������� �������
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');
	
	return 0;
}