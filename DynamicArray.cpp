#include "assert.h"
#include "DynamicArray.h"
#include <iostream>

int main()
{
	DynamicArray arr = {};
	InitArray(&arr, 3);
	Push(&arr, 1);
	Push(&arr, 2);
	Push(&arr, 3);
	Push(&arr, 4);
	Get(&arr, 0);
	Get(&arr, 100);

	return 0;
}

// 초기화
void InitArray(DynamicArray* arr, const int MaxLength)
{
	arr->pData = (int*)malloc(sizeof(int) * MaxLength);
	arr->maxLength = MaxLength;
	arr->currentLength = 0;
}

// 배열의 맨 뒤에 값 추가
void Push(DynamicArray* arr, const int Value)
{
	// 배열이 꽉 찬 경우, 배열 재할당
	if (arr->currentLength == arr->maxLength) Resize(arr);

	arr->pData[arr->currentLength++] = Value;

}

// 배열 재할당
void Resize(DynamicArray* arr)
{
	// 1. 더 큰 메모리 공간을 할당받는다
	int* newArr = (int*)malloc(arr->maxLength * 2 * sizeof(int));

	// 2. 기존 배열값을 새로운 배열에 저장
	for (int i=0; i<arr->maxLength; i++)
	{
		newArr[i] = arr->pData[i];
	}

	// 3. 기존에 할당받은 메모리 공간 해제
	free(arr->pData);

	// 4. 새롭게 할당받은 메모리 공간을 가리킨다
	arr->pData = newArr;

	// 5. 배열의 최대크기 변경
	arr->maxLength *= 2;
}

// 배열 값 가져오기
int Get(DynamicArray* arr, const int Index)
{
	// 배열에 입력된 크기보다 Index가 큰 경우 예외처리
	if (Index >= arr->currentLength) assert(!(Index >= arr->currentLength));

	return arr->pData[Index];
}
