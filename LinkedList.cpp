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

// 리스트의 맨 뒤에 원소 추가
void PushBack(LinkedList* list, const int Value)
{
	// 1. 새로운 노드 생성
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->data = Value;
	pNode->pNext = nullptr;

	// 2. 데이터 입력이 최초인지 아닌지 체크
	if (list->pHead == nullptr)
	{
		list->pHead = pNode;
	}
	else
	{
		// 리스트를 순회해서 마지막 노드 찾기
		Node* pLast = list->pHead;
		while (pLast->pNext)
		{
			pLast = pLast->pNext;
		}

		// 마지막 노드의 next 포인터로 새로 생성한 노드 가리킴
		pLast->pNext = pNode;

		// 리스트 크기 증가
		list->currentCount++;
	}
}

// 리스트의 맨 앞에 원소 추가
void PushFront(LinkedList* list, const int Value)
{
	// 1. 노드 생성
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->data = Value;
	pNode->pNext = list->pHead;

	// 2. 새로 생성된 노드를 리스트의 head 포인터가 가리키게 함
	list->pHead = pNode;
	
	// 3. 리스트 크기 증가
	list->currentCount++;
}

// 해당 인덱스의 값 가져오기
// 리스트의 단점 : 해당 인덱스의 값을 가져오기 위해, 리스트의 처음부터 순회해야 함
int Get(LinkedList* list, const int Index)
{
	// 현재 리스트 크기보다 인덱스를 크게 지정한 경우
	assert(!(Index >= list->currentCount));

	Node* pNode = list->pHead;

	for (int i=0; i<Index; i++)
	{
		pNode = pNode->pNext;
	}

	return pNode->data;
}

// 재귀함수를 이용해서 리스트 역순으로 만들기
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
		pNode->pNext->pNext = pNode;		// 자기의 다음노드의 다음이 자기를 가리키도록
		if (isHead) pNode->pNext = nullptr;	// 마지막 노드의 다음을 nullptr로 만들어줌
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