#include <iostream>

using namespace std;



int main()
{
	bool P = true;
	bool Q = false;

	bool conjunction = P && Q;          // ��ȡ (��)
	bool disjunction = P || Q;         // ��ȡ (��)
	bool xor_result = P != Q;          // ���
	bool implication = !P || Q;        // �������
	bool biconditional = P == Q;       // ˫����

	return 0;
}