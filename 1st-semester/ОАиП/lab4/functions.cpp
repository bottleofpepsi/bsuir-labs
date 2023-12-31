#include "header.h"											//���������� ������ � ������������ ������������	

int input_nat()												//������� ����� ����������� �������
{
	int n = 0;												//����������� �������
	int k = 1;												//��������������� ���������� ��� �������� �� ���� ������ �����

	do														//���� ����������� ������� � ��������� �� ����� �����
	{
		rewind(stdin);										//������� ������
		k = scanf_s("%d", &n);								

		if (!k || n <= 0) 
			printf("������ ���� ������� ����������� �����!\n");
	} while (!k || n <= 0);									//���� ������� �� ����� �����, ���� �����������
	printf("\n");

	return n;
}

int** allocate_memory(int n)								//������� ��������� ������ ��� ���������� ������������� ������� �������� n
{
	int** a;

	a = (int**)malloc(n * sizeof(int*));					//��������� ������ ��� ���������� �������
	if (a)
	{
		for (int i = 0; i < n; i++)
			*(a + i) = (int*)malloc(n * sizeof(int));		//��������� ������ ��� ���������� ��������
	}

	return a;												//������� ������� � ���������� �������
}

void spiral(int** a, int n)									//������� ���������� ������� �� �������
{

	int i = 0,												//������� ����� 
		x = 0,												//����� ������� �������
		y = -1,												//����� ������ �������
		num = 0,											//��������� �����, ����������� �������
		dir = 1,											//����������� �������� ������ ������� (������ � ���� ��� ����� � �����)
		l = 0;												//���������� �� ������� ������� (��� ��� ������������ ��������)

	l = n;													//�������������� ���������� ����� ����� ������� �������
	while (l > 0)											//���� ����������� �� ��� ���, ���� ���������� �� ��� ������������ �������� �� ����� ����� 0
	{
		i = 0;
		while (i != l)										//�������� ������ (����� ����� ��������� �����������)
		{	
			y += dir;										//����������� �� ���� ������� ������ (�����)
			*(*(a + x) + y) = ++num;						//������������ �������� ������� �������� ���������� ����� 
			i++;
		}

		l--;												//���������� ���������� �� ��� ������������ ��������

		i = 0;
		while (i != l)										//�������� ���� (����� ����� ��������� �����������)
		{
			x += dir;										//����������� �� ���� ������� ���� (�����)
			*(*(a + x) + y) = ++num;						//������������ ��-�� ������� �������� ���������� ����� 
			i++;
		}

		dir *= -1;											//��������� �����������
	}
}

void print_array(int** a, int n)							//������� ������ ���������� ������������� ������� �������� n
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d ", *(*(a + i) + j));				//����� a[i,j] 
		printf("\n");										//������� �� ����� ������
	}
}