#define  _CRT_SECURE_NO_WARNINGS 1

#include "hefman.h"

sup::HefmanTree<char> g_ht;

void TestHefmanTree()
{
	string str = "abcdef";
	vector<char> ch(str.begin(), str.end());
	vector<int> weigh({ 9,8,7,6,5,4 });

	sup::HefmanTree<char>ht(ch, weigh);

	ht.print_tree();
	cout << endl;
	ht.print_code_list();

	ht.remake();
	ht.print_tree();
	cout << endl;
	ht.print_code_list();
}

void Init()
{
	int n = 0;
	cout << "������������n: " << endl;
	cin >> n;
	vector<int> weighs(n);
	vector<char> str(n);

	cout << "������" << n << "���ַ�" << endl;
	for (int i = 0; i < n; i++)
	{
		int ch = 0;
		cin >> ch;
		str[i] = ch;
	}

	cout << "������" << n << "��Ȩ��" << endl;
	for (int i = 0; i < n; i++)
	{
		int w = 0;
		cin >> w;
		weighs[i] = w;
	}

	sup::HefmanTree<char> ht(str, weighs);
	ht.whrite_file();

}


int main()
{
	TestHefmanTree();

	return 0;
}