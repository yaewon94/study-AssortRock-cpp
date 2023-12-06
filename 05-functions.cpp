// 함수선언
// 선언, 정의를 동시에 할 수도 있음
// 함수 호출부분보다 선언부분이 항상 위에 있어야 함 ! (컴파일러가 위에서 아래로 읽으므로)
// 가독성을 위해 선언부분은 헤더파일로 따로 묶음
//int GetFactorial(int);
//int GetFibonacci(int);
#include "FunctionTest.h"

int main()
{
	int result1 = GetFactorial(3);
	int result2 = GetFibonacci(10);

	return 0;
}

// 재귀함수 : 간단하게 문제 해결이 가능한 경우 사용
// 장점 : 코드의 간결성, 직관성
// 단점 : 느림
// ex. 팩토리얼
int GetFactorial(int num)
{
	if (num == 1) return num;
	else return num * GetFactorial(--num);
}
// ex. 피보나치 수열 : num이 클 경우 적합하지 않음 (함수 호출 횟수 : 2^1 +2^2 + ... + 2^num)
// 1 1 2 3 5 8 13 21 ...
int GetFibonacci(int num)
{
	if (num == 1 || num == 2) return 1;
	else return GetFibonacci(num-1) + GetFibonacci(num-2);
}
