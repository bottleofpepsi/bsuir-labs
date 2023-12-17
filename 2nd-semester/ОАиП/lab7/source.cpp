#include "header.h"																		//������ � ����������� ������� � ������������ ������������
#include "oldheader.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	tree* root = nullptr;																//��������� �� ������ ������
	int p = 0;

	while (1)
	{
		print_menu();																	//����� ���� �� �����						

		switch (input_nat())															//����� ��������
		{
		case 1:																			//�������� ����
			puts("������� ����������� �������� ('0', ����� ���������):");
			while (1)
			{
				p = input_nat();
				if (!p) break;
				root = add_node(root, p);
			}
			break;
		case 2:																			//������� ����
			if (!root)
			{
				puts("������ �����!\n");
				break;
			}
			printf("������� ��������� ��������: ");
			root = delete_node(root, input_nat());
			puts("�������!\n");
			break;
		case 3:																			//����� �� �����
			if (!root)
			{
				puts("������ �����!\n");
				break;
			}
			puts("����������������� �����:\n");
			show(root, 0);
			printf("\n������� ������ %d\n\n", get_depth(root));
			break;
		case 4:																			//�������������� ����� ������
			if (!root)
			{
				puts("������ �����!\n");
				break;
			}
			printf("������������ ����� ������: ");
			print_inorder(root);
			puts("\n");
			break;
		case 5:																			//������ ����� ������
			if (!root)
			{
				puts("������ �����!\n");
				break;
			}
			printf("\n������ ����� ������: ");
			print_preorder(root);
			puts("\n");
			break;
		case 6:																			//�������� ����� ������
			if (!root)
			{
				puts("������ �����!\n");
				break;
			}
			printf("\n�������� ����� ������: ");
			print_postorder(root);
			puts("\n");
			break;
		case 7:																			//������� ���������
			if (!root) break;
			printf("����� ��������� �� ������ �������: ");
			root = delete_subtree(root, input_nat());
			puts("�������!\n");
			break;
		case 8:																			//�������� ������
			if (!root) break;
			root = delete_tree(root);
			puts("������ �������!\n");
			break;
		case 9:																			//����� ��������
			if (!root)
			{
				puts("������ �����!\n");
				break;
			}
			printf("������� ������� ��������: ");
			search(root, input_nat());
			break;
		case 0:																			//����� �� ���������
			root = delete_tree(root);
			return 0;
		default: printf("������������ ����!\n");
		}
	}

	return 0;
}