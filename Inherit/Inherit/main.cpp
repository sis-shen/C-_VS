//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	void Info()
//	{
//		printf("name:%s age:%d\n", _name.c_str(), _age);
//	}
//protected:
//	string _name = "supdriver";
//	int _age = 24;
//};
//
//class Student:public Person
//{
//public:
//	void getID()
//	{
//		cout << "ID:" << _ID << endl;
//	}
//private:
//	int _ID = 114514;
//};
//
//
//int main()
//{
//	Student stu;
//	stu.Info();
//	stu.getID();
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	//����Ĺ��й��캯��
//	Person(const string& name, const string& gender, int age)
//		:_name(name)
//		,_gender(gender)
//		,_age(age)
//	{}
//	void Info()
//	{
//		printf("name:%s age:%d\n", _name.c_str(), _age);
//	}
//protected:
//	string _name;
//	string _gender;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student(const string& name,const string& gender,int age,int ID)
//		:Person(name,gender,age)//��ʽ���ø���Ĺ��캯��
//		,_ID(ID)
//	{}
//	void getID()
//	{
//		cout << "ID:" << _ID << endl;
//	}
//public:
//	int _ID;
//};
//
//
//int main()
//{
//	Student stu("supdriver", "male", 24, 114514);//���ù��캯��
//
//	Person  person(stu);//����û����ʽ������Ӧ�Ĺ��캯���������Զ���Ƭ
//	Person* pp = &stu;//����ָ�����ָ��������
//	Person& rp = stu;//�������ÿ���ָ��������
//
//	//stu = person;//��������ܸ�ֵ��������
//
//	//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &stu;
//	Student* pstu = (Student*)pp;//ָ���ַ����ָ��������ģ�������������ǰ�ȫ�ģ��Ϸ���
//	pstu->_ID = 233;//���ﲢû��Խ��
//
//	pp = &person;
//	pstu = (Student*)pp;//���־��ǲ���ȫ�ģ����ܻ�Խ�����	
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	void Info()
//	{
//		printf("name:%s age:%d\n", _name.c_str(), _age);
//	}
//protected:
//	string _name = "supdriver";
//	int _age = 24;
//};
//
//class Student:public Person
//{
//public:
//	void Info()//ͬ��������������
//	{
//		printf("name:%s age:%d\n ID:%d", _name.c_str(), _age,_ID);
//	}
//private:
//	int _ID = 114514;
//};
//
//
//int main()
//{
//	Student stu;
//	stu.Info();//����Student���ڵ�Info�������������ڵı�����
//	stu.Person::Info();//��ʽ����Person�ڵ�Info����
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._name << endl;//���д��벻�ᱨ����Ϊ_name�Ǽ̳���Person���
//	cout << s._stuNum << endl;//���д���ᱨ����Ϊ����û��Ȩ�޷���Student���Լ������ĳ�Ա
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ��̬��Ա����,ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//	return 0;
//}

class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}


