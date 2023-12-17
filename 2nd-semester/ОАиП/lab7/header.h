#pragma once

#include <stdio.h>									//����������� ���������
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

struct tree											//���� ��������� ������
{
	int data = 0,									//�������� ��������
		count = 0;									//����� ����������
	tree *left, *right;								//��������� �� ����� � ������ ���������
};

tree* allocate_memory();							//�������� ������� ��������� ������ ��� ���� ������
tree* add_node(tree*, int);							//�������� ������� ���������� ���� ������
tree* find_node(tree* root, int k);					//�������� ������� ������ ���� �� �����������
tree* delete_node(tree*, int);						//�������� ������� �������� ���� ������
tree* delete_tree(tree*);							//�������� ������� �������� ���������
tree* delete_subtree(tree*, int);					//�������� ������� �������� ���������
void show(tree*, int);								//�������� ������� ������������������ ������
void print_inorder(tree*);							//�������� ������� ������� ������ ������
void print_preorder(tree*);							//�������� ������� �������������� ������ ������
void print_postorder(tree*);						//�������� ������� ��������� ������ ������
int get_depth(tree*);								//�������� ������� ���������� ������� ������
void search(tree*, int);							//�������� ������� ������ ��������
void print_menu();									//�������� ������� ������ ���� �� �����