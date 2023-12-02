// 함수선언
// 선언, 정의를 동시에 할 수도 있음
int pow(int, int);

int main()
{
	int result = pow(2, 10);

	return 0;
}

// 함수정의
int pow(int num, int exp)
{
	int result = 1;

	for (int i=0; i<exp; i++)
	{
		result *= num;
	}

	return result;
}