#include <iostream>
#include <fstream>

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

int main()
{
	fstream f;
	f.open("ff.txt", ios::binary);
	f << 123 ;
	f.close();
	return 0;
}