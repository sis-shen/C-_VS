#include <iostream>
using namespace std;

//1.�麯������д(��дʵ�֣����Ĳ�����ȱʡֵ)  ��ͬ��������������������ֵ),����(��ΪЭ��)������ֵ���Բ�ͬ���������Ǹ��ӹ�ϵָ�������
//2.����ָ�������ȥ����

//class Person
//{
//public:
//	virtual Person* BuyTicket() 
//	{ 
//		cout << "ȫ��Ʊ" << endl;
//		return this;
//	}
//
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student :public Person
//{
//public:
//	virtual Student* BuyTicket() 
//	{ 
//		cout << "���ۼ�Ʊ" << endl; 
//		return this;
//	}
//
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//void Func(Person& p)
//{
//	//1.�������̬ -- ������������
//	//2.�����̬ -- ��ָ��Ķ�������
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student stu;
//
//	Func(p);
//	Func(stu);
//
//	auto pPerson = new Person;
//	auto pStu = new Student;
//
//	cout << "=======================" << endl;
//	delete pPerson;
//	delete pStu;
//	cout << "=======================" << endl;
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void func(int val = 2556) { cout << "A->" << val << endl; }
//	virtual void test() { func(); };
//};
//
//class B:public A 
//{
//public:
//	void func(int val = 0) { cout << "B->" << val << endl; }
//};
//
//int main()
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 2556) { cout << "A->" << val << endl; }
//};
//
//class B :public A
//{
//public:
//	virtual void func(int val = 0) { cout << "B->" << val << endl; }
//	virtual void test() { func(); };
//
//};
//
//int main()
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}



//������

//class car
//{
//public:
//	virtual void drive() = 0;
//};