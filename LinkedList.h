#pragma once

//
// C++ list.h �� �����Ǿ� ����
//

// �ѹ��� ��ũ�� ����Ʈ�� ��� (int�� ����)
struct Node
{
	int data;
	Node* pNext;
};

// ��ũ�� ����Ʈ ������ �� �� �ִ� �ڷ��� ����
struct LinkedList
{
	Node* pHead;	// ù��° ���
	int currentCount;
};

void PushBack(LinkedList*, const int);
void PushFront(LinkedList*, const int);
int Get(LinkedList*, const int);
void Reverse(LinkedList*);