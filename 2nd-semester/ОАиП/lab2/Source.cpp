#include "header.h"																	//����� � ����������� ������� � ������������ ������������


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int exit = 0;																	//������ ��� �������� �� ����� �� ���������

	do
	{
		system("cls");

		shape* array;																//������ �����
		int n = 0;																	//���-�� �����
		
		printf("������� ����� ���������� �����: ");
		n = input_nat();
		array = allocate_memory(n);													//��������� ������ ��� ������� �����

		if (array)
		{
			input_array(array, n);													//���� ������ � �������
			print_array(array, n);													//����� �������� ������ � ���� �������

			for (int i = 0; i < n; i++)												//������� ������� ������ ������
				*(array + i) = area(*(array + i));
			result(array, n);														//����� ���������� � ���� �������
		}

		do
		{
			printf_s("\n����������? (y - �� / n - ���): ");							//������ �� ����������� ���������
			rewind(stdin);															//������� ������ ��� ����������� ����� �������
			exit = getchar();														//��������� �������
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');

	return 0;
}