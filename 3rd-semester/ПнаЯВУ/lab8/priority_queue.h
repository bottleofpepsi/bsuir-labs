#include "libs.h"
#include "Truck.h"

struct Comparator                                                       //компаратор
{
    bool operator()(Truck const& obj1, Truck const& obj2)
    {
        if (obj1.get_max_speed() != obj2.get_max_speed())               
            return obj1.get_max_speed() > obj2.get_max_speed();         //сравнивать скорости

        return obj1.get_load() > obj2.get_load();                       //если скорости равны, сравнивать вес груза
    }
};

template<typename T>
void printPQ(T obj)                                     //вывод очереди с приоритетом на экран
{
    int k = 0;

    if (obj.empty())                                    //если очередь пуста
    {
        k = 15;
        cout << tableFrame
            << " Таблица пуста" << endl
            << tableFrame << endl;
        return;
    }

    k = T::value_type::display();                       //вывод шапки
    while (!obj.empty())
    {
        cout << obj.top();                              //вывод эл-та с наибольшим приоритетом
        obj.pop();                                      //удаление этого элемента
    }
    cout << tableFrame << endl;
}