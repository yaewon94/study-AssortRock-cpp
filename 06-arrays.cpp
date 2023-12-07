// 배열 : 같은 타입의 변수 여러 개 모음
#include <iostream>

int main()
{
	// 배열 선언, 초기화
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };	// 모든 값 초기화
	int arr1[3] = {};			// 배열의 모든 원소 0으로 초기화
	int arr2[3] = { 1,2 };		// 초기화되지 않은 나머지 원소는 0으로 초기화

	// 배열 값 변경
	// 인덱스 : 0부터 시작
	// 배열의 이름은 해당 배열의 시작위치(주소)
	// 메모리 구조 : 연속적인 구조
	arr1[0] = 10;

	// 정렬기능
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
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				isSorted = false;
			}
		}

		//printf("sorted = " + isSorted);
		if (isSorted) break;
	}

	return 0;
}