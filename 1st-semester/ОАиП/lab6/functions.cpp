#include "header.h"																	//����� � ����������� ������� � ������������ ������������

int input_nat()																		//������� ����� ������������ �����
{
	int n = 0;																		//����������� �������
	int k = 1;																		//��������������� ���������� ��� �������� �� ���� ������ �����

	do																				//���� ����������� ������� � ��������� �� ����� �����
	{
		rewind(stdin);																//������� ������
		k = scanf_s("%d", &n);

		if (!k || n <= 0)
			printf("������ ���� ������� ����������� �����!\n");
	} while (!k || n <= 0);															//���� ������� �� ����� �����, ���� �����������

	return n;
}

char* allocate_memory(int n)														//������� ��������� ������
{
	char* a;

	a = (char*)calloc(n + 1, sizeof(char));											//��������� ������ ��� n �������� � 1 ��� ����-�������
	if (!a)																			//��������, ���� �� �������� ������
	{
		printf("������ �� ���� ��������!");
		return 0;
	}

	return a;
}

void get_string(char* a, int n)														//������� ����� ������
{
	int i = 0;

	if (a)
	{
		rewind(stdin);																//������� ������
		while (i < n)
		{
			*(a + i) = getchar();													//���� ���������� �������
			if (*(a + i) == '\n')													//���� ���� ������ ������� �������� �������� Enter, �� ���� �����������
				break;
			i++;
		}
		*(a + i) = '\0';															//���������� ����-������� � ����� ������
	}
}

char* replace(char* str, char* str1, char* str2)									//������� ������ ���� ��������� ��������� str1 �� str2 � ������ str
{
	int i = 0,																		//�������� ������
		j = 0,
		k = 0;
	char* temp;																		//������, � ������� �������� ������ ����� ������������� ������

	if (str)
	{
		while(i < get_length(str) - get_length(str1) + 1)							
		{
			if (*(str + i) == *str1)												//���� � ������ str ����������� ������ ������ ��������� str1
				if (compare(str, str1, i))											//���� ������ ��������� ���������
				{
					for (j = 0; j < get_length(str1); j++)							//�������� ��������� str1 � ������ str
						for (k = i; k < get_length(str); k++)
							*(str + k) = *(str + k + 1);

					temp = (char*)realloc(str, sizeof(char) * (get_length(str) + get_length(str2) + 1));	//������������� ������
					if (temp) str = temp;																	//��������, ������� �� ���� ������������ ������

					for (j = get_length(str2); j > 0; j--)							//������� ��������� str2 � ������ str
					{
						for (k = get_length(str) + 1; k > i; k--)					//����� ������, ������� � i-�� �������
							*(str + k) = *(str + k - 1);
						*(str + i) = *(str2 + j - 1);								//������� ���������� �������
					}

					i += get_length(str2) - get_length(str1) + 1;					//���������� ������� ��������� �������� � ������ str � ������ ��������� � �����
				}
			i++;																	//������� � ���������� �������
		}
	}
	return str;
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

int compare(char* str, char* str1, int k)											//������� ��������, �������� �� str1 ���������� ������ str, ������� � k-�� �������
{
	int i = 0;

	for (i = 0; i < get_length(str1); i++)
		if (*(str + k + i) != *(str1 + i)) return 0;								//���� ���� �� ���� ������ �� ���������, �� ���������� ������� ������������

	return 1;																		//������� ���������� 1 ��� �������� ���������� � 0 ��� ���������
}

int get_length(char* str)															//������� ����������� ����� ������
{
	int i = 0;																		//������� ���-�� �������� � ������

	while (*(str + i) != '\0') i++;													//����������� �������, ���� �� ����� �������� ����-������

	return i;
}