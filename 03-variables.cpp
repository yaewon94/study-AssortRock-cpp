#include <iostream>

// 메모리 영역
// 1. 스택 : 함수, 지역변수
// 2. 데이터 : 전역변수
// 3. 힙 : 동적할당 영역
// 4. ROM : 코드 및 초기화 데이터

// 전역변수
int i = 0;

int main()
{
	// main() 내의 지역변수
	int i = 0;

	return 0;
}