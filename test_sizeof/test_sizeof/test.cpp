#include <iostream>

using namespace std;

//int g_arr[10] = { 0 };
//
//void func(int st_arr[])
//{
//	cout << sizeof(st_arr) << endl;//�˴��˻�Ϊָ����������4��8
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	cout << sizeof(g_arr) << endl;//���40
//	cout << sizeof(arr) << endl; //���40
//	func(arr);//���4/8
//	return 0;
//}

class R
{
	int _a, _b, _c;
};

class A
{
	char _ch;
	short _s;
};

int main()
{
	cout << sizeof(A);
	return 0;
}