#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>
using std::cout;
using std::wcout;
using std::vector;

int main()
{
	// iterator(�ݺ���)
	// �����̳ʰ� ������ �ִ� �����͸� ����Ű�� �����͸� ���� ���������� ����
	// �����̳ʸ��� ��ü �����͸� ��ȸ�ϴ� ����� ���� �޶�, ���ϼ� �ִ� �ڵ�� �����Ϳ� ���� ����
	// �� �����̳� Ŭ������ ����Ŭ������ ����

	//
	// ex. vector ����
	vector<int> vec(5);
	
	/*
	for (size_t i=0; i<vec.size(); i++)
	{
		cout << vec.at(i) << "\n";
	}
	*/

	vector<int>::iterator iter = vec.begin();	// begin() : �����̳��� ���� �ּҸ� ��ȯ
	while (iter != vec.end())					// end() : �����̳��� ���� ��ȯ
	{
		//cout << *iter++ << "\n";
	}

	//
	// ex. ����� ���� �����̳� ����
	DynamicArray<int> dArr(3);
	DynamicArray<int>::iterator darrIter = dArr.begin();

	//wcout << "���ϵ� iterator �ּҰ� = " << &darrIter << "\n";
	dArr.Push(1);
	dArr.Push(2);
	dArr.Push(3);
	// iterator ���������� �����ε�
	*darrIter;		// �� �б�
	*darrIter = 0;	// �� ���� (return& Ÿ���̿��� ����)

	for (; darrIter!=dArr.end(); ++darrIter)
	while(darrIter != dArr.end())
	{
		//cout << *iter++ << "\n";
	}

	//
	// ex. ����� ���� �����̳� ����
	LinkedList<Player> playerList;

	playerList.PushBack(Player(L"�ϳ���", 1, 10));
	playerList.PushBack(Player(L"����", 1, 100));
	playerList.PushBack(Player(L"������", 100, 100));
	playerList.PushFront(Player(L"����", 1, 200));

	LinkedList<Player>::iterator listiter = playerList.begin();
	const Player& player = *listiter;

	++(++listiter);
	playerList.insert(listiter, Player(L"���", 1, 50));
	LinkedList<Player>::iterator listiter2 = listiter++;

	listiter = playerList.begin();
	playerList.erase(listiter);

	return 0;
}