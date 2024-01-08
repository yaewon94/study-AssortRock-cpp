#pragma once
#include "assert.h"
#include <string>

//
// C++ list.h 에 구현되어 있음
//

// 템플릿에 넣을 타입 정의
// ex. 플레이어 구조체
struct Player
{
	wchar_t name[20];
	int level;
	int hp;
	Player(const wchar_t* name, int level, int hp) : level(level), hp(hp) 
	{
		wcscpy_s(this->name, name);
	}
};

// 링크드 리스트의 각 노드
template<typename T>
struct Node
{
	T data;
	Node<T>* pPrev;
	Node<T>* pNext;
	Node() {}
	Node(const T& data, Node<T>* pPrev, Node<T>* pNext) : data(data), pPrev(pPrev), pNext(pNext) {}
};

// 링크드 리스트 역할을 할 수 있는 자료형 정의
//struct LinkedList
template<typename T> 
class LinkedList
{
	private:
		//void Reverse(Node*);
		Node<T>* pHead;
		Node<T>* pTail;	// head, tail 중 더 효율이 좋은 쪽으로 가서 데이터 접근 가능
		int currentCount;

	public:
		// 생성자
		LinkedList() : pHead(nullptr), pTail(nullptr), currentCount(0) {}
		
		// 소멸자
		~LinkedList() 
		{
			// 리스트의 모든 노드 순회하면서 동적으로 할당된 메모리 해제
			Node<T>* node = pHead;
			while (node->pNext)
			{
				Node<T>* nextNode = node->pNext;
				delete node;
				node = nextNode;
			}
		}

		// 리스트가 비어있는지 여부
		bool isEmpty() { return currentCount == 0 ? true : false; }

		// 리스트 현재 크기 반환
		int GetCount() { return currentCount; }

		// 리스트 맨 뒤에 데이터 삽입
		void PushBack(const T&);

		// 리스트 맨 앞에 데이터 삽입
		void PushFront(const T&);

		// 리스트 맨 앞의 데이터 제거
		T PopFront();
		
		// 리스트 맨 뒤의 데이터 제거
		T PopBack();
		
		// 반복자 클래스
		class iterator
		{
			// 친구 클래스 선언
			// 친구 클래스로 선언한 클래스는 나의 private 멤버에 접근 가능
			friend class LinkedList<T>;

			// private 멤버
			private:
				LinkedList<T>* list;
				Node<T>* node;
			public:
				// 생성자
				iterator(LinkedList<T>* list, Node<T>* node) : list(list), node(node) {}
				
				// 참조 연산자 오버로딩
				T& operator*()
				{
					assert(list && node);
					return node->data;
				}

				// 전위 연산자 오버로딩
				iterator& operator++()
				{
					assert(list && node);
					node = node->pNext;
					return *this;
				}

				iterator& operator--()
				{
					assert(list); // list 가 null 인 경우
					assert(list->pHead != node); // begin iterator 인 경우

					if (node == nullptr) node = list->pTail; // end iterator 인 경우
					else node = node->pPrev;

					return *this;
				}

				// 후위 연산자 오버로딩
				// 후위 연산자 : 값을 먼저 lvalue에 대입하고 rvalue를 증가 또는 감소시킴
				// 연산자 오버로딩은 연산자처럼 쓰는거지, 결국 멤버함수 이므로 연산자 우선순위를 바꿀 수 없다
				// => 무조건 연산자 오버로딩 멤버함수가 호출되고나서 = 연산자 순서로 가게 됨
				iterator operator++ (int)
				{
					iterator copyiter = *this; // 복사생성자 호출됨 : iterator copyiter(*this) 와 같음
					++(*this);
					return copyiter; // 지역변수를 리턴시킬 것이므로 iterator&가 아닌 iterator로 반환
				}
				
				iterator operator-- (int)
				{
					iterator copyiter = *this;
					--(*this);
					return copyiter;
				}

				// == 연산자 오버로딩
				bool operator== (const iterator& other)
				{
					if (list == other.list && node == other.node) return true;
					return false;
				}

				// != 연산자 오버로딩
				bool operator!= (const iterator& other)
				{
					return !(*this == other);
				}
		};

		iterator begin() { return iterator(this, pHead); }
		iterator end() { return iterator(this, nullptr); }
		iterator insert(iterator iterator, const T& data);
		iterator erase(iterator iterator);
};

