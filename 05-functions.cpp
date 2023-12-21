// 함수선언
// 선언, 정의를 동시에 할 수도 있음
// 함수 호출부분보다 선언부분이 항상 위에 있어야 함 ! (컴파일러가 위에서 아래로 읽으므로)
// 가독성을 위해 선언부분은 헤더파일로 따로 묶음
//int GetFactorial(int);
//int GetFibonacci(int);
//#include "FunctionTest.h"
#include <iostream>

void BubbleSort(int*, const int);

// 함수 오버로딩 : 함수의 이름은 같고 매개변수를 다르게 해서, 다른 기능을 하는 함수를 만들 수 있음
//void InsertSort(const int*, int*, const int, const int);
void InsertSort(int*, int*, const int, const int);
void InsertSort(int*, int);

int main()
{
	//int result1 = GetFactorial(3);
	//int result2 = GetFibonacci(10);

	int arr[5] = { 1, 5, 3, 2, 4 };
	const int Length = sizeof(arr) / sizeof(int);
	//BubbleSort(arr, Length)
	//const int Value = 0;
	//int* result = new int[Length + 1] {};
	//InsertSort(arr, result, Length, Value);
	InsertSort(arr, Length);

	/*
	std::cout << "결과출력" << std::endl;
	for (int i=0; i<Length+1; i++)
	{
		std::cout << result[i] << std::endl;
	}
	*/

	//delete[] result;

	return 0;
}

// 재귀함수 : 간단하게 문제 해결이 가능한 경우 사용
// 장점 : 코드의 간결성, 직관성
// 단점 : 느림
// ex. 팩토리얼
/*
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
*/

// 매개변수
// 
// 1. 값에 의한 전달
// 함수를 호출할 때 매개변수들을 복사해서 넘겨줌
// => 매개변수로 전달한 원본 변수들의 값에 영향 없음
// 
// 2. 참조에 의한 전달 (08-pointers.cpp 참조)
// 함수를 호출할 때 매개변수의 주소값(또는 포인터)을 넘겨줌
// => 함수 내부에서 매개변수 변경 시, 매개변수로 전달한 원본 변수의 값도 변경됨

// 버블정렬
void BubbleSort(int* arr, const int Length)
{
	for (int i=Length-1; i>0; i--)
	{
		bool isSorted = true;

		for (int j = 0; j<i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSorted = false;
			}
		}

		if (isSorted) break;
	}
}

/*
// 삽입정렬 (방법 1 : 삽입 후 정렬)
void InsertSort(const int* oldArr, int* newArr, const int Length, const int Value)
{
	// 1. 새로운 배열에 기존 값 저장
	for (int i=0; i<Length; i++)
	{
		newArr[i] = oldArr[i];
	}

	// 2. 마지막 인덱스에 새로운 값 삽입
	newArr[Length] = Value;

	// 3. 버블정렬 호출
	BubbleSort(newArr, Length + 1);
}
*/


// 삽입정렬 (방법 2 : 정렬 후 삽입)
void InsertSort(int* oldArr, int* newArr, const int Length, const int Value)
{
	// 1. 버블정렬 호출
	BubbleSort(oldArr, Length);

	// 2. 삽입할 값과 배열의 값들을 비교
	for (int i = 0; i < Length + 1; i++)
	{
		// 새로운 배열에 기존의 값들을 넣음
		newArr[i] = oldArr[i];

		// 삽입하려는 값이 해당 인덱스의 값보다 작은 경우
		if (Value < oldArr[i])
		{
			newArr[i] = Value;

			// 기존의 값들을 한칸씩 뒤로 이동
			for (int j=i; j<Length; j++)
			{
				newArr[j + 1] = oldArr[j];
			}

			break;
		}
	}
}

// 삽입정렬 [선생님 풀이]
void InsertSort(int* arr, int count)
{
	for (int i=1; i<count; i++)
	{
		int temp = arr[i];

		int j = i - 1;
		for (; j>=0; j--)
		{
			if (temp < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				arr[j + 1] = temp;
				break;
			}
		}

		arr[j + 1] = temp;
	}
}
