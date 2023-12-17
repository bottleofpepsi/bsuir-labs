#include "header.h"
#include "oldheader.h"

tree* allocate_memory()															//������� ��������� ������ ��� ���� ������
{
	tree* t1;

	t1 = (tree*)calloc(1, sizeof(tree));
	if (!t1) return nullptr;

	return t1;
}

tree* add_node(tree* root, int k)												//������� ���������� ���� ������
{
	if (!root)																	    
	{            
		root = allocate_memory();												//��������� ������ ��� ������������ ����

		root->data = k;															//���������� �������������� �����
		root->count = 0;
		root->left = nullptr;
		root->right = nullptr;
	}

	if (k == root->data)														//���� ����� ������� ��� ���� � ������
	{
		root->count++;															//������� ���������� �������������
		return root;
	}
	if (k < root->data)
		root->left = add_node(root->left, k);									//���� ����� ������������ ������ ����� �������� ��-��, �� ������� � ����� ���������
	else
		root->right = add_node(root->right, k);									//����� � � ������
	
	return root;
}

tree* find_node(tree* root, int k)												//������� ������ ����
{
	if (!root) return nullptr;

	if (k < root->data)															//���� ������� �������� ������, ��� �������
		root = find_node(root->left, k);										//���������� ��������� ������� ��� ������ ���������
	else
		if (k > root->data)														//����� � ��� �������
			root = find_node(root->right, k);

	return root;
}

tree* delete_node(tree* root, int k)											//������� �������� ���� ������
{
	if (!root) return nullptr;

	tree* t1;

	if (k < root->data)															//���� ������� �������� ������, ��� �������
		root->left = delete_node(root->left, k);								//���������� ��������� ������� ��� ������ ���������
	else if (k > root->data)
		root->right = delete_node(root->right, k);								//����� � ��� �������

	else																		//���� ���� ������
	{
		if (!root->left)														//���� ���� ����� ������ ������ ���������� ��� �� ����� ������
		{
			t1 = root->right;													//��������� ��������� �� ����������
			free(root);															//������� ������ ��� ��������
			return t1;
		}
		if (!root->right)
		{
			t1 = root->left;													//��������� ��������� �� ����������
			free(root);															//������� ������ ��� ��������
			return t1;
		}

																				//���� ���� ����� ���� �����������
		t1 = root->right;														//������� ���������� (����� �����) ���� � ������ ���������
		while (t1 && t1->left) t1 = t1->left;
		root->data = t1->data;													//������ �� ������� � ��������� �����

		root->right = delete_node(root->right, t1->data);						//������� ����
	}

	return root;
}

tree* delete_tree(tree* node)													//������� �������� ������ (���������)
{
	if (!node) return nullptr;

	if (node->left)
		delete_tree(node->left);												//���� ���������� ����� ���������, ���������� ������� ���
	if (node->right)
		delete_tree(node->right);												//���� ���������� ������ ���������, ���������� ������� ���

	free(node);																	//������� ������ �������� ��������
	return nullptr;
}

tree* delete_subtree(tree* root, int k)											//������� �������� ���������
{
	if (!root) return nullptr;
	tree* node = find_node(root, k);											//������� ��������� ����

	delete_tree(node->left);													//������� ���������� ����� ����
	delete_tree(node->right);
	node->left = node->right = nullptr;

	root = delete_node(root, k);												//������� ��� ����

	return root;
}

void show(tree* root, int l)													//������� ������������������ ������
{
	int i = 0;

	if (root)
	{
		if (root->right) show(root->right, l + 1);								//���������� ������� ������ ���������
		for (i = 0; i < l; i++) printf("      ");
		printf("%d (%d)\n", root->data, root->count);
		if (root->left) show(root->left, l + 1);								//���������� ������� ����� ���������
	}
}

void search(tree* root, int k)													//������� ������ ��������
{
	tree* node = find_node(root, k);

	if (!node)
		puts("����� ������� �� ������!\n");
	else
		printf("������� %d ����������� %d ���\n\n", node->data, node->count);
}

void print_inorder(tree* root)													//������� ������������� ������ ������
{
	if (!root) return;
	print_inorder(root->left);													//������� ����� ���������
	printf("%d  ", root->data);													//������� ������
	print_inorder(root->right);													//������� ������ ���������
}

void print_preorder(tree* root)													//������� ������� ������ ������
{
	if (!root) return;
	printf("%d  ", root->data);													//������� ������
	print_preorder(root->left);													//������� ����� ���������
	print_preorder(root->right);												//������� ������ ���������
}

void print_postorder(tree* root)												//������� ��������� ������ ������.
{
	if (!root) return;
	print_postorder(root->left);												//������� ����� ���������
	print_postorder(root->right);												//������� ������ ���������
	printf("%d  ", root->data);													//������� ������ ���������
}

int get_depth(tree* root)														//������� ����������� ������� ������
{
	if (!root) return 0;

	int l = 0,																	//������� ������ ���������
		r = 0;																	//������� ������� ���������

	if (root->left)																
		l = get_depth(root->left) + 1;											//���������� ������� ����� ���������, ����������� �������� ��������
	if (root->right)
		r = get_depth(root->right) + 1;											//���������� ������� ������ ���������, ����������� �������� ��������

	return (l > r ? l : r);														//���������� ������� ����������� � ���������� ���������� ��������
}

void print_menu()																//������� ������ ���� �� �����
{
	printf("����:\n");
	printf("1 � �������� ����� ��������\n");
	printf("2 � ������� ��������\n");
	printf("3 � ������� ������ �� �����\n");
	printf("4 � �������������� ����� ������\n");
	printf("5 � ������ ����� ������\n");
	printf("6 � �������� ����� ������\n");
	printf("7 � ������� ���������\n");
	printf("8 � �������� ������\n");
	printf("9 � ����� �������\n");
	printf("0 � �����\n\n");
	printf("����: ");
}