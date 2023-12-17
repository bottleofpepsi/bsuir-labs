#pragma once
#include "Ring.h"

template <typename T>
bool Ring<T>::isEmpty()                             //функция проверки, пусто ли кольцо
{
    if (!this->head) return true;

    return false;
}

template<typename T>
void Ring<T>::insert(T obj)                         //функция добавления элемента
{
    if (isEmpty())                                  //если кольцо пусто
    {
        head = new Node<T>();
        head->data = obj;
        head->next = head->prev = head;
    }
    else                                            //в кольце уже есть элементы
    {
        Node<T>* newNode = new Node<T>();

        newNode->data = obj;
        newNode->next = head;                       //переустановка указателей
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

template<typename T>
void Ring<T>::remove(int n)                         //функция удаления элемента
{
    if (isEmpty())
        return;

    Node<T>* delNode = head;                        //если в кольце есть элементы

    while (n-- > 1)
    {
        if (delNode->next == head)                  //больше одного прохода кольца — выход из функции
            return;
        delNode = delNode->next;
    }

    if (head == head->next)                         //если в кольце только один элемент
    {
        delete head;
        head = nullptr;
        return;
    }

    if (delNode == head)                            //если удаляемый элемент — головной
        head = head->next;

    delNode->next->prev = delNode->prev;            //переустановка указателей
    delNode->prev->next = delNode->next;
    delete delNode;
}

template<typename T>
void Ring<T>::clear()                               //функция очистки кольца
{
    while (!isEmpty())                              //пока не пусто, удалять первый элемент
        remove(1);
}

template<typename T>
void Ring<T>::display()                             //функция отображения очереди на экран
{
    Node<T>* current = head;

    if (isEmpty())
    {
        cout << "Таблица пуста" << endl << endl;
        return;
    }

    head->data.display();                           //вывод шапки
    do
    {
        cout << current->data;                      //вывод элементов очереди
        current = current->next;
    } while (current != head);
    cout << endl;
}

template<typename T>
Ring<T> Ring<T>::search(const T obj)                //функция поиска по параметрам
{
    Ring<T> result;                                 //кольцо для сохранения результата
    Node<T>* current = this->head;

    if (isEmpty())
        return result;

    do
    {
        if (obj == current->data)                   //поиск подходящих объектов
            result.insert(current->data);
        current = current->next;
    } while (current != this->head);

    return result;
}