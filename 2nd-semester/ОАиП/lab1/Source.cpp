#include "header.h"																	//����� � ����������� ������� � ������������ ������������


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int exit = 0;																	//������ ��� �������� �� ����� �� ���������

	system("cls");

	cube* array;																	//������ �����
	cube* array_new;																//������ ������� �����
	char** colours;																	//������ ������

	char str[50] = {};																//������ ��� ����� ��������� ������

	int k = 0,																		//���-�� �����
		k1 = 0,																		//���-�� ������� �����
		n = 0,																		//���-�� ������
		select = 0;

	printf("������� ���������� �����: ");
	k = input_nat();																//���� ���-�� �����
	array = allocate_memory(k);														//��������� ������ ��� ������� �����

	if (array)																		//���� ������ ���� ��������
	{
		printf("\n������� ������ � ����� (����� �����, ����, ��������):\n");
		input_array(array, k);														//���������� ����� ������� �����
		print_array(array, k);														//����� ������� ������ �� �����
	}

	do
	{
		printf("����: \n1 � ��������� ����� ����� ������� ����� \n2 � ����� ����� �� �������� ���������\n");
		select = input_nat();														//����� ��������

		switch (select)
		{
			case 1:																	//���������� ������ ������ ����� ������� �����	
			{
				colours = allocate_memory_char(k);									//��������� ������ ��� ������� ������
				n = number_of_colours(array, k, colours); 
				result(cube_volume(array, k, colours, n), colours, n);

				free(colours);														//������� ������
				break;									
			}
			case 2:																	//����� ����� �� �������� ���������
			{
				array_new = allocate_memory(k);										//��������� ������ ��� ������� ������� �����
				printf("\n����� ���� �� ������ �����? (����� �����, ����, ��������)\n");
				get_string(str);													//���� ���������
				k1 = cube_search(array, array_new, k, str);							//����� ����� �� �������� ���������
				if (k1)																
				{
					array_new = reallocate_memory(array_new, k1);					//������������� ������ � ������ ��������� �������� ��������
					print_array(array_new, k1);										//����� ����������		
					printf("���-�� ����� �����: %d\n", k1);
				}
				else
					printf("����� ���� �� �������!\n");

				free(array_new);													//������� ������
				break;
			}
			default: printf("������������ ����!\n");
		}
		do
		{
			printf_s("\n���������? (y - �� / n - ���): ");							//������ �� ����������� ���������
			rewind(stdin);															//������� ������ ��� ����������� ����� �������
			exit = getchar();														//��������� �������
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');

	free(array);																	//������� ������

	return 0;
}