#include "header.h"


int main()
{
	system("chcp 1251");															//кодировка
	system("color E0");																//изменение цвета консоли

	int select = 0;																	//символ для проверки на выход из программы

	Truck tr[3];																	//массив грузовиков
	int n = 0;
	float tmp = 0.0;
	char str[15];

	while (true)
	{
		system("cls");

		tr->display();																//вывод таблицы

		for (int i = 0; i < 3; i++)
		{
			cout << left << tr[i];
		}

		cout << endl << "1 — Ввести максимальную скорость" << endl << "2 — Ввести модель грузовика" << endl;
		cout << "3 — Ввести тип груза" << endl << "4 — Ввести пункт назначения" << endl;
		cout << "5 — Ввести вес груза" << endl << "6 — Полный ввод" << endl << "9 — Выход" << endl;

		cout << endl << "Ввод: ";
		cin >> select;																//выбор операции
		switch (select)
		{
		case 1:																		//ввод максимальной скорости
			cout << "Номер грузовика: ";
			cin >> n;
			cout << "Новое значение: ";
			cin.ignore(INT_MAX, '\n');
			cin >> tmp;
			tr[n-1].set_max_speed(tmp);
			break;
		case 2:																		//ввод модели
			cout << "Номер грузовика: ";
			cin >> n;
			cout << "Новое значение: ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(str, 15, '\n');
			tr[n-1].set_model(str);
			break;
		case 3:																		//ввод типа груза
			cout << "Номер грузовика: ";
			cin >> n;
			cout << "Новое значение: ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(str, 15, '\n');
			tr[n-1].set_load_type(str);
			break;		
		case 4:																		//ввод пункта назначения
			cout << "Номер грузовика: ";
			cin >> n;
			cout << "Новое значение: ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(str, 15, '\n');
			tr[n-1].set_destination(str);
			break;
		case 5:																		//ввод веса груза
			cout << "Номер грузовика: ";
			cin >> n;
			cout << "Новое значение: ";
			cin.ignore(INT_MAX, '\n');
			cin >> tmp;
			tr[n-1].set_load(tmp);
			break;
		case 6:																		//полный ввод 
			cout << "Номер грузовика: ";
			cin >> n;
			cin.ignore(INT_MAX, '\n');
			cin >> tr[n-1];
			break;
		case 9:
			return 0;
		default: printf("Некорректный ввод!\n");
		}
	}
}