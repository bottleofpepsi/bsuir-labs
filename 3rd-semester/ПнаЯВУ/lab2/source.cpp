#include "String.h"

int main()
{
	system("chcp 1251");															//���������

	int n = 0;
	char exit = 0;																	//������ ��� �������� �� ����� �� ���������

	do
	{
		system("cls");

		String str1, str2, str3, str4;

		cout << "������ 1: ";
		cin >> str1;
		cout << "������ 2: ";
		cin >> str2;
		cout << "������ 3: ";
		cin >> str3;

		str4 = str1 + " " + str2 + str3 + "_ _ _" + str1(1, 3);
		str4 += " " + str1 + " �����.";

		cout << endl << "���������: " << endl << str4;

		do
		{
			cout << "\n����������? (y - �� / n - ���): ";							//������ �� ����������� ���������
			cin >> exit;															//��������� �������
		} while (exit != 'y' && exit != 'Y' && exit != 'N' && exit != 'n');
	} while (exit == 'Y' || exit == 'y');
}
