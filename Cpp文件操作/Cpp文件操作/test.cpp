#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//int main()
//{
//	fstream f;
//	f.open("file.txt", ios::out);//��outģʽ��file.txt
//	string str = "This is a sentence";//���ڴ���׼��һ���ַ���
//	f << str;//���ַ������ڴ�д���ļ�
//	f.close();//�ر��ļ���
//
//	//f������Ը���
//	f.open("file.txt", ios::in);//��inģʽ��file.txt
//	string content;//��������
//	f >> content;//���ļ�����ȡ����д�����(�ڴ�)
//	cout << content;//��ӡ������һ��
//	f.close();
//
//	return 0;
//}



//int main()
//{
//	fstream f;
//	f.open("nofile", ios::in);
//
//
//	return 0;
//}

//int main()
//{
//	fstream f;
//	string s1 = "123456789";
//	string s2 = "1234";
//	string tmp;
//
//	f.open("f1.txt", ios::out);
//	f << s1;
//	f.close();
//
//	f.open("f1.txt", ios::out);
//
//	
//
//	f.open("f1.txt", ios::out);
//	f << s2;
//	f.close();
//
//	return 0;
//}

//int main()
//{
//	fstream f;
//	f.open("ff.txt", ios::out);
//	f << "LongWord";//׼��һ�������ݵ�ԭ�ļ�
//	f.close();
//
//	f.open("ff.txt", ios::in | ios::out);
//	f << "1234";//д��1234
//	f.close();
//	//���ff.txt������Ϊ"1234Word",����ȫ����
//	return 0;
//}

//
//int main()
//{
//	fstream f;
//
//	f.open("file.txt",ios::out);
//	f << "111";//׼��һ������Ϊ111���ļ�
//	f.close();
//	f.open("file.txt", ios::app);
//	f << "222";//111����׷��222
//	f.close();
//	//�ļ�����Ϊ111222
//	return 0;
//}

//int main()
//{
//	fstream f;
//	f.open("f1.txt", ios::trunc | ios::out);
//	f.close();
//"
//	return 0;
//}

//int main()
//{
	//fstream f;
	////f.open("ff.txt",ios::out);
	//f.open("ff.txt", ios::binary);
	//f << "test" << "\r\n";
	//f.close();
//
//	f.open("ff.txt", ios::binary | ios::in);
//	char ch;
//	while ((ch = f.get()) != EOF)
//	{
//		if (ch == '\r')
//			cout << "\\r";
//		else if (ch == '\n')
//			cout << "\\n";
//		else
//			cout << ch;
//	}
//	return 0;
//}

//int main()
//{
//	fstream f("ff.txt", ios::out);
//	f << "123|";
//	f.close();
//	
//	f.open("ff.txt", ios::ate | ios::out | ios::in);
//	f << "456";
//	f.close();
//
//	return 0;
//}


//int main()
//{
//	//��ǰ׼��һ������ȡ�ļ�
//	fstream f;
//	f.open("ff.txt", ios::out);
//	f << "line 1" << endl << "line 2" << endl;
//	f.close();
//	//================
//	f.open("ff.txt");
//	string str;
//	while (getline(f, str))//��fΪ��ʱ��ѭ��ֹͣ
//	{
//		cout << str << endl;//��ӡÿ��,str�ڲ������з�
//	}
// f.close();
//	return 0;
//}

int main()
{
	//��ǰ׼��һ������ȡ�ļ�
	fstream f,f2;
	f.open("ff.txt", ios::out);
	f2.open("f2.txt", ios::out);
	f2 << 666 << endl;
	f << "line 1" << endl << "line 2" << endl;
	f.close();
	//================

	f.open("ff.txt");
	char ch;
	while (f.get(ch))//��ȡ�ַ�
	{
		cout << ch;//��ӡ�ַ�
	}
	f.close();

	f.open("ff.txt");
	while ((ch = f.get()) != EOF)//��Ϊ���ȼ������⣬���������
	{
		cout << ch;//��ӡ�ַ�
	}
	f.close();
	return 0;
}