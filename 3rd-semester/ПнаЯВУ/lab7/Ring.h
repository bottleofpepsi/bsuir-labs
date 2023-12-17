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
class Iterator
{
    Node<T>* current;

public:
    Iterator(Node<T>* cur = nullptr) : current(cur) {}
    Iterator(const Iterator<T>& iter) : current(iter.current) {}
    ~Iterator() {}

    T& operator*();

    Iterator<T>& operator=(const Iterator<T>&);
    Iterator<T>& operator=(T);

    Iterator<T>& operator++(int);
    Iterator<T>& operator--(int);
    Iterator<T>& operator+=(int);
    Iterator<T>& operator-=(int);

    bool operator!=(const Iterator<T>& b);
    bool operator==(const Iterator<T>& b);
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

    friend class Iterator<T>;                       //������������� ����� ���������

    T& operator[](int);                             //�������� ����������

    bool isEmpty();                                 //�������� ������� �������� ������ �� �������
    int size();                                     //�������� ������� ������� ����� ������
    void insert(T);                                 //�������� ������� ���������� ��������
    void remove(int);                               //�������� ������� �������� ��������
    void clear();                                   //�������� ������� ������� ������
    void display();                                 //�������� ������� ����������� ������� �� �����
    Ring<T> search(T);                              //�������� ������� ������ �� ����������

    Iterator<T> begin();                            //�������� �� ������ ������ (�������� �������)
    Iterator<T> end();                              //�������� �� ����� ������ (������� ����� ��������)
};