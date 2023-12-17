#pragma once
#include "libs.h"

template <typename T>
struct Node                                         //узел
{
    T data;                                         //информация
    Node* next;                                     //указатель на следующий элемент
    Node* prev;                                     //указатель на предыдущий элемент

    Node() : next(nullptr), prev(nullptr) {}        //инициализация узла
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

    friend class Iterator<T>;                       //дружественный класс итератора

    T& operator[](int);                             //оператор индексации

    bool isEmpty();                                 //прототип функции проверки кольца на пустоту
    int size();                                     //прототип функции расчёта длины кольца
    void insert(T);                                 //прототип функции добавления элемента
    void remove(int);                               //прототип функции удаления элемента
    void clear();                                   //прототип функции очистки кольца
    void display();                                 //прототип функции отображения очереди на экран
    Ring<T> search(T);                              //прототип функции поиска по параметрам

    Iterator<T> begin();                            //итератор на начало кольца (головной элемент)
    Iterator<T> end();                              //итератор на конец кольца (элемент перед головным)
};