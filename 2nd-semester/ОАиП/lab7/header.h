#pragma once

#include <stdio.h>									//подключение библиотек
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct tree											//узел бинарного дерева
{
	int data = 0,									//числовое значение
		count = 0;									//число повторений
	tree *left, *right;								//указатели на левое и правое поддерево
};

tree* allocate_memory();							//прототип функции выделения памяти для узла дерева
tree* add_node(tree*, int);							//прототип функции добавления узла дерева
tree* find_node(tree* root, int k);					//прототип функции поиска узла по содержимому
tree* delete_node(tree*, int);						//прототип функции удаления узла дерева
tree* delete_tree(tree*);							//прототип функции удаления поддерева
tree* delete_subtree(tree*, int);					//прототип функции удаления поддерева
void show(tree*, int);								//прототип функции псевдографического вывода
void print_inorder(tree*);							//прототип функции прямого обхода дерева
void print_preorder(tree*);							//прототип функции симметриченого обхода дерева
void print_postorder(tree*);						//прототип функции обратного обхода дерева
int get_depth(tree*);								//прототип функции вычисления глубины дерева
void search(tree*, int);							//прототип функции поиска значения
void print_menu();									//прототип функции вывода меню на экран