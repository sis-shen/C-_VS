#pragma once
#include <vector>

using namespace std;

namespace sup
{
	template<class T,class Con = vector<T>>//�ṹ��������Ĭ��ʹ��vector
	class stack
	{
		stack()
			:_top(0)
			,_con(0)
		{}




	private:
		int _top;
		Con _con;
	};


}