#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

int main()
{
	int* p1 = new int;
	int* p2 = new int(10);//��10��ʼ��
	int* p3 = new int[10];//��������
	int* p4 = new int[10] {0};

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	return 0;
}