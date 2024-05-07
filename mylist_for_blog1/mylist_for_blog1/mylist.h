#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class T>//����ģ�崴��һ���ڵ���
struct ListNode
{
	T _val;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	//�ṩȫȱʡ��Ĭ�Ϲ��캯��
	ListNode(const T& val = T()) :_val(val), _next(nullptr), _prev(nullptr) {}
};

template<class T,class Ref,class Ptr>//������Ҳ����ģ��
struct __list_iterator
{
	typedef __list_iterator<T,Ref,Ptr> Self;//�򻯴���
	typedef __list_iterator<T, T&, T*> iterator;
	typedef ListNode<T> Node;
	Node* _node;

	__list_iterator(Node* node) :_node(node) {}

	__list_iterator(iterator it) :_node(it._node) {}

	Self& operator++()//����operator++
	{
		_node = _node->_next;
		return *this;
	}

	bool operator!=(const Self& it) const //����!==,�Ƚϲ������ǵü�const
	{
		return _node != it._node;
	}

	Ref operator*()//���� *
	{
		return _node->_val;
	}

	Ptr operator->()
	{
		return &(_node->_val);
	}
};

//��ListNode����list��

template <class T>
class list
{
	typedef ListNode<T> Node;//��typedef�򻯴���
public:
	typedef __list_iterator<T,T&,T*> iterator;
	typedef __list_iterator<T,const T&,const T*> const_iterator;
public:
	list()//Ĭ�Ϲ��캯��
	{
		_head = new Node;
		//ά������ָ��
		_head->_next = _head;
		_head->_prev = _head;
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	void push_front(const T& val)
	{
		Node* newnode = new Node(val);
		Node* next = _head->_next;//�����ָ�룬�򻯴���

		_head->_next = newnode;
		newnode->_prev = _head;
		newnode->_next = next;
		next->_prev = newnode;
	}

	void pop_front()
	{
		if (empty()) return;

		Node* cur = _head->_next;
		
		_head->_next = cur->_next;
		cur->_next->_prev = _head;
		delete cur;
	}

	bool empty()
	{
		return _head->_next == _head;
	}

	//ʣ��������в�ȫ

private:
	Node* _head;
};