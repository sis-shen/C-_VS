//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Course
//{
//public:
//	Course(const string& name,int credit = 0,int id = -1,double score = 0)
//		:_name(name), _credit(credit), _id(id), _score(score)
//	{}
//
//	void Set(const string& name, int credit = 0, int id = -1, double score = 0)
//	{
//		_name = name;
//		_credit = credit;
//		_id = id;
//		_score = score;
//	}
//	void Info()
//	{
//		printf("�γ���:%s ,�γ̺�:%d ,ѧ��:%d ,����:%lf\n", _name.c_str(), _credit, _id, _score);
//	}
//
//	void ShowName()
//	{
//		cout << "�γ���:" << _name << endl;
//	}
//
//	void ShowCredit()
//	{
//		cout << "ѧ�֣�" << _credit << endl;
//	}
//
//	void ShowID()
//	{
//		cout << "�γ�ID" << _id << endl;
//	}
//
//	void ShowScore()
//	{
//		cout << "����" << _score << endl;
//	}
//
//private:
//	string _name;
//	int _credit;//ѧ��
//	int _id;//�γ̺�
//	double _score;//����
//};
//
//
//
//int main()
//{
//	Course CPP("C++�������", 3, 1, 99.8);
//	CPP.ShowName();
//	CPP.Info();
//	CPP.Set("C++�������", 6, 11, 250);
//	CPP.Info();
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1

// �����ռ�

//#include <stdio.h>
//#include <stdlib.h>
//
//int rand = 0; // �����ʱ��cstdlibȫ��չ������rand����������ͻ
//// Ҳ����˵�����ǺͿ�֮�����������ͻ
//// ���ڹ�˾���棬һ����Ŀ�кö��ˣ����п��ܻ���������ͻ
//
//int main()
//{
//	printf("%d\n", rand);
//
//	return 0;
//}

// ���ǣ�Ϊ�˽��������ͻ�����⣬�����������ռ�
// �ؼ���namespace

#include <stdio.h>
#include <stdlib.h>

// �������Ƕ���һ�������ռ���
namespace tan
{
	int rand = 0;
}

int a = 0;

int main()
{
	printf("%p\n", rand); // ���ֵ��ȡ�����ǿ������
	printf("%d\n", tan::rand); // ���ʵľ���ȫ��

	int a = 1;
	printf("%d\n", a);
	printf("%d\n", ::a); // ::���޶��������û��Ĭ��ȫ��

	return 0;
}