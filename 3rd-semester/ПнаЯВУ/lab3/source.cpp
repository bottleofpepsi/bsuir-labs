#include "header.h"


int main()
{
	system("chcp 1251");															//���������
	system("color E0");																//��������� ����� �������

	int select = 0;																	//������ ��� �������� �� ����� �� ���������

	Truck tr[3];																	//������ ����������
	int n = 0;
	float tmp = 0.0;
	char str[15];

	while (true)
	{
		system("cls");

		tr->display();																//����� �������

		for (int i = 0; i < 3; i++)
		{
			cout << left << tr[i];
		}

		cout << endl << "1 � ������ ������������ ��������" << endl << "2 � ������ ������ ���������" << endl;
		cout << "3 � ������ ��� �����" << endl << "4 � ������ ����� ����������" << endl;
		cout << "5 � ������ ��� �����" << endl << "6 � ������ ����" << endl << "9 � �����" << endl;

		cout << endl << "����: ";
		cin >> select;																//����� ��������
		switch (select)
		{
		case 1:																		//���� ������������ ��������
			cout << "����� ���������: ";
			cin >> n;
			cout << "����� ��������: ";
			cin.ignore(INT_MAX, '\n');
			cin >> tmp;
			tr[n-1].set_max_speed(tmp);
			break;
		case 2:																		//���� ������
			cout << "����� ���������: ";
			cin >> n;
			cout << "����� ��������: ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(str, 15, '\n');
			tr[n-1].set_model(str);
			break;
		case 3:																		//���� ���� �����
			cout << "����� ���������: ";
			cin >> n;
			cout << "����� ��������: ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(str, 15, '\n');
			tr[n-1].set_load_type(str);
			break;		
		case 4:																		//���� ������ ����������
			cout << "����� ���������: ";
			cin >> n;
			cout << "����� ��������: ";
			cin.ignore(INT_MAX, '\n');
			cin.getline(str, 15, '\n');
			tr[n-1].set_destination(str);
			break;
		case 5:																		//���� ���� �����
			cout << "����� ���������: ";
			cin >> n;
			cout << "����� ��������: ";
			cin.ignore(INT_MAX, '\n');
			cin >> tmp;
			tr[n-1].set_load(tmp);
			break;
		case 6:																		//������ ���� 
			cout << "����� ���������: ";
			cin >> n;
			cin.ignore(INT_MAX, '\n');
			cin >> tr[n-1];
			break;
		case 9:
			return 0;
		default: printf("������������ ����!\n");
		}
	}
}