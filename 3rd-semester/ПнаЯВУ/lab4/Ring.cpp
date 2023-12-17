#pragma once
#include "Ring.h"

template <typename T>
bool Ring<T>::isEmpty()                             //������� ��������, ����� �� ������
{
    if (!this->head) return true;

    return false;
}

template<typename T>
void Ring<T>::insert(T obj)                         //������� ���������� ��������
{
    if (isEmpty())                                  //���� ������ �����
    {
        head = new Node<T>();
        head->data = obj;
        head->next = head->prev = head;
    }
    else                                            //� ������ ��� ���� ��������
    {
        Node<T>* newNode = new Node<T>();

        newNode->data = obj;
        newNode->next = head;                       //������������� ����������
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

template<typename T>
void Ring<T>::remove(int n)                         //������� �������� ��������
{
    if (isEmpty())
        return;

    Node<T>* delNode = head;                        //���� � ������ ���� ��������

    while (n-- > 1)
    {
        if (delNode->next == head)                  //������ ������ ������� ������ � ����� �� �������
            return;
        delNode = delNode->next;
    }

    if (head == head->next)                         //���� � ������ ������ ���� �������
    {
        delete head;
        head = nullptr;
        return;
    }

    if (delNode == head)                            //���� ��������� ������� � ��������
        head = head->next;

    delNode->next->prev = delNode->prev;            //������������� ����������
    delNode->prev->next = delNode->next;
    delete delNode;
}

template<typename T>
void Ring<T>::clear()                               //������� ������� ������
{
    while (!isEmpty())                              //���� �� �����, ������� ������ �������
        remove(1);
}

template<typename T>
void Ring<T>::display()                             //������� ����������� ������� �� �����
{
    Node<T>* current = head;

    if (isEmpty())
    {
        cout << "������� �����" << endl << endl;
        return;
    }

    head->data.display();                           //����� �����
    do
    {
        cout << current->data;                      //����� ��������� �������
        current = current->next;
    } while (current != head);
    cout << endl;
}

template<typename T>
Ring<T> Ring<T>::search(const T obj)                //������� ������ �� ����������
{
    Ring<T> result;                                 //������ ��� ���������� ����������
    Node<T>* current = this->head;

    if (isEmpty())
        return result;

    do
    {
        if (obj == current->data)                   //����� ���������� ��������
            result.insert(current->data);
        current = current->next;
    } while (current != this->head);

    return result;
}