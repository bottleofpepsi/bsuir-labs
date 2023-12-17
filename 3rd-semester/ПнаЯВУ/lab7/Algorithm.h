#pragma once
#include "libs.h"
#include "Ring.cpp"

template<typename T>
int find(Iterator<T> begin, Iterator<T> end, const T& obj)			//функци€ поиска заданного элемента	
{
	int i = 0;
	do
		i++;
	while (begin++ != end);

	return i;
}

template<typename T>
void swap(Iterator<T> it1, Iterator<T> it2)							//функци€ обмена
{
	T temp = *it1;
	*it1 = *it2;
	*it2 = temp;
}

template<typename T>
Ring<T> search(Iterator<T> begin,									//функци€ поиска по фильтру
	Iterator<T> end, const T& param)
{
	Ring<T> result;													//кольцо дл€ сохранени€ результата

	end++;
	do
	{
		if (*begin == param)
			result.insert(*begin);
	} while (begin++ != end);

	return result;
}

template<typename T>
void sort(Iterator<T> begin, Iterator<T> end, int num)		//функци€ сортировки по полю
{
	Iterator<T> min;
	Iterator<T> j;
	do
	{
		min = j = begin;									//поиск минимального значени€
		do
		{
			j++;					
			if (*j < (*min).copyParameter(num))				//сравнение по полю num
				min = j;									//если меньше, то j Ч новое минимальное
		} while (j != end);

		if (min != begin)									//если минимальное значение Ч не текущий элемент
			swap(min, begin);								//помен€ть их местами
		begin++;
	} while (begin != end);
}