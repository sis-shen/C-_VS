#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year = 1,int month = 1,int day = 1):_year(year),_month(month),_day(day)
        {}

    void TestPrint()
    {
        _year = 2024;//��ʽ����this���ʳ�Ա����
        this->_month = 4;//��ʽ����this
        _day = 1;
        Print();//��ʽ����this�����ó�Ա����Print()
        this->Print();//��ʽ����this��Ч������һ����ͬ
    }

    void Print()
    {
        cout << _year << ":" << _month << ":" << _day << endl;
    }

protected:
    int _num;

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d;

    d.TestPrint();
    return 0;
}

