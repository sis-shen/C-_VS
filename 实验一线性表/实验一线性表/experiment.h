#pragma once

#include <iostream>
#include "slist.h"
#include "list.h"
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;
class Examin
{
public:
	void testSList()
	{
		//������ɾ���
		cout << "���Ե�����" << endl;
		slist::slist<int> slst;
		slist::slist<int> copy(slst);//���Կ�������

		int arr1[] = { 1,2,3,4,5 };
		int arr2[] = { 10,9,8,7,6 };

		cout << "����β��" << endl;
		for (auto e : arr1) slst.PushBack(e);
		slst.PrintList();

		cout << "����ͷ��" << endl;
		for (auto e : arr2) slst.PushFront(e);
		slst.PrintList();

		cout << "���Բ���" << endl;
		auto it = slst.Find(8);
		*it = 888;
		slst.PrintList();

		cout << "���Բ���" << endl;
		slst.Insert(it,666);
		slst.PrintList();

		cout << "����ɾ��" << endl;
		slst.Erase(it);
		slst.PrintList();

		cout << "����βɾ*5" << endl;
		int n = 5;
		while (n--) slst.PopBack();
		slst.PrintList();

		cout << "����ͷɾ*4" << endl;
		n = 4;
		while (n--) slst.PopFront();
		slst.PrintList();


	}

	void testList()
	{
		cout << "����˫��ѭ����ͷ����" << endl;
		list::list<int> lst;
		list::list<int> lst(lst);//���Կ�������

		int arr1[] = { 1,2,3,4,5 };
		int arr2[] = { 10,9,8,7,6 };

		cout << "����β��" << endl;
		for (auto e : arr1) lst.push_back(e);
		lst.print_list();

		cout << "����ͷ��" << endl;
		for (auto e : arr2) lst.push_front(e);
		lst.print_list();


		cout << "���Բ���" << endl;
		auto it = lst.find(8);
		*it = 888;
		lst.print_list();

		cout << "���Բ���" << endl;
		lst.insert(it, 666);
		lst.print_list();


		cout << "����ɾ��" << endl;
		lst.erase(it);
		lst.print_list();

		cout << "����βɾ*5" << endl;
		int n = 5;
		while (n--) lst.pop_back();
		lst.print_list();

		cout << "����ͷɾ*4" << endl;
		n = 4;
		while (n--) lst.pop_front();
		lst.print_list();

	}
};

namespace design
{
	struct city
	{
		typedef pair<int, int> PII;

		string _name;
		PII _pos;

		city(string name="", PII pos = {-1,-1})
			:_name(name)
			,_pos(pos)
		{}

		bool operator==(city c)
		{
			return _name == c._name;
		}

		
	};

	ostream& operator<<(ostream& o, city& c)
	{
		cout << c._name;
		return o;
	}

	class city_list :public slist::slist<city>
	{
	public:
		typedef pair<int, int> PII;
		PII FindPosByName(string name)
		{
			city tmp(name, { 0,0 });//������ʱ���нڵ㣬�����ع���==ֻƥ��name���ȥFind
			iterator cur = Find(tmp);
			if (cur == end()) return { -1,-1 }; //���طǷ����꣬��ʾû�ҵ�

			return cur->_pos;
			
		}

		vector<string> FindCitiesByDistance(PII pos, int distance)
		{
			assert(distance >= 0);
			assert(pos.first >= 0 and pos.second >= 0);
			vector<string> ret;
			iterator cur = begin();
			while (cur != end())
			{
				int x = cur->_pos.first;
				int y = cur->_pos.second;
				int dd = (x - pos.first) * (x - pos.first) + (y - pos.second) * (y - pos.second);
				if (dd <= distance*distance) ret.push_back(cur->_name);

				++cur;
			}

			return ret;
		}
	};

	void ManualTest()
	{
		city_list cl;
		int cnt;
		cout << "�������������" << endl;
		cin >> cnt;
		while (cnt--)
		{
			cout << "������������֣���������,�ո����" << endl;
			string name;
			int x, y;
			cin >> name >> x >> y;
			city c(name, { x,y });
			cl.PushBack(c);
		}

		cl.PrintList();
	}

	void AutoTest()
	{
		const int N = 100;

		vector<string> city_name({ "ShaoXing","BeiJing","Shanghai","Trump","Biden" });
		srand(time(NULL));

		city_list cl;

		for (int i = 0; i < city_name.size(); i++)
		{
			int x = rand() % N;
			int y = rand() % N;
			cl.PushBack(city(city_name[i], {x,y}));
		}

		//���Բ��ҳ���
		cl.PrintList();
		string name;
		cout << "Ҫ���ҵĳ���" << endl;
		cin >> name;
		auto pos = cl.FindPosByName(name);
		cout << "����" << name << "������Ϊ" << pos.first << " " << pos.second << endl;

		int pos_x, pos_y;
		int dis = 0;
		cout << "������Ҫ���ҵľ���,��������" << endl;
		cin >> dis>>pos_x>>pos_y;

		auto arr = cl.FindCitiesByDistance({ pos_x,pos_y }, dis);
		
		if (arr.size())
		{
			cout << "�ҵ��ĳ���Ϊ:";
			for (auto e : arr)
			{
				cout << e << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "�Ҳ������������ĳ���" << endl;
		}


	}

	void TestMain()
	{
		AutoTest();
	}

}

namespace Josegh
{
	void TestMain()
	{
		vector<int> arr({ 5,7,3,9,4,8,2 });//n���˵������б�
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
	}
}