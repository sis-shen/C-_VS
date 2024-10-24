#include <iostream>

using namespace std;

//C++98
class NoCopy
{
private://���ó�˽��
	NoCopy(const NoCopy&);
	NoCopy& operator=(const NoCopy&);//ֻ����������
};

//C++11
class CopyBan
{
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};

class HeapOnly
{
public:
	static HeapOnly* GenerateObj()//�ṩ��̬��Ա����
	{
		return new HeapOnly();
	}

private:
	HeapOnly();//˽�л�Ĭ�Ϲ��캯��
	HeapOnly(const HeapOnly&) = delete;//������������
	HeapOnly& operator=(const HeapOnly&) = delete;//ɾ����ֵ��������
};


class StackOnly
{
public:
	static StackOnly CreatObj()
	{
		return StackOnly();//������ʱ����Ŀ���
	}

private:
	StackOnly() {}

	StackOnly(const StackOnly&) = delete;

	void* operator new(size_t size) = delete;
	void operator delete(void* ptr) = delete;
};

class NoInherit
{
public:
	static NoInherit GenerateInstance()
	{
		return NoInherit();
	}
private:
	NoInherit() {}
};

class InheritBan final
{

};

int main()
{
	cout << "OK" << endl;
	return 0;
}