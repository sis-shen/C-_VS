#define  _CRT_SECURE_NO_WARNINGS 1

#include "hefman.h"






class HefmanTreeSystem
{
public:

	//void Run()
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

	void TestInit()
	{
		cout << "TestInit()" << endl;

		Init();

		g_ht.print_code_list();
	}

	void TestReadFile()
	{
		sup::HefmanTree<char> ht;
		ht.read_file("hfmTree.txt");
		ht.print_code_list();
	}

	void TestEncode()
	{
		g_ht.read_file("hfmTree.txt");
		Encode();
	}

	void Init()
	{
		int n = 0;
		cout << "������������n: " << endl;
		cin >> n;
		vector<int> weighs(n);
		vector<char> str(n);

		cout << "������" << n << "���ַ�(��#��ʾ�ո�)" << endl;
		for (int i = 0; i < n; i++)
		{
			char ch = 0;
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
		ht.whrite_file("hfmTree.txt");

	}

	void Encode()
	{
		fstream f;
		f.open("ToBeTran.txt", ios::in);
		string line;
		string code;
		while (getline(f, line))
		{
			for (auto ch : line)
			{
				if (ch != ' ')
					code += g_ht.get_index(ch);
				else
					code += g_ht.get_index('#');
			}
		}

		f.close();

		f.open("CodeFile.txt", ios::out);
		f << code;
		f.close();
	}


	void menu()
	{
		cout << "=============================";
		cout << "         ������ָ��            ";
		cout << "    I.��ʼ��  E.����  D.����     ";
		cout << "    P.��ӡ����  T.��ӡ�շ�����     ";
		cout << "=============================";
	}
private:
	sup::HefmanTree<char> g_ht;
};


int main()
{
	HefmanTreeSystem hfsys;
	hfsys.TestReadFile();
	hfsys.TestEncode();
	return 0;
}