#include "header.h"																//����� � ����������� ������� � ������������ ������������

int input_nat()																	//������� ����� ������������ �����
{
	int n = 0;																	//����������� �������
	int k = 1;																	//��������������� ���������� ��� �������� �� ���� ������ �����

	do																			//���� ����������� ������� � ��������� �� ����� �����
	{
		rewind(stdin);															//������� ������
		k = scanf_s("%d", &n);

		if (!k || n <= 0)
			printf("������ ���� ������� ����������� �����!\n");
	} while (!k || n <= 0);														//���� ������� �� ����� �����, ���� �����������

	return n;
}

cube* allocate_memory(int n)													//������� ��������� ������ ��� ������� �������� (�����)
{
	int i = 0;
	cube* array;																//������ �����

	array = (cube*)calloc(n, sizeof(cube));
	if (!array)																	//���� ������ �� ���� ��������
	{
		printf("������ �� ���� ��������!");
		return 0;
	}

	return array;																//������� ������� ��������
}

int** allocate_memory_int(int n, int m)											//������� ��������� ������ ��� ������� ��������� �����
{
	int** array,
		  i = 0;

	array = (int**)calloc(n, sizeof(int*));										//��������� ������
	if (!array) return 0;

	for (i = 0; i < n; i++)
	{
		*(array + i) = (int*)calloc(m, sizeof(int));
		if (!*(array + i)) return 0;
	}

	return array;
}

char** allocate_memory_char(int k)												//������� ��������� ������ ��� ������� �����
{
	char** array;
	int i = 0;

	array = (char**)calloc(k, sizeof(char*));
	if (!array) return nullptr;													//���� ������ �� ����������

	for (i = 0; i < k; i++)														//��������� ������ ��� i-��� ������
	{
		*(array + i) = (char*)calloc(50, sizeof(char));
	}

	return array;
}

cube* reallocate_memory(cube* array, int k)										//������� ������������� ������
{
	cube* temp;																	//��������� ������

	temp = (cube*)realloc(array, k * sizeof(cube));								
	if (temp) array = temp;

	return array;
}

void get_string(char* str)														//������� ����� ������
{
	int i = 0;

	if (str)
	{
		rewind(stdin);															//������� ������
		while (i < 50)
		{
			*(str + i) = getchar();												//���� ���������� �������
			if (*(str + i) == '\n')												//���� ���� ������ ������� �������� �������� Enter, �� ���� �����������
				break;
			i++;
		}
		*(str + i) = '\0';														//���������� ����-������� � ����� ������
	}
}

int get_length(const char* str)													//������� ����������� ����� ������
{
	int i = 0;																	//������� ���-�� �������� � ������

	while (*(str + i) != '\0') i++;												//����������� �������, ���� �� ����� �������� ����-������

	return i;
}

int compare(const char* str, const char* str1)									//������� ��������� ���� �����
{
	int i = 0;

	if (get_length(str) != get_length(str1)) return 0;							//���� ����� ����� ����������, �� ���������� ������� ������������

	for (i = 0; i < get_length(str); i++)
		if (*(str + i) != *(str1 + i)) return 0;								//���� ���� �� ���� ������ �� ���������, �� ���������� ������� ������������

	return 1;																	//������� ���������� 1 ��� �������� ���������� � 0 ��� ���������
}

char* copy(char* str, int k)													//������� ����������� ������ ����� �� ������, ������� � n-�� �������
{
	#define ch *(str + k + p)													//������ ��� ��������� ���������� ����

	char* word;																	//���������� ������, ���������� �����
	int p = 0,																	//����� ���� ������
		i = 0;

	while (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ','
		&& ch != ':' && ch != ';' && ch != '\0' && ch != EOF) p++;				//���� �� �������� ���� ����������
	word = (char*)calloc(p, sizeof(char));										//��������� ������ ��� �������

	if (word)																	//���� ������ ���� ��������
	{
		for (i = 0; i < p; i++)
			*(word + i) = *(str + k + i);										//����������� ���������� �������
		*(word + i) = '\0';														//���������� ����-������� � ����� ������
	}

	return word;
}






















































void input_array(cube* array, int n)											//������� ���������� ����� ������� �����
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		(array + i)->length = input_nat();										//���� ����� ����� i-��� ����
		get_string((array + i)->colour);										//���� ����� i-��� ����
		get_string((array + i)->material);										//���� ��������� i-��� ����
	}
}

