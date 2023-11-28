// .exe 파일 진입점
int main(void)
{
	// 1. 정수타입 - char(1), short(2), wchar_t(2), int(4), long(4), long long(8), __int64(8)
	char c1 = 0; 
	char c2 = 'a';

	// signed 타입의 양수/음수 표현
	// 부호비트 : 양수 0, 음수 1
	// 음수 (2의 보수법으로 저장 : 비트를 전부 반전 + 1)
	char c3 = 128;		// overflow 발생 (char : -128 ~ 127)
	unsigned char c4 = 128;	// (unsigned char : 0 ~ 255)
	short s = 32767;
	wchar_t wc = '가';
	int i = 2147483647;
	long long l = 9223372036854775807;

	return 0;
}
