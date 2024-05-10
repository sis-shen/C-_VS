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

	void TestDecode()
	{
		g_ht.read_file("hfmTree.txt");
		Decode();
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

	void ReadFile()
	{
		g_ht.read_file("hfmTree.txt");
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
					code += g_ht.generate_code(ch);
				else
					code += g_ht.generate_code('#');
			}
		}

		f.close();

		f.open("CodeFile.txt", ios::out);
		f << code;
		f.close();
	}

	void Decode()
	{
		fstream f;
		f.open("CodeFile.txt", ios::in);
		string code;
		getline(f, code);
		f.close();
		string ret;
		ret = g_ht.decode(code);
		cout << "������Ϊ: " << ret<<endl;
		f.open("TextFile.txt", ios::out);
		f << ret;
		f.close();

	}

	void Print()
	{
		fstream f;
		fstream out;
		out.open("TextFile.txt", ios::out);
		f.open("CodeFile.txt", ios::in);
		string code;
		getline(f, code);
		for (int i = 0; i < code.size(); i++)
		{
			cout << code[i];
			out << code[i];
			if (i && i % 50 == 0)
			{
				cout << endl;
				out << endl;
			}
		}
		cout << endl;
		f.close();
		out.close();
	}

	void PrintTree()
	{
		g_ht.print_tree();
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
	hfsys.TestDecode();
	hfsys.Print();
	hfsys.PrintTree();
	return 0;
}