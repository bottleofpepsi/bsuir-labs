#include "header.h"
#include "oldheader.h"

tree* allocate_memory()															//функция выделения памяти для узла дерева
{
	tree* t1;

	t1 = (tree*)calloc(1, sizeof(tree));
	if (!t1) return nullptr;

	return t1;
}

tree* add_node(tree* root, int k)												//функция добавления узла дерева
{
	if (!root)																	    
	{            
		root = allocate_memory();												//выделение памяти для добавляемого узла

		root->data = k;															//заполнение информационных полей
		root->count = 0;
		root->left = nullptr;
		root->right = nullptr;
	}

	if (k == root->data)														//если такой элемент уже есть в дереве
	{
		root->count++;															//счётчик повторений увеличивается
		return root;
	}
	if (k < root->data)
		root->left = add_node(root->left, k);									//если число добавляемого меньше числа текущего эл-та, то заносим в левое поддерево
	else
		root->right = add_node(root->right, k);									//иначе — в правое
	
	return root;
}

tree* find_node(tree* root, int k)												//функция поиска узла
{
	if (!root) return nullptr;

	if (k < root->data)															//если искомое значение меньше, чем текущее
		root = find_node(root->left, k);										//рекурсивно запускаем функцию для левого поддерева
	else
		if (k > root->data)														//иначе — для правого
			root = find_node(root->right, k);

	return root;
}

tree* delete_node(tree* root, int k)											//функция удаления узла дерева
{
	if (!root) return nullptr;

	tree* t1;

	if (k < root->data)															//если искомое значение меньше, чем текущее
		root->left = delete_node(root->left, k);								//рекурсивно запускаем функцию для левого поддерева
	else if (k > root->data)
		root->right = delete_node(root->right, k);								//иначе — для правого

	else																		//если узел найден
	{
		if (!root->left)														//если узел имеет только одного наследника или не имеет вообще
		{
			t1 = root->right;													//сохраняем указатель на наследника
			free(root);															//очищаем память для родителя
			return t1;
		}
		if (!root->right)
		{
			t1 = root->left;													//сохраняем указатель на наследника
			free(root);															//очищаем память для родителя
			return t1;
		}

																				//если узел имеет двух наследников
		t1 = root->right;														//находим наименьший (самый левый) узел в правом поддереве
		while (t1 && t1->left) t1 = t1->left;
		root->data = t1->data;													//меняем их местами с удаляемым узлом

		root->right = delete_node(root->right, t1->data);						//удаляем узел
	}

	return root;
}

tree* delete_tree(tree* node)													//функция удаления дерева (поддерева)
{
	if (!node) return nullptr;

	if (node->left)
		delete_tree(node->left);												//если существует левое поддерево, рекурсивно удаляем его
	if (node->right)
		delete_tree(node->right);												//если существует правое поддерево, рекурсивно удаляем его

	free(node);																	//очистка памяти текущего элемента
	return nullptr;
}

tree* delete_subtree(tree* root, int k)											//функция удаления поддерева
{
	if (!root) return nullptr;
	tree* node = find_node(root, k);											//находим удаляемый узел

	delete_tree(node->left);													//удаляем поддеревья этого узла
	delete_tree(node->right);
	node->left = node->right = nullptr;

	root = delete_node(root, k);												//удаляем сам узел

	return root;
}

void show(tree* root, int l)													//функция псевдографического вывода
{
	int i = 0;

	if (root)
	{
		if (root->right) show(root->right, l + 1);								//рекурсивно выводим правое поддерево
		for (i = 0; i < l; i++) printf("      ");
		printf("%d (%d)\n", root->data, root->count);
		if (root->left) show(root->left, l + 1);								//рекурсивно выводим левое поддерево
	}
}

void search(tree* root, int k)													//функция поиска значения
{
	tree* node = find_node(root, k);

	if (!node)
		puts("Такой элемент не найден!\n");
	else
		printf("Элемент %d встречается %d раз\n\n", node->data, node->count);
}

void print_inorder(tree* root)													//функция симметричного обхода дерева
{
	if (!root) return;
	print_inorder(root->left);													//обходим левое поддерево
	printf("%d  ", root->data);													//обходим корень
	print_inorder(root->right);													//обходим правое поддерево
}

void print_preorder(tree* root)													//функция прямого обхода дерева
{
	if (!root) return;
	printf("%d  ", root->data);													//обходим корень
	print_preorder(root->left);													//обходим левое поддерево
	print_preorder(root->right);												//обходим правое поддерево
}

void print_postorder(tree* root)												//функция обратного обхода дерева.
{
	if (!root) return;
	print_postorder(root->left);												//обходим левое поддерево
	print_postorder(root->right);												//обходим правое поддерево
	printf("%d  ", root->data);													//обходим корень поддерево
}

int get_depth(tree* root)														//функция определения глубины дерева
{
	if (!root) return 0;

	int l = 0,																	//глубина левого поддерева
		r = 0;																	//глубина правого поддерева

	if (root->left)																
		l = get_depth(root->left) + 1;											//рекурсивно обходим левое поддерево, увеличиваем значение счётчика
	if (root->right)
		r = get_depth(root->right) + 1;											//рекурсивно обходим правое поддерево, увеличиваем значение счётчика

	return (l > r ? l : r);														//сравниваем глубины поддеревьев и возвращаем наибольшее значение
}

void print_menu()																//функция вывода меню на экран
{
	printf("Меню:\n");
	printf("1 — Добавить новые значения\n");
	printf("2 — Удалить значение\n");
	printf("3 — Вывести дерево на экран\n");
	printf("4 — Симметрический обход дерева\n");
	printf("5 — Прямой обход дерева\n");
	printf("6 — Обратный обход дерева\n");
	printf("7 — Удалить поддерево\n");
	printf("8 — Очистить дерево\n");
	printf("9 — Найти элемент\n");
	printf("0 — Выход\n\n");
	printf("Ввод: ");
}