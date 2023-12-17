#include "matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int m = 0,
		n = 0;
	char exit = 0;																	//символ для проверки на выход из программы

	do
	{
		system("cls");

		cout << "Введите размеры 1-ой матрицы:" << endl;							//ввод размеров матриц
		cin >> m >> n;
		matrix mat1(m, n);															//инициализация 1-ой матрицы																		

		cout << "Введите размеры 2-ой матрицы:" << endl;							
		cin >> m >> n;
		matrix mat2(m, n);															//инициализация 2-ой матрицы

		if (mat1.exeption(mat2))													//проверка матриц на совместимость									
		{
			cout << "Введите содержимое 1-ой матрицы:" << endl;						//ввод			
			mat1.input();
			cout << "Введите содержимое 2-ой матрицы:" << endl;
			mat2.input();

			matrix res = mat1 * mat2;												//умножение матриц

			cout << endl << "Результат умножения матриц:" << endl;					//вывод
			res.output();	
		} 

		do
		{
			cout << "\nПродолжить? (y - да / n - нет): ";							//запрос на продолжение программы
			cin >> exit;															//получение символа
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');
}
