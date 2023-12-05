// 함수선언
// 선언, 정의를 동시에 할 수도 있음
int GetFactorial(int);

int main()
{
	int result = GetFactorial(3);

	return 0;
}

// 함수정의
// 재귀함수 : 간단한 문제 해결이 가능한 경우 사용 (ex.계층구조(트리) 순회)
int GetFactorial(int num)
{
	if (num == 1) return num;
	else num * GetFactorial(--num);
}
