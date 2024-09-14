#pragma once
#include <functional>
#include <cassert>
#include <iostream>

typedef bool Color;//ֻ�к��������ɫ������ʹ��bool����
const Color Red = false;//����������ɫ
const Color Black = true;

//��������Ķ���
template <class ValueType>
struct RBTreeNode
{
	typedef RBTreeNode<ValueType> Node;//�򻯴���
	Node* _left;
	Node* _right;
	Node* _parent;
	Color _color;

	ValueType _value;
	RBTreeNode(const ValueType& val, Color color)
		:_value(val)
		, _color(color)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

template <class Value,class Ref,class Ptr>
class __rbtree_iterator
{
	typedef __rbtree_iterator<Value, const Value&, const Value*> const_iterator;
	typedef __rbtree_iterator<Value, Ref, Ptr> self;
	typedef RBTreeNode<Value>* linkeType;

public:
	__rbtree_iterator(const linkeType& ptr)
		:_ptr(ptr)
	{}

	__rbtree_iterator(const const_iterator& const_it)
		:_ptr(const_it._ptr)
	{}

	self operator++()
	{
		if (_ptr == nullptr || _ptr->_right == _ptr )
		{
			exit(-1);//end()����������++,�յ��������ܼӼ�
		}
		if (_ptr->_right)
		{
			_ptr = _ptr->_right;
		}
		else
		{
			linkeType parent = _ptr->_parent;
			while (parent->_right == _ptr)
			{
				_ptr = parent;
				parent = _ptr->_parent;
			}
			if (parent->_right == nullptr || parent->_right==parent)
			{
				//��������������ĸ��ڵ�û��������
				_ptr = parent;
			}
		}
		return (*this);
	}

	self operator--()
	{
		if (_ptr == nullptr)
		{
			exit(-1);//�Ƿ����
		}
		else if (_ptr->_left == _ptr)//��ͷ���
		{
			linkeType right = _ptr->_parent;//�ߵ����ڵ�
			while (right)
			{
				_ptr = right;
				right->_ptr;
			}
		}
		else if (_ptr->_left)
		{
			_ptr = _ptr->_left;
			linkeType right = _ptr->_right;
			while (right)
			{
				_ptr = right;
				right = _ptr->_right;
			}
		}
		else
		{
			linkeType parent = _ptr->_parent;
			while (parent->_left == _ptr)
			{
				_ptr = parent;
				parent = _ptr->_parent;
			}
			_ptr = parent;
		}

		return *this;
	}

	Ref operator*()
	{
		return *_ptr;
	}

	Ptr operator->()
	{
		return _ptr;
	}


private:
	linkeType _ptr;
};

template<class K,class V,class KeyOfValue,class Compare = std::greater<int>>
class RBTree
{
	typedef RBTreeNode<V> Node;
	typedef RBTree<K, V, KeyOfValue, Compare> self;
	typedef __rbtree_iterator<V, V&, V*> iterator;
	typedef __rbtree_iterator<V, const V&, const V*>const_iterator;

public:
	RBTree(const Compare& cmp =Compare())
		:_cmp(cmp), _header(nullptr)
	{
		//�����ڱ�λͷ��㣬ʹ�����������״�������ָ��ڵ�
		_header = new Node(V(), Black);
		_header->_left = _header;
		_header->_right = _header;
	}

	RBTree(const self& rbt)
	{
		for (auto value : rbt)
		{
			Insert(value);
		}
	}

public:
	iterator begin()
	{
		return iterator(Most_Left());
	}

	iterator end()
	{
		return iterator(_header);
	}

	const_iterator begin()const
	{
		return const_iterator(Most_Left());
	}

	const_iterator end()const
	{
		return const_iterator(_header);
	}

public:
	void Inorder()
	{
		_Inorder(GetRoot());
		std::cout << "nullptr" << std::endl;
	}

protected:
	void _Inorder(Node* root)
	{
		if (root == nullptr) return;
		_Inorder(root->_left);
		std::cout << root->_value << "->";
		_Inorder(root->_right);
	}
public:
	int Height()
	{
		return _Height(GetRoot());
	}
private:
	int _Height(Node* root)
	{
		if (root == nullptr) return 0;

		int LHeight = _Height(root->_left);
		int RHeight = _Height(root->_right);
		if (LHeight > RHeight) return LHeight + 1;
		else return RHeight + 1; //������������ȵ�����ϲ�������
	}

public:
	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (root->_color != Black)return false;//Υ�����ڵ�Ⱦɫ����
		
		int blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->_color == Black) blackCount++;
			cur = cur->_left;
		}

		blackCount++;//curΪnullptrʱҲ����һ���ڽڵ�

		return _IsValidRBTree(root,0,blackCount);
	}

protected:
	bool _IsValidRBTree(Node* root,int cnt,const int blackCount)
	{
		if (root == nullptr)
		{
			cnt++;
			if (cnt == blackCount)return true;
			else return false;//��ɫ�ڵ����������
		}
		//����븸����Ⱦɫ����
		if (root->_color == Red && root->_parent->_color == Red)
		{
			return false;
			//�����������ĺ�ɫ�ڵ�
		}

		if (root->_color == Black) cnt++;
		return _IsValidRBTree(root->_left, cnt, blackCount)
			&& _IsValidRBTree(root->_right, cnt, blackCount);
	}

