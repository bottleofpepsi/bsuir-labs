#include "header.h"																//����� � ����������� ������� � ������������� ������������

int main()
{
	setlocale(LC_ALL, "Russian");												//������� �����������

	char exit = '0';															//������ ��� �������� �� ����� �� ���������

	do
	{
		int* a;																	//������������ ������, ���������� �������� ������������������
		int	n = 0;																//����� ������� (���-�� ������ �������� ������������������)

		system("cls");															//������� �������

		printf("������� ���-�� n (n - ����������� �����) ������ �������� ������������������: ");
		n = input_nat();														//���� ������� �������
		a = allocate_memory(n);													//��������� ������ ��� ������������� �������
		printf("������� %d �������� ������ �������� ������������������ (����� �����): ", n);
		input_array(a, n);														//���� �������� ��������� �������
		printf("\n�������� ������: ");
		print_array(a, n);

		printf("\n\n����� ������������� ������ ����� %d \n", positive(a, n));	//����� ����������
		printf("����� ������������� ������ ����� %d \n", negative(a, n));

		free(a);																//������������ ������

		do
		{
			printf_s("����������? (y - �� / n - ���): ");						//������ �� ����������� ���������
			rewind(stdin);														//������� ������ ��� ����������� ����� �������
			exit = getchar();													//��������� �������
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'y' || exit == 'Y');

	return 0;
}
