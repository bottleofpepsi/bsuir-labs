#include "oldheader.h"	

int input_nat()																	//������� ����� ������������ �����
{
	int n = 0;																	//����������� �������
	int k = 1;																	//��������������� ���������� ��� �������� �� ���� ������ �����

	do																			//���� ����������� ������� � ��������� �� ����� �����
	{
		rewind(stdin);															//������� ������
		k = scanf_s("%d", &n);

		if (!k || n < 0)
			printf("������ ���� ������� ����������� �����!\n");
	} while (!k || n < 0);														//���� ������� �� ����� �����, ���� �����������

	return n;
}

int* allocate_memory_int(int m)													//������� ��������� ������ ��� ������� ��������� �����
{
	int* array;

	array = (int*)calloc(m, sizeof(int));
	if (!array) return nullptr;

	return array;
}

int* reallocate_memory_int(int* array, int m)									//������� ������������� ������ ��� ������� ��������� �����
{
	int* tmp;

	tmp = (int*)realloc(array, m * sizeof(int));
	if (!tmp) array = tmp;

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

void get_string(char* str, int max)												//������� ����� ������
{
	if (str)
	{
		rewind(stdin);															//������� ������
		fgets(str, max, stdin);
		*(str + get_length(str)) = '\0';										//���������� ����-������� � ����� ������
	}
}

int get_length(const char* str)													//������� ����������� ����� ������
{
	int i = 0;																	//������� ���-�� �������� � ������

	while (*(str + i) != '\0' && *(str + i) != '\n') i++;						//����������� �������, ���� �� ����� �������� ����-������

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
#define ch *(str + k + p)														//������ ��� ��������� ���������� ����

	char* word;																	//���������� ������, ���������� �����
	int p = 0,																	//����� ���� ������
		i = 0;

	while (ch != ' ' && ch != '!' && ch != '?' && ch != '.' && ch != ','
		&& ch != ':' && ch != ';' && ch != '\0' && ch != '\n' && ch != EOF) p++;	//���� �� �������� ���� ����������
	word = (char*)calloc(p, sizeof(char));											//��������� ������ ��� �������

	if (word)																	//���� ������ ���� ��������
	{
		for (i = 0; i < p; i++)
			*(word + i) = *(str + k + i);										//����������� ���������� �������
		*(word + i) = '\0';														//���������� ����-������� � ����� ������
	}

	return word;
}

void sort(int* arr, int k)														//������� ���������� ������� ���������
{
	int i = 0,
		j = 0,
		temp = 0;

	for (i = 0; i < k - 1; i++)
		for (j = 0; j < k - i - 1; j++)
			if (*(arr + j) > *(arr + j + 1))
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
}