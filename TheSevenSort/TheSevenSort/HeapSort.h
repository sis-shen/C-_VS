#pragma once
#include <vector>
using namespace std;

template<class T>
void adjust_up(vector<T>& arr, int child)
{
	int parent = (child - 1) / 2;
	while (parent != child)//parent == child == 0ʱ
	{
		if (arr[parent] < arr[child])//��������
		{
			swap(arr[parent], arr[child]);//����
			child = parent;//�������ϵ���,����child��parent
			parent = (child - 1) / 2;
		}
		else//��ɽ��ѣ��˳�ѭ��
		{
			break;
		}
	}
}

template<class T>
void adjust_down(vector<T>& arr,int sz , int parent)
{
	int child = parent * 2 + 1;
	if (child + 1 < sz && arr[child + 1] > arr[child]) child++;//ȡ�ϴ�ĺ���

	while (child < sz)
	{
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			int child = parent * 2 + 1;
			if (child >= sz) break;
			if (child + 1 < sz && arr[child + 1] > arr[child]) child++;
		}
		else
		{
			break;
		}
	}
}

template <class T>
void heap_sort(vector<T>& arr)
{
	int sz = arr.size();

	//����
	for (int i = 1; i < sz; i++)
	{
		adjust_up(arr, i);//������벢���ϵ�������
	}

	for (int i = sz-1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);//ѡ������Ԫ�ط���ĩβ
		adjust_down(arr,i,0);//���µ�������
	}
}
