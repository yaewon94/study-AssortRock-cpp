#include <assert.h>
#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList list = {};

	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushFront(&list, 100);
	//Get(&list, 0);
	Reverse(&list);
	while (list.pHead->pNext)
	{
		std::cout << list.pHead->data << std::endl;
		list.pHead = list.pHead->pNext;
	}

	return 0;
}

// ����Ʈ�� �� �ڿ� ���� �߰�
void PushBack(LinkedList* list, const int Value)
{
	// 1. ���ο� ��� ����
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->data = Value;
	pNode->pNext = nullptr;

	// 2. ������ �Է��� �������� �ƴ��� üũ
	if (list->pHead == nullptr)
	{
		list->pHead = pNode;
	}
	else
	{
		// ����Ʈ�� ��ȸ�ؼ� ������ ��� ã��
		Node* pLast = list->pHead;
		while (pLast->pNext)
		{
			pLast = pLast->pNext;
		}

		// ������ ����� next �����ͷ� ���� ������ ��� ����Ŵ
		pLast->pNext = pNode;

		// ����Ʈ ũ�� ����
		list->currentCount++;
	}
}

// ����Ʈ�� �� �տ� ���� �߰�
void PushFront(LinkedList* list, const int Value)
{
	// 1. ��� ����
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->data = Value;
	pNode->pNext = list->pHead;

	// 2. ���� ������ ��带 ����Ʈ�� head �����Ͱ� ����Ű�� ��
	list->pHead = pNode;
	
	// 3. ����Ʈ ũ�� ����
	list->currentCount++;
}

// �ش� �ε����� �� ��������
// ����Ʈ�� ���� : �ش� �ε����� ���� �������� ����, ����Ʈ�� ó������ ��ȸ�ؾ� ��
int Get(LinkedList* list, const int Index)
{
	// ���� ����Ʈ ũ�⺸�� �ε����� ũ�� ������ ���
	assert(!(Index >= list->currentCount));

	Node* pNode = list->pHead;

	for (int i=0; i<Index; i++)
	{
		pNode = pNode->pNext;
	}

	return pNode->data;
}

// ����Լ��� �̿��ؼ� ����Ʈ �������� �����
void Reverse(Node* pNode, LinkedList* list)
{
	/*
	if (pNode->pNext != nullptr)
	{
		Node* pTemp = pNode->pNext;
		pTemp->pNext = pNode;
		list->pHead = pTemp;
		Reverse(pNode->pNext, list);
	}
	else
	{
		list->pHead = pNode;
	}
	*/

	if (pNode->pNext != nullptr)
	{
		bool isHead = false;
		if (pNode == list->pHead) isHead = true;
		Reverse(pNode->pNext, list);
		pNode->pNext->pNext = pNode;		// �ڱ��� ��������� ������ �ڱ⸦ ����Ű����
		if (isHead) pNode->pNext = nullptr;	// ������ ����� ������ nullptr�� �������
	}
	else
	{
		list->pHead = pNode;
	}
}

void Reverse(LinkedList* list)
{
	Reverse(list->pHead, list);
}