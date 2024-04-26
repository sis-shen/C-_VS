#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1) :_year(year), _month(month), _day(day) { cout << "Date()" << endl; }

    Date(const Date& d) :_year(d._year), _month(d._month), _day(d._day) { cout << "��������" << endl; }

    //Date(int year, int month, int day):_year(year),_day(day),_month(month) {}

    void TestPrint()
    {
        //_year = 2024;//��ʽ����this���ʳ�Ա����
        //this->_month = 4;//��ʽ����this
        //_day = 1;
        Print();//��ʽ����this�����ó�Ա����Print()
        this->Print();//��ʽ����this��Ч������һ����ͬ
    }

    void Print()
    {
        cout << _year << ":" << _month << ":" << _day << endl;
    }

    Date& operator=(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        cout << "operator=" << endl;
        return *this;
    }

private:
    int _year;
    int _month;
    int _day;
};

template<class T>
struct Node
{
    T _val;
    Node<T>* _next;

    Node(const T& val = T()):_val(val),_next(nullptr){}
};

class Calendar
{
public:
    Calendar(const Date& d):_d1(nullptr),_d2(nullptr)
    {
        _d1 = new Date(d);
        _d2 = new Date;
    }

    ~Calendar()
    {

    }
private:
    Date* _d1;
    Date* _d2;
};

int main()
{
    Node<Date> n;
    n._val.TestPrint();

    //Date copy = d;

    //copy = d;
    //copy.TestPrint();
    return 0;
}

