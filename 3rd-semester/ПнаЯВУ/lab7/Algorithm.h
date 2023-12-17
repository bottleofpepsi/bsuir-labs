#pragma once
#include "libs.h"
#include "Ring.cpp"

template<typename T>
int find(Iterator<T> begin, Iterator<T> end, const T& obj)			//������� ������ ��������� ��������	
{
	int i = 0;
	do
		i++;
	while (begin++ != end);

	return i;
}

template<typename T>
void swap(Iterator<T> it1, Iterator<T> it2)							//������� ������
{
	T temp = *it1;
	*it1 = *it2;
	*it2 = temp;
}

template<typename T>
Ring<T> search(Iterator<T> begin,									//������� ������ �� �������
	Iterator<T> end, const T& param)
{
	Ring<T> result;													//������ ��� ���������� ����������

	end++;
	do
	{
		if (*begin == param)
			result.insert(*begin);
	} while (begin++ != end);

	return result;
}

template<typename T>
void sort(Iterator<T> begin, Iterator<T> end, int num)		//������� ���������� �� ����
{
	Iterator<T> min;
	Iterator<T> j;
	do
	{
		min = j = begin;									//����� ������������ ��������
		do
		{
			j++;					
			if (*j < (*min).copyParameter(num))				//��������� �� ���� num
				min = j;									//���� ������, �� j � ����� �����������
		} while (j != end);

		if (min != begin)									//���� ����������� �������� � �� ������� �������
			swap(min, begin);								//�������� �� �������
		begin++;
	} while (begin != end);
}