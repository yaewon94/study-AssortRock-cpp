#include <iostream>

void Set(int* pVal)
{
	*pVal = 10;
}

void Set(int& ref)
{
	ref = 100;
}


int main()
{
	int i = 0;

	Set(&i);	// 매개변수가 int* 인 함수 호출
	Set(i);		// 매개변수가 int& 인 함수 호출


	// C++ 레퍼런스는 포인터와 동작 원리가 같다 (주소를 받아서 원본에 접근)
	int iData = 0, iData2 = 0;

	// int& 는 int* const와 유사함
	// => 참조할 대상을 바꿀 수 없음
	int& ref = iData;
	ref = 20;
	ref = iData2; // 참조 대상을 바꾸는게 아니라, ref 에 값을 입력

	// const int& 는 const int* const 와 유사
	// => 참조할 대상을 바꿀 수 없고, 참조 대상 원본도 수정 불가
	// => 주로 규모가 큰 타입 변수를 읽기 전용으로 사용할 때 사용
	const int& cRef = iData;
	//cRef = 100;
	int value = cRef;

	return 0;
}