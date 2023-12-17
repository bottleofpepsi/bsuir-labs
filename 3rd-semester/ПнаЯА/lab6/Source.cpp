#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

#define N 10
float array[N];

void input();
void output();
//extern "C" void inlineAsm(int n, float* array);
void inlineAsm();

int main(void) 
{
	setlocale(LC_ALL, "Russian");

	printf("Введите 10 элементов массива: \n");
	input();

	printf("\nМассив: \n");
	output();

	inlineAsm();

	printf("\nПреобразованный массив: \n");
	output();

	return 0;
}

void input() 
{
	int flag;

	for (int i = 0; i < N; ++i) 
	{
		do 
		{
			rewind(stdin);
			flag = scanf_s("%f", &array[i]);
			if (flag != 1) printf("Должно быть введено число!\n");
		} while (flag != 1);
	}
}

void output() 
{
	for (int i = 0; i < N; ++i) 
	{
		printf("%.3f ", array[i]);
	}
	printf("\n");
}

void inlineAsm() 
{
	__asm 
	{
			finit									

			mov ecx, N
			lea ebx, array					

			fldz										

		Calculate_loop:
			fld [ebx]							
			fcom
			fstsw ax
			sahf
			ja Greater

		Less:										
			fmul [ebx]
			fstp [ebx]
			jmp End
		
		Greater:									
			fmul [ebx]
			fmul [ebx]
			fstp [ebx]

		End:										
			add ebx, 4								
			loop Calculate_loop

			fwait 
	}
}