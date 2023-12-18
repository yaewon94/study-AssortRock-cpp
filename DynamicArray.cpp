#include "DynamicArray.h"
#include <iostream>

int main()
{
	DynamicArray arr = {};
	InitArray(&arr, 3);
	Push(&arr, 1);
	Push(&arr, 2);
	Push(&arr, 3);

	return 0;
}

void InitArray(DynamicArray* arr, const int MaxLength)
{
	arr->pData = (int*)malloc(sizeof(int) * MaxLength);
	arr->maxLength = MaxLength;
	arr->currentLength = 0;
}

void Push(DynamicArray* arr, const int Value)
{
	if (arr->currentLength == arr->maxLength)
	{
		printf("¹è¿­ÀÌ ²Ë Ã¡½À´Ï´Ù");
		return;
	}

	arr->pData[arr->currentLength++] = Value;
}