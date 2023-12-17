#include "String.h"

int main()
{
	system("chcp 1251");															//кодировка

	int n = 0;
	char exit = 0;																	//символ для проверки на выход из программы

	do
	{
		system("cls");

		String str1, str2, str3, str4;

		cout << "Строка 1: ";
		cin >> str1;
		cout << "Строка 2: ";
		cin >> str2;
		cout << "Строка 3: ";
		cin >> str3;

		str4 = str1 + " " + str2 + str3 + "_ _ _" + str1(1, 3);
		str4 += " " + str1 + " Конец.";

		cout << endl << "Результат: " << endl << str4;

		do
		{
			cout << "\nПродолжить? (y - да / n - нет): ";							//запрос на продолжение программы
			cin >> exit;															//получение символа
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');
}
