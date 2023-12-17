#include "header.h"																		//хэдеры с прототипами функций и необходимыми библиотеками
#include "oldheader.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	tree* root = nullptr;																//указатель на корень дерева
	int p = 0;

	while (1)
	{
		print_menu();																	//вывод меню на экран						

		switch (input_nat())															//выбор операции
		{
		case 1:																			//добавить узел
			puts("Введите добавляемые значения ('0', чтобы закончить):");
			while (1)
			{
				p = input_nat();
				if (!p) break;
				root = add_node(root, p);
			}
			break;
		case 2:																			//удалить узел
			if (!root)
			{
				puts("Дерево пусто!\n");
				break;
			}
			printf("Введите удаляемое значение: ");
			root = delete_node(root, input_nat());
			puts("Удалено!\n");
			break;
		case 3:																			//вывод на экран
			if (!root)
			{
				puts("Дерево пусто!\n");
				break;
			}
			puts("Псевдографический вывод:\n");
			show(root, 0);
			printf("\nГлубина дерева %d\n\n", get_depth(root));
			break;
		case 4:																			//симметрический обход дерева
			if (!root)
			{
				puts("Дерево пусто!\n");
				break;
			}
			printf("Симметричный обход дерева: ");
			print_inorder(root);
			puts("\n");
			break;
		case 5:																			//прямой обход дерева
			if (!root)
			{
				puts("Дерево пусто!\n");
				break;
			}
			printf("\nПрямой обход дерева: ");
			print_preorder(root);
			puts("\n");
			break;
		case 6:																			//обратный обход дерева
			if (!root)
			{
				puts("Дерево пусто!\n");
				break;
			}
			printf("\nОбратный обход дерева: ");
			print_postorder(root);
			puts("\n");
			break;
		case 7:																			//удалить поддерево
			if (!root) break;
			printf("Какое поддерево вы хотите удалить: ");
			root = delete_subtree(root, input_nat());
			puts("Удалено!\n");
			break;
		case 8:																			//очистить дерево
			if (!root) break;
			root = delete_tree(root);
			puts("Дерево очищено!\n");
			break;
		case 9:																			//поиск значения
			if (!root)
			{
				puts("Дерево пусто!\n");
				break;
			}
			printf("Введите искомое значение: ");
			search(root, input_nat());
			break;
		case 0:																			//выход из программы
			root = delete_tree(root);
			return 0;
		default: printf("Некорректный ввод!\n");
		}
	}

	return 0;
}