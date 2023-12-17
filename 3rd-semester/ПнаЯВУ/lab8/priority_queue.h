#include "libs.h"
#include "Truck.h"

struct Comparator                                                       //����������
{
    bool operator()(Truck const& obj1, Truck const& obj2)
    {
        if (obj1.get_max_speed() != obj2.get_max_speed())               
            return obj1.get_max_speed() > obj2.get_max_speed();         //���������� ��������

        return obj1.get_load() > obj2.get_load();                       //���� �������� �����, ���������� ��� �����
    }
};

template<typename T>
void printPQ(T obj)                                     //����� ������� � ����������� �� �����
{
    int k = 0;

    if (obj.empty())                                    //���� ������� �����
    {
        k = 15;
        cout << tableFrame
            << " ������� �����" << endl
            << tableFrame << endl;
        return;
    }

    k = T::value_type::display();                       //����� �����
    while (!obj.empty())
    {
        cout << obj.top();                              //����� ��-�� � ���������� �����������
        obj.pop();                                      //�������� ����� ��������
    }
    cout << tableFrame << endl;
}