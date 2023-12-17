#pragma once
#include "libs.h"

template <typename T>
struct Node                                         //����
{
    T data;                                         //����������
    Node* next;                                     //��������� �� ��������� �������
    Node* prev;                                     //��������� �� ���������� �������

    Node() : next(nullptr), prev(nullptr) {}        //������������� ����
};

template<typename T>
class Ring                                          //��������� ����� ������
{
    Node<T>* head;                                  //��������� �� �������� �������

public:
    Ring() : head(nullptr) {}                       //�����������
    Ring(const Ring<T>& obj) : head(nullptr)        //����������� �����������
    {
        Node<T>* current = obj.head;
        if (obj.head)
        {
            do
            {
                this->insert(current->data);
                current = current->next;
            } while (current != obj.head);
        }
    }
    ~Ring() {}                                      //����������

    T& operator[](int);                             //�������� ����������

    bool isEmpty();                                 //�������� ������� �������� ������ �� �������
    int size();                                     //�������� ������� ������� ����� ������
    void insert(T);                                 //�������� ������� ���������� ��������
    void remove(int);                               //�������� ������� �������� ��������
    void clear();                                   //�������� ������� ������� ������
    void display();                                 //�������� ������� ����������� ������� �� �����
    Ring<T> search(T);                              //�������� ������� ������ �� ����������
};