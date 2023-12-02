// ��ó����
#define BLEED	1
#define SLOW	2
#define STURN	4
#define SHORK	8
#define BURN	0x10
#define ICE		0x20
#define ATT_UP	0x40
#define DEF_UP	0x80
#define DEX_UP	0x100

#define SPECIAL_DEBUF1	(BLEED | BURN)	// ���� ���յ� ����
#define SPECIAL_DEBUF2	(BLEED | \
						 SLOW | \
						 STURN)

int main()
{
	// ���� ������ : ++, --
	int val1 = 0; int val2 = 0;
	int forward = ++val1;
	int post = val2++;

	// ��Ģ ������ :+, -, *, /, %
	int mod = 10 % 3;

	// �� ������ : ==, !=, >, >=, <, <=
	// C++ �����Ϸ��� 0�� false �� ����, 0���� ���� true(1�� �ٲپ� �����)
	if (0 > 5) {}

	// �� ������ :&&(and), ||(or), !(not)
	// && ���ǹ� �� �ϳ��� false �� ������ ���ǹ��� �˻� ����
	// || ���ǹ� �� �ϳ��� true �� ������ ���ǹ��� �˻� ����
	if (0 < 100 && 0 > -1) {}

	// ��Ʈ ����Ʈ ������
	// << : nĭ ��ŭ ��Ʈ�� �������� �̵�, ������ ��Ʈ�� 0���� ä�� (*=2 �� ���� ȿ��)
	// >> : nĭ ��ŭ ��Ʈ�� ���������� �̵�, ������ ��Ʈ�� 0���� ä�� (/=2 �� ���� ȿ��)
	int shift = 1 << 1;
	
	// ��Ʈ ������
	// ��Ʈ ������ ����
	// & (and) : ��� ��Ʈ�� 1�̿��� 1
	// | (or) : ��Ʈ �ϳ��� 1�̸� 1
	// ~ (not) : 1�̸� 0, 0�̸� 1�� ����
	// ^ (xor) : �� ��Ʈ�� ������ 0, �ٸ��� 1
	// ex. ��뿹�� : ĳ������ ���°��� bool�� ���� ��� define ��ó����� ��Ʈ�����ڷ� ǥ�� 
	unsigned int status = 0;
	status |= SLOW;			// ���³ֱ�
	if (status & SLOW) {}	// �ش� ���°� �´��� Ȯ��
	status &= ~SLOW;		// ��������

	// ������ �켱����
	// ���� ���� ������
	// *, /
	// +, -
	// =
	// ���� ���� ������

	return 0;
}