// �迭 : ���� Ÿ���� ���� ���� �� ����
#include <iostream>

int main()
{
	// �迭 ����, �ʱ�ȭ
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };	// ��� �� �ʱ�ȭ
	int arr1[3] = {};			// �迭�� ��� ���� 0���� �ʱ�ȭ
	int arr2[3] = { 1,2 };		// �ʱ�ȭ���� ���� ������ ���Ҵ� 0���� �ʱ�ȭ

	// �迭 �� ����
	// �ε��� : 0���� ����
	// �迭�� �̸��� �ش� �迭�� ������ġ(�ּ�)
	// �޸� ���� : �������� ����
	arr1[0] = 10;

	// ���ı��
	// O(N^2) : ��������, ��������
	// O(N * logN) : ������, �պ�����, ������
	// ����/�Ҿ��� ���� : ���� ���� ������ �����ִ��� ����
	// ex. �������� ����
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