void print_array(cube* array, int n)											//������� ������ ������� ��������
{
	int i = 0;

	puts("\n================================================");					//���������� � ���� �������
	puts("================================================\n");

	printf("����� �����: | ����:      | ��������:\n\n");

	for (i = 0; i < n; i++)
		printf("%-3d ��       | %-10s | %-10s\n", (array + i) -> length, (array + i) -> colour, (array + i) -> material);	//����� ����� �����, ����� � ��������� ���������� ����

	puts("\n================================================");
	puts("================================================\n");
}

int number_of_colours(cube* cubes, int k, char** colours)						//������� �������� ���������� ������
{
	int n = 0,																	//���-�� ������
		i = 0,
		j = 0,
		flag = 0;

	while (i != k)
	{
		for (j = 0; j < n; j++)
			if(compare((cubes + i)->colour, *(colours + j))) flag = 1;			//��������, ���� ���� ��� ���� � �������
		if (!flag)																//���� ���� ���������� ���� ��� �� �������
		{
			*(colours + n) = (cubes + i)->colour;								//������ ����� � ������
			n++;																//���������� �������� ���-�� ������
		}
		i++;
		flag = 0;
	}

	return n;
}

int** cube_volume(cube* cubes, int k, char** colours, int n)					//������� �������� ���-�� ����� �� ������
{
	int** array,																//������, ���������� ���-�� ����� � ����� ����� ��� ������� �����
		i = 0,
		j = 0;

	array = allocate_memory_int(n, 2);											//��������� ������ ��� �������
	if (!array) return 0;

	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n; j++)
			if (compare((cubes + i)->colour, *(colours + j)))							
			{
				**(array + j) += 1;												//���������� �������� ���-�� ����� ������������ �����
				*(*(array + j) + 1) += pow((cubes + i)->length, 3);				//������������ ������ ���������� ���� � ����� �������
			}
	}

	return array;	
}

int cube_search(cube* cubes, cube* array, int k, char* str)						//������� ������ ����� �� ���������
{
	int i = 0,
		j = 0,
		t = 0,																	//���-�� ������� �����
		sign = 0,																
		length = 0;																//����� ������� �����
	char* search_criteria[4];													//������ ������� �������� ���� (����� �����, ����, ��������)
	int arr[4] = {0};															

	for (i = 0; i < 4; i++)														//������ ������ � ���������� ������
	{
		search_criteria[i] = copy(str, j);										//������ ���������� �������� � ������
		if (compare(search_criteria[i], "-\0"))									//���� ����� �� ����� �������� �� �����������
			arr[i] = 1;
		
		j += get_length(search_criteria[i]);									//������� ���������� �����
		while (*(str + j) == ' ') j++;											//������� �������� �� ���������� �����
	}

	if (compare(search_criteria[0], "������\0") || compare(search_criteria[0], ">\0"))				//���� ����� ����� ���� � ������ ������ ��������
		sign = 1;
	if (compare(search_criteria[0], "������\0") || compare(search_criteria[0], "<\0"))				//���� ����� ����� ���� � ������ ������ ��������
		sign = -1;
	if (compare(search_criteria[0], "�����\0") || compare(search_criteria[0], "=\0"))				//���� ����� ����� ���� � �������� ������
		sign = 0;
		
	length = atoi(search_criteria[1]);											//�������������� �������� ����� ����� �� ������ � �����

	for (i = 0; i < k; i++)
		if ((compare(search_criteria[2], (cubes + i)->colour) || arr[2]) &&		
			(compare(search_criteria[3], (cubes + i)->material) || arr[3]) &&
			((sign == 1 && (cubes + i)->length > length) || (sign == -1 && (cubes + i)->length < length) || (sign == 0 && (cubes + i)->length == length) || arr[1]))
		{
			*(array + t) = *(cubes + i);										//����������� ��������� � ����� ������ ��������
			t++;																//������� ���-�� ������� �����		
		}

	return t;
}

void result(int** array, char** colours, int n)									//������� ������ ����������
{
	int i = 0;

	puts("\n================================================");					//���������� � ���� �������
	puts("================================================\n");

	printf("����:      | ���-��: | �����:\n\n");

	for (i = 0; i < n; i++)
		printf("%-10s | %-4d    | %-5d ��^3\n", *(colours + i), **(array + i), *(*(array + i) + 1));	//����� �����, ���-�� ����� ������ �����, ����� ����� ���� �����

	puts("\n================================================");
	puts("================================================\n");
}