#include "Date.h"
using namespace std;
int main()
{
	int y, m, d;
	cout << "��������ʼ�����գ��ո�ָ�: ";
	cin >> y >> m >> d;

	Date date(y, m, d);
	while (true)
	{
		getchar();
		date.Print();
		++date;
	}
	return 0;
}