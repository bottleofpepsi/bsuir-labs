#pragma once
#include "Ring.h"

template <typename T>
T& Ring<T>::operator[](int n)                        //�������� ����������
{
    Node<T>* current = this->head;

    for (int i = 0; i < n; i++)
        current = current->next;

    return current->data;
}

template <typename T>
bool Ring<T>::isEmpty()                             //������� ��������, ����� �� ������
{
    if (!this->head) return true;

    return false;
}

template <typename T>
int Ring<T>::size()                                 //������� �������� ����� ������
{
    if (isEmpty())
        return 0;

    Node<T>* current = head;
    int count = 0;

    do
    {
        count++;
        current = current->next;
    } while (current != head);                      

    return count;
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
void Ring<T>::remove(int n)                            //������� �������� ��������
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
    int k = 0;

    if (isEmpty())
    {
        k = 15;
        cout << tableFrame
            << " ������� �����" << endl
            << tableFrame << endl;
        return;
    }

    k = T::display();                           //����� �����
    do
    {
        cout << current->data;                      //����� ��������� �������
        current = current->next;
    } while (current != head);
    cout << tableFrame << endl;
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

template<typename T>
Iterator<T> Ring<T>::begin()
{ 
    Iterator<T> iter(head);
    return iter;
}

template<typename T>
Iterator<T> Ring<T>::end()
{
    Iterator<T> iter(head->prev);
    return iter;
}

template<typename T>
T& Iterator<T>::operator*() { return current->data; }

template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& iter)
{
    this->current = iter.current;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator=(T obj)
{
    this->current->data = obj;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++(int)
{ 
    current = current->next; 
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--(int)
{
    current = current->prev;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator+=(int n)
{
    for (int i = 0; i < n; i++) 
        current = current->next;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-=(int n)
{
    for (int i = 0; i < n; i++)
        current = current->prev;
    return *this;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator& iter) { return !(*this == iter); }

template<typename T>
bool Iterator<T>::operator==(const Iterator& iter) { return this->current == iter.current; }