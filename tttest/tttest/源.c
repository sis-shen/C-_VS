//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////��Ŀһ
//typedef struct ListNode
//{
//	int data;//�洢����
//	struct ListNode* next;//����ָ��
//	struct ListNode* prev;//ǰ��ָ��
//
//}Node;
//Node* NodeCreate(int x)
//{
//	Node* newnode = (Node*)malloc(sizeof(Node));
//	if (newnode == NULL)
//	{
//		perror("malloc failed!\n");
//		return NULL;
//	}
//	newnode->data = x;//�洢����
//	newnode->next = newnode->prev = NULL;//ǰ��ָ�����Ϊ��
//	return newnode;
//}
//
//Node* ListInit(Node* head)
//{
//	head->next = head->prev = NULL;//ǰ���ָ������
//	return head;
//}
//
//void push_back(Node* head, int x)
//{
//	Node* newnode = NodeCreate(x);//�����½ڵ�
//	Node* cur = head;
//	if (head == NULL)
//	{
//		head = newnode;//������Ϊ��ֱ���
//
//	}
//	else
//	{
//		while (cur->next != NULL)
//		{
//			cur = cur->next;
//		}
//		cur->next = newnode;
//		newnode->prev = cur;//ǰ������
//		newnode->next = head;//β�ڵ����ָ��ָ��ͷ�ڵ�
//		head->prev = newnode;//ͷ�ڵ�ǰ��ָ��ָ��β�ڵ�
//	}
//}
//
//void FirstPrint(Node* head)
//{
//	Node* cur = head;
//	while (cur->next != head)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//}
//void LastPrint(Node* head)
//{
//	Node* cur = head->prev;
//	while (cur->prev != head)
//	{
//		printf("%d ", cur->data);
//		cur = cur->prev;
//	}
//}
//int main()
//{
//	Node phead;
//	Node* head = &phead;
//	ListInit(head);//��ʼ������
//	push_back(head, 1);
//	push_back(head, 2);
//	push_back(head, 3);
//	push_back(head, 4);
//	FirstPrint(head);
//	LastPrint(head);
//	return 0;
//}