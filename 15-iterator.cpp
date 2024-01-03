#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>
using std::cout;
using std::wcout;
using std::vector;

int main()
{
	// iterator(반복자)
	// 컨테이너가 가지고 있는 데이터를 가리키는 포인터를 통해 순차적으로 접근
	// 컨테이너마다 전체 데이터를 순회하는 방법이 각각 달라도, 통일성 있는 코드로 데이터에 접근 가능
	// 각 컨테이너 클래스의 내부클래스로 구현

	//
	// ex. vector 예시
	vector<int> vec(5);
	
	/*
	for (size_t i=0; i<vec.size(); i++)
	{
		cout << vec.at(i) << "\n";
	}
	*/

	vector<int>::iterator iter = vec.begin();	// begin() : 컨테이너의 시작 주소를 반환
	while (iter != vec.end())					// end() : 컨테이너의 끝을 반환
	{
		//cout << *iter++ << "\n";
	}

	//
	// ex. 사용자 정의 컨테이너 예시
	DynamicArray<int> dArr(3);
	DynamicArray<int>::iterator darrIter = dArr.begin();

	//wcout << "리턴된 iterator 주소값 = " << &darrIter << "\n";
	dArr.Push(1);
	dArr.Push(2);
	dArr.Push(3);
	// iterator 참조연산자 오버로딩
	*darrIter;		// 값 읽기
	*darrIter = 0;	// 값 대입 (return& 타입이여야 가능)

	for (; darrIter!=dArr.end(); ++darrIter)
	while(darrIter != dArr.end())
	{
		//cout << *iter++ << "\n";
	}

	//
	// ex. 사용자 정의 컨테이너 예시
	LinkedList<Player> playerList;

	playerList.PushBack(Player(L"암내원", 1, 10));
	playerList.PushBack(Player(L"포비", 1, 100));
	playerList.PushBack(Player(L"메이플", 100, 100));
	playerList.PushFront(Player(L"돔마", 1, 200));

	LinkedList<Player>::iterator listiter = playerList.begin();
	const Player& player = *listiter;

	++(++listiter);
	playerList.insert(listiter, Player(L"요요", 1, 50));
	LinkedList<Player>::iterator listiter2 = listiter++;

	listiter = playerList.begin();
	playerList.erase(listiter);

	return 0;
}