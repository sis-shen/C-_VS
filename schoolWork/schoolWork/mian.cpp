#include <iostream>
#include <string>

using namespace std;

class Course
{
public:
	Course(const string& name,int credit = 0,int id = -1,double score = 0)
		:_name(name), _credit(credit), _id(id), _score(score)
	{}

	void Set(const string& name, int credit = 0, int id = -1, double score = 0)
	{
		_name = name;
		_credit = credit;
		_id = id;
		_score = score;
	}
	void Info()
	{
		printf("�γ���:%s ,�γ̺�:%d ,ѧ��:%d ,����:%lf\n", _name.c_str(), _credit, _id, _score);
	}

	void ShowName()
	{
		cout << "�γ���:" << _name << endl;
	}

	void ShowCredit()
	{
		cout << "ѧ�֣�" << _credit << endl;
	}

	void ShowID()
	{
		cout << "�γ�ID" << _id << endl;
	}

	void ShowScore()
	{
		cout << "����" << _score << endl;
	}

private:
	string _name;
	int _credit;//ѧ��
	int _id;//�γ̺�
	double _score;//����
};



int main()
{
	Course CPP("C++�������", 3, 1, 99.8);
	CPP.ShowName();
	CPP.Info();
	CPP.Set("C++�������", 6, 11, 250);
	CPP.Info();
	return 0;
}