/*
void PushBack(LinkedList*, const int);
void PushFront(LinkedList*, const int);
int Get(LinkedList*, const int);
void Reverse(LinkedList*);
*/

// 데이터 맨 뒤에 삽입
template<typename T>
void LinkedList<T>::PushBack(const T& data)
{
	// 1. 새로운 노드 생성
	Node<T>* node = new Node<T>(data, nullptr, nullptr);

	// 2. 처음 삽입하는 경우
	if (pHead == nullptr)
	{
		pHead = node;
		pTail = node;
	}
	// 그 외
	else
	{
		// 기존의 맨 마지막 노드를 새로운 노드의 앞 노드로 지정
		pTail->pNext = node;
		node->pPrev = pTail;
		pTail = node;
	}

	// 3. 리스트 카운트 증가
	currentCount++;
}

// 데이터 맨 앞에 삽입
template<typename T>
void LinkedList<T>::PushFront(const T& data)
{
	// 1. 새로운 노드 생성
	Node<T>* node = new Node<T>(data, nullptr, pHead);

	// 2. 데이터를 새로 삽입하는 경우
	if (pHead == nullptr) pTail = node; // 새로운 노드를 테일노드로 지정
	// 그 외
	else pHead->pPrev = node; // 새로운 노드를 기존의 헤드노드의 앞 노드로 지정

	// 3. 새로운 노드를 헤드노드로 지정
	pHead = node;

	// 4. 리스트 카운트 증가
	currentCount++;
}

// 리스트 맨 앞의 데이터 제거
template<typename T>
T LinkedList<T>::PopFront()
{
	// 1. 헤드가 널포인터인 경우 예외처리
	assert(pHead);

	// 2. 헤드가 들고있는 데이터를 복사해둔다
	T data = pHead->data;
	
	// 3. 헤드의 다음이 존재하는지 여부 체크
	if(pHead->pNext == nullptr)
	{
		delete pHead;
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		pHead = pHead->pNext;
		delete pHead->pPrev;
		pHead->pPrev = nullptr;
	}
	
	// 4. 리스트 카운트 감소
	--currentCount;

	// 5. 삭제한 노드에 있던 반환
	// 노드는 삭제되었으므로 & 타입으로 반환하면 안된다
	return data;
}

// 현재 iterator 위치에 데이터 삽입
// 내부클래스를 반환 타입으로 할 경우 typename 키워드를 붙여야 함
template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator target, const T& data)
{
	// 1. target iterator 가 해당 리스트를 가리키는 것인지 확인
	assert(this == target.list);

	// 2. 맨 앞에 삽입하는 경우
	if (pHead == target.node)
	{
		PushFront(data);
		return iterator(this, pHead);
	}
	// 그 외
	else
	{
		// 삽입할 새로운 노드 생성
		Node<T>* newNode = new Node<T>(data, target.node->pPrev, target.node);
		target.node->pPrev->pNext = newNode;
		target.node->pPrev = newNode;

		// 리스트 카운트 증가
		++currentCount;
		return iterator(this, newNode);
	}
}

// 현재 iterator위치의 노드를 제거
template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(iterator target)
{
	// 1. target iterator가 해당 리스트를 가리키는 것인지 확인
	assert(target.list == this);

	// 2. target이 가리키는 노드 연결 조정
	// 삭제할 노드가 맨 앞인 경우
	if (target.node == pHead) 
	{
		// 두번째 노드를 헤드로 지정
		pHead = target.node->pNext;

		if (pHead == nullptr) pTail = nullptr; // 리스트의 데이터가 1개인 경우 테일도 널포인터로 지정
		else pHead->pPrev = nullptr;
	}
	// 삭제할 노드가 맨 뒤인 경우
	else if (target.node == pTail)
	{
		// 삭제할 노드의 전 노드를 테일로 지정
		pTail = target.node->pPrev;
		pTail->pNext = nullptr;
	}
	// 그 외
	else
	{
		target.node->pPrev->pNext = target.node->pNext;
		target.node->pNext->pPrev = target.node->pPrev;
	}

	// 3. 삭제할 노드의 다음을 가리키는 iterator 생성
	iterator nextiter(this, target.node->pNext);

	// 4. 삭제할 노드의 메모리 해제
	delete target.node;

	// 5. 삭제한 노드의 다음을 가리키는 iterator 리턴
	return nextiter;
}
