int main()
{
	// ���� (����Ÿ��)
	char c = 'a';		// 1 byte (�ƽ�Ű�ڵ�)
	wchar_t wc = L'��';	// 2 byte (�����ڵ�, 2byte�ε� �������� �� ǥ���� ���� ���� ������, ���󺰷� ������ �ϸ� �� ���� �� �°� ����)

	// ���� �迭
	// ���ڿ��� �� : �ι���('\0')�� 1 byte (wchar_t �� 2 byte) ����
	wchar_t wcArr[3] = L"�ȳ�";
	char cArr[6] = "hello";

	// ���ڿ�
	// => ���ڿ��� �����ͺ����� ����Ű�� �ִ� �޸� �ּҿ� ���������� ����� char �Ǵ� wchar_t �����̴�
	//char* str = "hello";	// ���ڿ��� const �� �ƴ� Ÿ������ ����ų �� ���� (ROM�� ����� ����̹Ƿ�)
	const char* cStr = "hello";
	char ch1 = *cStr;
	char ch2 = cStr[0];
	//((char*) cStr)[0] = 'b';	// ��Ÿ�ӿ��� : ����ĳ�����ص� ROM ������ ����� ���� ������ �� ����

	// �ڡڡڡڡ� ���ڿ��� �ּ� �ڡڡڡڡ�
	// ���� ������ ���ڿ��� ������ ���� �ּҸ� ��Ÿ����
	// �ڵ�󿡼� ������ ���ڿ��� ���� �� ��������, �ش� ���ڿ��� ROM �� �� 1���� �����Ѵ�
	// ��, &cArr == &str

	return 0;
}