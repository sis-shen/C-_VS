#pragma once
#include <iostream>
#include <utility>

namespace key_value
{
	template<class K,class V>
	class BSTNode
	{
	public:
		BSTNode(const K& key = K(), const V& value = V())
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
		BSTNode<K, V>* _left;//ָ��������
		BSTNode<K, V>* _right;//ָ��������
		K _key;//�����
		V _value;//����ֵ
	};

	template<class K,class V>
	class BSTree
	{
		typedef BSTNode<K, V> Node;//ʹ��typedef�򻯴���
	public:
		BSTree() :_root(nullptr) {}//�ṩĬ�Ϲ��캯��

		BSTree(const BSTree<K, V>& bst)
		{
			_root = copy(bst._root);
		}

		~BSTree()
		{
			destroy(_root);
		}

		bool insert(const K& key, const V& value)
		{
			if (_root == nullptr)//����
			{
				_root = new Node(key, value);
				return true;
			}
			//====�޸ĵĲ���====
			PNN pnn = _find(key);

			Node* cur = pnn.first;
			Node* parent = pnn.second;

			if (cur != nullptr)//��key�Ѵ��ڣ�����ʧ��
			{
				return false;
			}
			//================
			
			//��ʱcurΪnullptr, parentΪcur�Ľ��
			if (key < parent->_key)parent->_left = new Node(key, value);
			else parent->_right = new Node(key, value);
			return true;//�ɹ�����
		}

		void in_order()
		{
			_in_order(_root);//��������
			std::cout << std::endl;
		}
	protected:
		void _in_order(Node* root)
		{
			if (root == nullptr) return;
			_in_order(root->_left);//�ȷ�������
			std::cout << root->_value << " ";//�ٷ��ʸ����
			_in_order(root->_right);//�������ҽ��
		}


	public:
		typedef std::pair< Node*, Node* > PNN;//�򻯴���
		bool find(const K& key)
		{
			return _find(key).first != nullptr;//����Ƿ��ҵ�
		}
	protected:
	
		PNN _find(const K& key)//����PNN���ڼ������ӿ�
		{
			if (_root == nullptr) return {nullptr,nullptr};
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (key < cur->_key)//key�ȵ�ǰ�ڵ�С������������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)//����������
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					//�ҵ�key
					return { cur,parent };
				}
			}
			//û�ҵ�key,curΪnullptr
			return { nullptr,parent };
		}
	public:

		bool erase(const K& key)
		{
			if (_root == nullptr)return false;//�����޷�ɾ��
			if (_root->_key == key && _root->_left == nullptr && _root->_right == nullptr)//ɾ�����һ�����
			{
				delete _root;
				_root = nullptr;
			}
			PNN pnn = _find(key);
			Node* cur = pnn.first;
			Node* parent = pnn.second;
			if (cur == nullptr) return false;//û�ҵ��ý��

			//�����cur�ز�Ϊ��
			if(cur->_left == nullptr)
			{
				if (cur == _root)//Ϊ���ڵ�ʱҪ�滻���ڵ�
				{
					Node* right = _root->_right;
					delete _root;
					_root = right;
				}
				//û������������ֱ���Ƴ����,���������ԭ���
				if (cur == parent->_left) parent->_left = cur->_right;
				else parent->_right = cur->_right;
				delete cur;
			}
			else if (cur->_right == nullptr)
			{
				if (cur == _root)
				{
					Node* left = _root->_left;
					delete _root;
					_root = left;
				}
				//ֱ�ӹ���������
				if (cur == parent->_left)parent->_left = cur->_left;
				else parent->_right = cur->_left;
			}
			else 
			{
				//�ҵ������������ҽ��
				Node* _cur = cur->_left;
				Node* _parent = cur;
				while (_cur->_right != nullptr)
				{
					_parent = _cur;
					_cur = _cur->_right;
				}
				//���߽��
				if (_cur == _parent->_left) _parent->_left = nullptr;
				else _parent->_right = nullptr;
				//��ȡcur�����ҽ��,���������߽��󣬷�����ܳ���ָ���Լ��Ľ��
				_cur->_left = cur->_left;
				_cur->_right = cur->_right;
				//����cur��λ��
				if (cur == _root)//ɾ�������ʱ
				{
					delete _root;
					_root = _cur;
				}
				else//ɾ����ͨ���ʱ
				{
					if (cur == parent->_left) parent->_left = _cur;
					else parent->_right = _cur;
					delete cur;
				}

			}
			return true;
		}


	protected:
		Node* copy(Node* root)
		{
			if (root == nullptr) return nullptr;//�ݹ����
			Node* pnode = new Node(root->_key, root->_value);//���ƽ��
			pnode->_left = copy(root->_left);
			pnode->_right = copy(root->_right);
			return pnode;
		}

		void destroy(Node* root)
		{
			if (root == nullptr) return;
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
	private:
		Node* _root;//ָ����ڵ��ָ����Ϊ��Ա����
	};
}