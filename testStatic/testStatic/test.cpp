#include <iostream>

using namespace std;
//
//void func()
//{
//	static char ch = 'a';//��static����
//	cout << ch++ << " ";//ÿ�ε��ö��ı�ch
//}
//
//int main()
//{
//	for (int i = 0; i < 26; i++)
//	{
//		func();
//	}
//	
//	return 0;
//}


//class A
//{
//public:
//	A(){ cout << "A()"<<endl; }
//
//	~A(){cout << "~A()"<<endl;}
//};
//
//void func()
//{
//	cout <<"func"<<endl;
//	static A a;
//}
//
//int main()
//{
//	func();
//	func();
//	cout << "end" << endl;
//	return 0;
//}


//
//extern void func();//��ʱ�������������Ҳ���ʵ��
//
//int main()
//{
//	func();//����
//	return 0;
//}

class A
{
public:
	A()
	{
		cnt++;
	}

	static int getCNT()
	{
		return cnt;
	}

private:
	static int cnt;
};

int A::cnt = 0;

int main()
{
	A a, b, c;
	cout<<A::getCNT();
	return 0;
}