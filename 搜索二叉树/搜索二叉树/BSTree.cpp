#include "BSTree.h"
#include <string>
using namespace std;

void TestBSTree()
{
	//                 8
	//            3          10
	//         1     6            14
	//            4    7         13
	int arr[] = { 8,3,1,10,6 ,4,7,14,13 };
	key::BSTree<int> tree;

	for (auto e : arr)
	{
		tree.Insert(e);
	}

	for (auto e : arr)
	{
		tree.Erase(e);
		tree.InOrder();
	}
}

void TestKeyTree()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("sort", "����");
	dict.Insert("order", "˳��");
	dict.Insert("left", "�ұ�");
	dict.Insert("right", "�ұ�");
	dict.Insert("find", "����");
	dict.Insert("erase", "ɾ��");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "�޴˵���" << endl;
		}
	}

}

int main()
{
	TestKeyTree();
	return 0;
}