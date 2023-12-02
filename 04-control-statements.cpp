int main()
{
	bool flag1 = true;
	int flag2 = 0;

	// 1. 조건문
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
			// break 문이 없으면 다음 break 문이 나올 때 까지 실행된다
		case 3:
			break;
		default:
	}

	// 2. 반복문
	// for(초기식; 반복조건; 증감식)
	for (int i=0; i<3; i++)
	{
	}
	// while(조건식)
	int flag = 0;
	while (flag<3)
	{
		flag++;
	}
	// do ~ while(조건식)
	do 
	{
		flag++;
	} while (flag < 5);

	// 3. 분기이동 키워드
	// continue : 해당 부분을 건너뛰고 다음 루프를 실행
	// break : 해당 반복문을 중단
	for (int i=0; i<5; i++)
	{
		if (i == 2) continue;
		else if (i == 4) break;
	}

	return 0;
}