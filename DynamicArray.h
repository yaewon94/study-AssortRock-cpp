#pragma once

// �����迭 ������ ������ �� �ִ� �ڷ��� ���� (int�� ����)
struct DynamicArray
{
	int* pData;	// �����͸� ������ �ּ�
	int maxLength;		// ��� ������ �ִ� ����
	int currentLength;	// ���� ����� ����
};

void InitArray(DynamicArray*, const int);
void Push(DynamicArray*, const int);