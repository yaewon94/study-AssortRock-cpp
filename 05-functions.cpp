// �Լ�����
// ����, ���Ǹ� ���ÿ� �� ���� ����
int pow(int, int);

int main()
{
	int result = pow(2, 10);

	return 0;
}

// �Լ�����
int pow(int num, int exp)
{
	int result = 1;

	for (int i=0; i<exp; i++)
	{
		result *= num;
	}

	return result;
}