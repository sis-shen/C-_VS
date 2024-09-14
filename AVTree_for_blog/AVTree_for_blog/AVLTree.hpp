#pragma once

#include <utility>
#include <iostream>
#include <cassert>

template <class K,class V>
struct AVLTreeNode
{
	typedef AVLTreeNode<K, V> Node;//ʹ��typedef�򻯴���
	Node* _left;                   
	Node* _right;
	Node* _parent;
	std::pair<K, V> _kv; //�ڵ㴢��ļ�ֵ��
	int _bf;// ballance factor ƽ������

	//���캯���������ṩ�޲ε�Ĭ�Ϲ��캯��
	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V,class Cmp = std::greater<K>>//ʹ�÷º���
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
	typedef std::pair<K, V> PKV;
public:
	AVLTree() :_root(nullptr) {}//Ĭ�Ϲ��캯��

	void Inorder()
	{
		_Inorder(_root);
		std::cout<<"nullptr" << std::endl;
	}

protected:
	void _Inorder(Node* root)
	{
		if (root == nullptr) return;
		_Inorder(root->_left);
		std::cout << root->_kv.second << "->";
		_Inorder(root->_right);
	}
public:
	int Height()
	{
		return _Height(_root);
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
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	bool _IsBalance(Node* root)
	{
		if (root == nullptr) return true;
		bool left = _IsBalance(root->_left);
		bool right = _IsBalance(root->_right);

		if (left == false || right == false) return false;//���ж���������

		int LHeight = _Height(root->_left);
		int RHeight = _Height(root->_right);

		if (LHeight - RHeight >= 2 || LHeight - RHeight <= -2)return false;//����ж���
		else return true;
	}

public:
	bool Insert(const PKV& kv)
	{
		Cmp cmp;//�º���ʵ����һ������
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		//Ѱ�Ҳ���λ��
		while (cur)
		{
			if (cur->_kv.first == kv.first)
			{
				//�ü��µĽڵ��Ѵ��ڣ�������ͻ
				return false;
			}
			else if (cmp(cur->_kv.first, kv.first))//���Ƚڵ�"��"
			{
				parent = cur;
				cur = cur->_left;
			}
			else //���Ƚڵ�С
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		//��ʼ����
		Node* node = new Node(kv);
		if (cmp(parent->_kv.first, kv.first))//Ӧ�ò������
		{
			parent->_left = node;
			node->_parent = parent;
			parent->_bf -= 1;//_bfԽС��������Խ��
		}
		else //����������
		{
			parent->_right = node;
			node->_parent = parent;
			parent->_bf += 1;//_bfԽ��������Խ��
		}
		//������ɣ�׼����ʼά��ƽ��
		while (true)
		{
			if (parent->_bf == 0)break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//�����߶�����
				node = parent;
				parent = parent->_parent;
				if (parent == nullptr)break;//�ߵ����ڵ���
				if (node == parent->_left)
				{
					parent->_bf -= 1;
				}
				else if (node == parent->_right)
				{
					parent->_bf += 1;
				}
				else
				{
					assert(false);//�Ƿ����
				}
			}
			else if (parent->_bf == -2)
			{
				if (parent->_left->_bf == 0)
				{
					assert(false);//�Ƿ����,��������������ͬʱ����
				}
				else if (parent->_left->_bf == -1)
				{
					//����������������
					RotateR(parent);
					break;
				}
				else if (parent->_left->_bf == 1)
				{
					//����������������
					RotateLR(parent);
				}
			}
			else if (parent->_bf == 2)
			{
				if (parent->_right->_bf == 0)
				{
					assert(false);//�Ƿ����,��������������ͬʱ����
				}
				else if (parent->_right->_bf == 1)
				{
					//����������������
					RotateL(parent);
					break;
				}
				else if (parent->_right->_bf == -1)
				{
					//����������������
					RotateRL(parent);
					break;
				}
			}
			else
			{
				assert(false);//�Ƿ����
			}
		}
		return true;
	}

private:
	void RotateR(Node* parent)
	{
		if (parent == nullptr) return;
		Node* child = parent->_left;

		//ά�����Ľṹ
		parent->_left = child->_right;//����������������
		child->_right = parent;//�ع����ṹ
		Node* grandParent = parent->_parent;//ά���游�ڵ�
		child->_parent = grandParent;//ά��child
		parent->_parent = child;
		if (grandParent)//������Ǹ��ڵ�
		{
			//ά�����ڵ�ĸ��ڵ������
			if (parent == grandParent->_left) grandParent->_left = child;
			else grandParent->_right = child;
		}
		
		//ά��ƽ������
		if (child->_bf == -1)
		{
			child->_bf = 0;
			parent->_bf = 0;
		}
		else if (child->_bf == 0)
		{
			assert(false);//�����ڵ����
		}
		else
		{
			assert(false);//��Ҫ�����תʱ��Ӧ�õ��øú���
		}

		if (parent == _root)
		{
			_root = child;//���¸��ڵ�
		}
	}

private:
	void RotateL(Node* parent)
	{
		if (parent == nullptr) return;
		Node* child = parent->_right;
		//ά�����ṹ
		parent->_right = child->_left;//��������
		child->_left = parent;//�ع����ṹ
		Node* grandParent = parent->_parent;//ά���游�ڵ�
		child->_parent = grandParent;//ά��_parent
		parent->_parent = child;//ά��_parent
		if (grandParent)//������Ǹ��ڵ�
		{
			//ά���游�ڵ������
			if (parent == grandParent->_left) grandParent->_left = child;
			else grandParent->_right = child;
		}

		//ά��ƽ������
		if (child->_bf == 1)
		{
			child->_bf = 0;
			parent->_bf = 0;
		}
		else if (child->_bf == 0)
		{
			assert(false);//�����ڵ����
		}
		else
		{
			assert(false);//��Ҫ�����תʱ��Ӧ�õ��øú���
		}
		if (parent == _root)
		{
			_root = child;//���¸��ڵ�
		}
	}

private:
	void RotateLR(Node* parent)
	{
		if (parent == nullptr) return;//�������
		Node* Lchild = parent->_left;
		if (Lchild == nullptr) return;//�������
		Node* Rchild = Lchild->_right;

		//����ת������

		//ά�����ṹ
		Lchild->_right = Rchild->_left;
		Rchild->_left = Lchild;
		Lchild->_parent = Rchild;
		parent->_left = Rchild;
		Rchild->_parent = parent;

		//ά��_bf
		if (Lchild->_bf == 1)
		{
			Lchild->_bf = -1;
		}
		else
		{
			//_bf == -1 �� 0���ǷǷ���
			assert(false);
		}

		//��������ת
		Node* child = parent->_left;
		
		//ά�����ṹ
		parent->_left = child->_right;
		child->_right = parent;

		Node* grandParent = parent->_parent;
		child->_parent = grandParent;
		parent->_parent = child;

		if (grandParent)//���Ǹ��ڵ�
		{
			if (parent == grandParent->_left)grandParent->_left = child;
			else grandParent->_right = child;
		}

		//ά��_bf
		parent->_bf = -1;
		child->_bf = 0;
		
		if (parent == _root)
		{
			_root = child;//���¸��ڵ�
		}
	}

private:
	void RotateRL(Node* parent)
	{
		//��������ת����
		Node* Rchild = parent->_right;
		Node* Lchild = Rchild->_left;

		//ά�����ṹ
		Rchild->_left = Lchild->_right;
		Lchild->_right = Rchild;
		Rchild->_parent = Lchild;
		Lchild->_parent = parent;
		parent->_right = Lchild;

		//ά��_bf
		if (Rchild->_bf == -1)
		{
			Rchild->_bf = 0;
		}
		else
		{
			assert(false);//�Ƿ������
		}

		//��������ת
		Node* child = parent->_right;

		parent->_right = child->_left;//����������
		child->_left = parent;
		parent->_parent = child;
		Node* grandParent = parent->_parent;
		child->_parent = grandParent;
		
		if (grandParent)//������Ǹ��ڵ�
		{
			if (parent == grandParent->_left)grandParent->_left = child;
			else grandParent->_right = child;
		}

		//ά��_bf
		parent->_bf = -1;
		child->_bf = 0;

		if (parent == _root)
		{
			_root = child;//���¸��ڵ�
		}
	}

private:
	Node* _root;
};