public:
	bool Find(const K& key)
	{
		Node* prev = nullptr;
		Node* cur = GetRoot();
		while (cur)
		{
			if (_cmp(_kof(cur->_value), key))//��Ȼ���������
			{
				prev = cur;
				cur = left(cur);
			}
			else
			{
				cur = right(cur);//������������
			}
		}

		if (prev == nullptr || _cmp(_kof(prev->_value),key))//һֱ�����߻�һֱ������
		{
			return false;
		}
		else return true;//�ߵ�ͷ�Ĺ�������ת��һ��֮��һֱ������
	}

	bool Insert(const V& value)
	{
		Node* proot = GetRoot();
		if (proot == nullptr)//��Ϊ��
		{
			Node* newnode = new Node(value, Black);
			newnode->_parent = _header;
			_header->_parent = newnode;
			return true;
		}

		if (Find(_kof(value)))return false;//����Ѵ��ڣ�����ʧ��
		Node* cur = proot;
		Node* parent = proot->_parent;
		while (cur)
		{
			if (_cmp(_kof(cur->_value), _kof(value)))
			{
				//����������
				parent = cur;
				cur = left(cur);
			}
			else
			{
				//����������
				parent = cur;
				cur = right(cur);
			}
		}
		//��ʼ����
		Node* newnode = new Node(value, Red);
		if (_cmp(_kof(parent->_value),_kof(value) ))
		{
			//����������
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}

		cur = newnode;
		//��ʼ����
		while (parent != _header && parent->_color == Red)
		{
			Node* gp = parent->_parent;
			Node* uncle = nullptr;
			if (parent == gp->_left)uncle = gp->_right;
			else uncle = gp->_left;

			if (uncle && uncle->_color == Red)//���һ
			{
				parent->_color = Black;
				uncle->_color = Black;
				gp->_color = Red;

				cur = gp;
				parent = gp->_parent;
			}
			else if (cur == parent->_left && parent == gp->_left)
			{
				RotateR(cur);
				break;
			}
			else if (cur == parent->_right && parent == gp->_right)
			{
				RotateL(cur);
				break;
			}
			else if (cur == parent->_right && parent == gp->_left)
			{
				RotateLR(cur);
				break;
			}
			else if (cur == parent->_left && parent == gp->_right)
			{
				RotateRL(cur);
				break;
			}
		}

		Node* root = GetRoot();
		root->_color = Black;//�޸ĸ��ڵ���ɫ
		_header->_left = _header;
		_header->_right = _header;
		return true;
	}

private:
	void RotateR(Node* node)
	{
		if (node == nullptr)assert(false);
		Node* cur = node;
		Node* parent = cur->_parent;
		if (parent == nullptr) assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr) assert(false);

		//�������ṹ
		Node* ggp = gp->_parent;
		if (gp == ggp->_left)ggp->_left = parent;
		else ggp->_right = parent;
		parent->_parent = ggp;

		gp->_left = parent->_right;
		parent->_right = gp;
		gp->_parent = parent;

		if (gp == GetRoot())
		{
			SetRoot(parent);
		}

		//Ⱦɫ
		parent->_color = Black;
		gp->_color = Red;
	}

	void RotateL(Node* node)
	{
		Node* cur = node;
		if (cur == nullptr)assert(false);
		Node* parent = cur->_parent;
		if (parent == nullptr)assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr)assert(false);

		//�������ṹ
		Node* ggp = gp->_parent;
		if (ggp->_left == gp) ggp->_left = parent;
		else ggp->_right = parent;
		parent->_parent = ggp;
		
		gp->_right = parent->_left;
		parent->_left = gp;
		gp->_parent = parent;

		if (gp == GetRoot())
		{
			SetRoot(parent);
		}

		//Ⱦɫ
		parent->_color = Black;
		gp->_color = Red;
	}

	void RotateLR(Node* node)
	{
		Node* cur = node;
		if (cur == nullptr)assert(false);
		Node* parent = cur->_parent;
		if (parent == nullptr)assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr) assert(false);

		parent->_right = cur->_left;
		cur->_left = parent;
		parent->_parent = cur;
		cur->_parent = gp;
		gp->_left = cur;

		RotateR(parent);
	}

	void RotateRL(Node* node)
	{
		Node* cur = node;
		if (cur == nullptr)assert(false);
		Node* parent = cur->_parent;
		if (parent == nullptr)assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr) assert(false);

		parent->_left = cur->_right;
		cur->_right = parent;
		parent->_parent = cur;
		cur->_parent = gp;
		gp->_right = cur;

		RotateL(parent);
	}

private:
	Node* GetRoot()
	{
		if (_header->_parent == _header)return nullptr;
		else return _header->_parent;
	}

	Node* SetRoot(Node* root)
	{
		if (root == nullptr)return nullptr;
		root->_parent = _header;
		_header->_parent = root;
		return root;
	}

	Node* left(Node* root)
	{
		if (root == nullptr)return nullptr;
		return root->_left;
	}

	Node* right(Node* root)
	{
		if (root == nullptr)return nullptr;
		return root->_right;
	}

	Node* Most_Left()
	{
		Node* cur = GetRoot();
		Node* prev = _header;
		while (cur)
		{
			prev = cur;
			cur = left(cur);
		}
		return prev;
	}

	Node* Most_Right()
	{
		Node* cur = GetRoot();
		Node* prev = _header;
		while (cur)
		{
			prev = cur;
			cur = right(cur);
		}
		return prev;
	}

private:
	Compare _cmp;
	KeyOfValue _kof;
	Node* _header;
};