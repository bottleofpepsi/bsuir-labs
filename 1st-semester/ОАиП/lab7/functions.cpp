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

char** allocate_memory(int n)													//������� ��������� ������ ��� ������� ���������� �����
{
	char** text;
	int i = 0;

	text = (char**)calloc(n, sizeof(char*));									//��������� ������ ��� n �����
	if (!text)																	//��������, ���� �� �������� ������
	{
		printf("������ �� ���� ��������!");
		return 0;
	}

	for (i = 0; i < n; i++)
		*(text + i) = (char*)calloc(500, sizeof(char));							//��������� ������ ��� ������ ������

	return text;
}

int* allocate_memory_int(int n)													//������� ��������� ������ ��� ������� ����� �����
{
	int* a;
	
	a = (int*)calloc(n, sizeof(int));											//��������� ������ ��� n �����
	if (!a)																		//��������, ���� �� �������� ������
	{
		printf("������ �� ���� ��������!");
		return 0;
	}

	return a;
}

void get_string(char* str)														//������� ����� ������
{
	int i = 0;

	if (str)
	{
		rewind(stdin);															//������� ������
		while (i < 500)
		{
			*(str + i) = getchar();												//���� ���������� �������
			if (*(str + i) == '\n')												//���� ���� ������ ������� �������� �������� Enter, �� ���� �����������
				break;
			i++;
		}
		*(str + i) = '\0';														//���������� ����-������� � ����� ������
	}
}

void get_text(char** text, int n)												//������� ��������� ����� ������
{
	int i = 0;
	for (i = 0; i < n; i++)
		get_string(*(text + i));												//���� ��������� ������

	*(*(text + n - 1) + get_length(*(text + n - 1))) = EOF;						//���������� ������� "����� �����" � ����� ������
}

int number_of_words(char** text)												//������� ���������� ���-�� ���� � ������
{
	int count = 0,																//������� ����
		i = 0,
		j = 0;

	while (*(*(text + i) + j) != EOF)											//���� �� ��������� ����� ������
	{
		if (*(*(text + i) + j) == '\0')											//���� �������� ����-������, �� ��������� � ��������� ������
		{
			if (**(text + i) != ' ') count++;									//���� ������ �� ���������� � �������, �� ��������� ������ �����
			i++; 
			j = 0;
			continue;
		}

		if (*(*(text + i) + j) == ' ' && *(*(text + i) + j + 1) != ' ') count++;	//���� ����� ������� ��������� �����, �� ����������� ������� ����
		j++;
	}
	if (**(text + i) != ' ') count++;

	return count;
}

int get_length(char* str)														//������� ����������� ����� ������
{
	int i = 0;																	//������� ���-�� �������� � ������

	while (*(str + i) != '\0') i++;												//����������� �������, ���� �� ����� �������� ����-������

	return i;
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

int compare(char* str, char* str1)												//������� ��������� ���� �����
{
	int i = 0;

	if (get_length(str) != get_length(str1)) return 0;							//���� ����� ����� ����������, �� ���������� ������� ������������

	for (i = 0; i < get_length(str); i++)
		if (*(str + i) != *(str1 + i)) return 0;								//���� ���� �� ���� ������ �� ���������, �� ���������� ������� ������������

	return 1;																	//������� ���������� 1 ��� �������� ���������� � 0 ��� ���������
}


void find(char** text, char** words, int* array)								//������� ���������� ������������� ����
{
	#define c *(*(text + i) + j)												//������ ��� ��������� ���������� ����

	char* temp;																	//������-�����

	int i = 0,	
		j = 0,
		k = 0,
		p = 0,
		flag = 0;																//���������� ��� �������� �� ���������� �����

	temp = (char*)calloc(500, sizeof(char));

	while (*(*(text + i) + j) != EOF)											//���� �� ��������� ����� ������
	{
		while (c == ' ' || c == '!' || c == '?' || c == '.' || c == ',' || c == ':' || c == ';') j++;		//���� ��������� ������ � ���� ����������, �� 
		if (*(*(text + i) + j) == '\0')																		//���� �������� ����-������, �� ��������� � ��������� ������
		{
			i++;
			j = 0;
			continue;
		}
		if (*(*(text + i) + j) >= 65 && *(*(text + i) + j) <= 90) *(*(text + i) + j) += 32;					//���������� �������� ���� � ������� ��������
		
		temp = copy(*(text + i), j);											//����������� ������, ���������� �����, � �����

		for (p = 0; p < k; p++)													//��������� ���������� ����� � ��� ���������� � ������ ����
		{
			flag = compare(*(words + p), temp);									
			if (flag)															//���� ����� ����� ��� �������� � ������
			{
				*(array + p) += 1;												//������� ���������� ����� �������������
				break;
			}
		}
		if (!flag)																//���� ����� ����� ��� �� �������� � ������
		{
			*(words + k) = temp;												//��������� ����� � ������ �� ������
			*(array + k) += 1;													//������� ���������� ����� �������������
			k++;
		}

		j += get_length(temp);													//������� � ����� �����
	}

	for (i = 0; i < k - 1; i++)													//���������� ���� �������� ������� "��������" �� ��������, � ����������� �� ���-�� ���������� ���� � ������
		for (j = 0; j < k - i - 1; j++)
			if (*(array + j) <= *(array + j + 1))
			{
				p = *(array + j);												//������ ������� ��������� � �������, �������� ���-�� ���������� ����
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = p;
				temp = *(words + j);											//������ ������� ��������� � �������, �������� �����
				*(words + j) = *(words + j + 1);
				*(words + j + 1) = temp;
			}
}

void result(char** words, int* array, int n)									//������� ������ ����������
{
	int i = 0,
		p = 0;

	while (*(array + p) > 0) p++;
	if (p < n)																	//���� ���-�� ���������� ���� ������, ��� ��������, �� ������� ��� ���������� �����
	{
		for (i = 0; i < p; i++)
			printf("%10s � %d ����������\n", *(words + i), *(array + i));
		return;
	}

	for (i = 0; i < n; i++)														//����� n ������������� �������� ����� ������������� ����
		printf("%10s � %d ����������\n", *(words + i), *(array + i));
}