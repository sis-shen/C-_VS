#include "BSTree.h"
#include <vector>
#include <utility>
using namespace std;


int main()
{
	vector<int> arr({ 2,3,1,5,4,6,8,7 });//׼��������ļ�ֵ��
	key_value::BSTree<int, int> bst;
	for (int i = 0; i < arr.size(); ++i)
	{
		bst.insert(arr[i],arr[i]);//����ʹ��ֵ��ͬ������۲�
	}
	bst.erase(2);

	bst.in_order();//����

	key_value::BSTree<int, int> copy(bst);


	//cout << bst.find(1);


	return 0;
}