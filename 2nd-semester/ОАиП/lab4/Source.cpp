#include "header.h"																	//����� � ����������� ������� � ������������ ������������


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	cube* array = nullptr;																//������ �����
	cube* array_new;																	//������ ������� �����
	char** colours;																		//������ ������

	char str[50] = {};																	//������ ��� ����� ��������� ������
	char name[] = "binary.bin";															//��� �����

	int k = 0,																			//���-�� �����
		k1 = 0,																			//���-�� ������� �����
		n = 0,																			//���-�� ������
		select = 0;

	while (1)
	{
		printf("����: \n1 � ���� ������ � ���������� \n2 � ������ � ��������� ����");		
		printf("\n3 � �������� � ��������� ���� \n4 � ������ � �������� ����");
		printf("\n5 � �������� � �������� ���� \n6 � ������ �� ��������� �����");
		printf("\n7 � ���������� ������ ����� \n8 � ����� ����� �� ���������\n9 � �����\n");

		printf("\n����: ");
		select = input_nat();															//����� ��������
		switch (select)
		{
		case 1:																			//���� ������ � ����������
			printf("\n������� ���������� �����: ");
			k = input_nat();															//���� ���-�� �����
			array = allocate_memory(k);													//��������� ������ ��� ������� �����

			if (array)																	//���� ������ ���� ��������
			{
				printf("\n������� ������ � ����� (����� �����, ����, ��������):\n");
				input_array(array, k);													//���������� ����� ������� �����
				print_array(array, k);													//����� ������� ������ �� �����
			}
			break;
		case 2:																			//������ ������ � ��������� ����
			if (!array)
			{
				printf("������� ������ �����!\n\n");
				break;
			}
			txt_output(array, k, 0);													//����� ������� ������ ��������� � ��������� ����
			break;
		case 3:																			//�������� ������ � ��������� ����
			if (!array)
			{
				printf("������� ������ �����!\n\n");
				break;
			}
			txt_output(array, k, 1);													//����� ������� �������� ��������� � ��������� ����
			break;
		case 4:																			//������ ������ � �������� ����
			if (!array)
			{
				printf("������� ������ �����!\n\n");
				break;
			}
			bin_output(array, k, name, 0);												//����� ������� ������ ��������� � �������� ����
			break;
		case 5:																			//�������� ������ � �������� ����
			if (!array)
			{
				printf("������� ������ �����!\n\n");
				break;
			}
			bin_output(array, k, name, 1);												//����� ������� �������� �������� � �������� ����
			break;
		case 6:																			//������ ������ �� ��������� �����
			array = bin_input(&k, name);												//����� ������� ������ �������� �� �������� ����
			print_array(array, k);														//����� ��������� �� �����
			break;
		case 7:																			//���������� ������ ������ ����� ������� �����	
			colours = allocate_memory_char(k);											//��������� ������ ��� ������� ������
			n = number_of_colours(array, k, colours);
			result(cube_volume(array, k, colours, n), colours, n);

			free(colours);																//������� ������
			break;
		case 8:																			//����� ����� �� �������� ���������
			array_new = allocate_memory(k);												//��������� ������ ��� ������� ������� �����
			printf("\n����� ���� �� ������ �����? (����� �����, ����, ��������)\n");

			rewind(stdin);																//������� ������
			fgets(str, 50, stdin);														//���� ���������
			k1 = cube_search(array, array_new, k, str);									//����� ����� �� �������� ���������
			if (k1)
			{
				array_new = reallocate_memory(array_new, k1);							//������������� ������ � ������ ��������� �������� ��������
				print_array(array_new, k1);												//����� ����������		
				printf("���-�� ����� �����: %d\n", k1);
			}
			else
				printf("����� ���� �� �������!\n");

			free(array_new);															//������� ������
			break;
		case 9:
			if (array)
				free(array);															//������� ������
			return 0;
		default: printf("������������ ����!\n");
		}
	}

	return 0;
}