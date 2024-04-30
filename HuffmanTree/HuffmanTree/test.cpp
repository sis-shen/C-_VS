#define  _CRT_SECURE_NO_WARNINGS 1

#include "hefman.h"

sup::HefmanTree<char> g_ht;

void TestHefmanTree()
{
	string str = "abcdef";
	vector<char> ch(str.begin(), str.end());
	vector<int> weigh({ 9,8,7,6,5,4 });
	sup::HefmanTree<char> tmp(ch, weigh);
	sup::HefmanTree<char>ht = tmp;

	ht.print_tree();
	cout << endl;
	ht.print_code_list();

	ht.remake_tree();
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
	g_ht = ht;
	ht.whrite_file();

}

void menu()
{
	cout << "=============================";
	cout << "         ������ָ��            ";
	cout << "    I.��ʼ��  E.����  D.����     ";
	cout << "    P.��ӡ����  T.��ӡ�շ�����     ";
	cout << "=============================";
}

//void TestExp()
//{
//	char ch;
//	while (true)
//	{
//		menu();
//		cin >> ch;
//		switch (ch)
//		{
//		case 'I': Init(); break;
//		case 'E': Encode(); break;
//		case 'D': Decode(); break;
//		case 'P': PrintCode(); break;
//		case 'T': TreePrint(); break;
//		default:
//			cout << "����Ƿ�������������" << endl << endl;
//			break;
//		}
//	}
//}


int main()
{
	TestHefmanTree();

	return 0;
}