#include <stdio.h>

// 배열 : 같은 타입의 변수 여러 개 모음
int main()
{
	//
	// 1. 배열 선언, 초기화
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };	// 모든 값 초기화
	int arr0[] = { 1,2,3 };		// 배열 크기를 명시하지 않아도 초기화 가능
	int arr1[3] = {};			// 배열의 모든 원소 0으로 초기화
	int arr2[3] = { 1,2 };		// 초기화되지 않은 나머지 원소는 0으로 초기화
	
	// 변수를 배열크기로 지정할 수 없음
	// => 변수로 크기 지정을 하면 런타임에 배열 크기가 확정되므로, 배열이 선언된 메모리 영역 크기 계산 불가
	int arraySize;
	scanf_s("%d", &arraySize);
	//int arr3[arraySize] = {};

	//
	// 2. 배열 접근
	// 인덱스 : 0부터 시작
	// 해당 인덱스를 탐색하는데 걸리는 시간 : O(1) (상수시간 => 매우빠름)
	// 배열의 이름은 해당 배열의 시작위치(주소)
	// 메모리 구조 : 연속적인 구조
	// => 원소의 삽입, 삭제가 일어날 때 마다 기존 데이터의 이동이 일어나야 함
	// => 삽입, 삭제가 빈번하게 일어나는 경우는 리스트를 사용하는 것이 효율적
	arr1[0] = 10;

	//
	// ex. 정렬기능
	// O(N^2) : 버블정렬, 삽입정렬
	// O(N * logN) : 퀵정렬, 합병정렬, 힙정렬
	// 안정/불안정 정렬 : 이전 정렬 순서가 남아있는지 여부
	// ex. 버블정렬 구현
	int Length = sizeof(arr) / sizeof(int);
	
	for (int i=Length-1; i>0; i--)
	{
		bool isSorted = true;

		for (int j=0; j<i; j++)
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

	return 0;
}
