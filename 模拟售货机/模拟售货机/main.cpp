#include "VendingMachine.h"

int main()
{
	shared_ptr<VendingMachine> pvm(new VendingMachine());//ͨ��shared_ptrʵ�ֵ���ģʽ

	pvm->Run();
	return 0;
}