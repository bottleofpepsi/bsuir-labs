#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct Node                                         //узел
{
    T data;                                         //информация
    Node* next;                                     //указатель на следующий элемент
    Node* prev;                                     //указатель на предыдущий элемент

    Node() : next(nullptr), prev(nullptr) {}        //инициализация узла
};

template<typename T>
class Ring                                          //шаблонный класс кольца
{
    Node<T>* head;                                  //указатель на головной элемент

public:
    Ring() : head(nullptr) {}                       //конструктор
    Ring(const Ring<T>& obj) : head(nullptr)        //конструктор копирования
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
    ~Ring() {}                                      //деструктор

    bool isEmpty();                                 //прототип функции проверки кольца на пустоту
    void insert(T);                                 //прототип функции добавления элемента
    void remove(int);                               //прототип функции удаления элемента
    void clear();                                   //прототип функции очистки кольца
    void display();                                 //прототип функции отображения очереди на экран
    Ring<T> search(T);                              //прототип функции поиска по параметрам
};