#include <iostream>

void Set(int* pVal)
{
	*pVal = 10;
}

void Set(int& ref)
{
	ref = 100;
}


int main()
{
	int i = 0;

	Set(&i);	// �Ű������� int* �� �Լ� ȣ��
	Set(i);		// �Ű������� int& �� �Լ� ȣ��


	// C++ ���۷����� �����Ϳ� ���� ������ ���� (�ּҸ� �޾Ƽ� ������ ����)
	int iData = 0, iData2 = 0;

	// int& �� int* const�� ������
	// => ������ ����� �ٲ� �� ����
	int& ref = iData;
	ref = 20;
	ref = iData2; // ���� ����� �ٲٴ°� �ƴ϶�, ref �� ���� �Է�

	// const int& �� const int* const �� ����
	// => ������ ����� �ٲ� �� ����, ���� ��� ������ ���� �Ұ�
	// => �ַ� �Ը� ū Ÿ�� ������ �б� �������� ����� �� ���
	const int& cRef = iData;
	//cRef = 100;
	int value = cRef;

	return 0;
}