int main()
{
	bool flag1 = true;
	int flag2 = 0;

	// 1. ���ǹ�
	// if ~ (else if ~) (else ~)
	if (flag1)
	{
	}
	else if (!flag1)
	{
	}
	else
	{
	}
	// switch ~ case
	switch (flag2)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			// break ���� ������ ���� break ���� ���� �� ���� ����ȴ�
		case 3:
			break;
		default:
	}

	// 2. �ݺ���
	// for(�ʱ��; �ݺ�����; ������)
	for (int i=0; i<3; i++)
	{
	}
	// while(���ǽ�)
	int flag = 0;
	while (flag<3)
	{
		flag++;
	}
	// do ~ while(���ǽ�)
	do 
	{
		flag++;
	} while (flag < 5);

	// 3. �б��̵� Ű����
	// continue : �ش� �κ��� �ǳʶٰ� ���� ������ ����
	// break : �ش� �ݺ����� �ߴ�
	for (int i=0; i<5; i++)
	{
		if (i == 2) continue;
		else if (i == 4) break;
	}

	return 0;
}