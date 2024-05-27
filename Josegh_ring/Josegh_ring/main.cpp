#include "list.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	int m = 0,n = 0;
	cout << "�������ʼ��������ֵ: " << endl;
	cin >> m;
	cout << "����������n: " << endl;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	list::list<pair<int, int>> lst;
	for (int i = 0; i < arr.size(); i++)
	{
		lst.push_back({ i + 1,arr[i] });
	}

	int m = 0;
	cout << "�������һ��m��ֵ: ";

	auto cur = lst.begin();
	vector<int> ret;
	while (!lst.empty())
	{
		while (--m)//ѭ��m-1
		{
			++cur;
			if (cur == lst.end()) ++cur;
		}

		auto tmp = ++cur;
		ret.push_back(tmp->first);//������
		m = tmp->second;//����m
		lst.erase(tmp);

	}

	//��ӡ���
	cout << "����˳��Ϊ:" << endl;
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}