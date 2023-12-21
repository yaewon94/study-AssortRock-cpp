#pragma once

//
// C++ list.h 에 구현되어 있음
//

// 한방향 링크드 리스트의 노드 (int형 예시)
struct Node
{
	int data;
	Node* pNext;
};

// 링크드 리스트 역할을 할 수 있는 자료형 정의
//struct LinkedList
class LinkedList
{
	private:
		void Reverse(Node*);

	public:
		Node* pHead;	// 첫번째 노드
		int currentCount;
		~LinkedList();
		void PushBack(const int);
		void PushFront(const int);
		int Get(const int);
		void Reverse();
};

/*
void PushBack(LinkedList*, const int);
void PushFront(LinkedList*, const int);
int Get(LinkedList*, const int);
void Reverse(LinkedList*);
*/
