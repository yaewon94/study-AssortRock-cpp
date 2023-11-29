/*
// .exe 파일 진입점
int main(void)
{
	// 1. 정수타입 - bool(1), char(1), short(2), wchar_t(2), int(4), long(4), long long(8), __int64(8)
	char c1 = 0; 
	char c2 = 'a';

	// signed 타입의 양수/음수 표현
	// 부호비트 : 양수 0, 음수 1
	// 음수 : 2의 보수법으로 저장(비트를 전부 반전 + 1)
	char c3 = 128;			//	overflow 발생 (char : -128 ~ 127)
	unsigned char c4 = 128;	//	(unsigned char : 0 ~ 255)

	short s = 32767;
	wchar_t wc = '가';
	int i = 2147483647;
	long long l = 9223372036854775807;

	bool b1 = 0;
	bool b2 = 100;	// 컴파일러는 true(1)로 바꿔서 저장
	bool b3 = true;
	
	// 2. 실수타입 - float(4), double(8)
	// double 타입이 float 타입보다 정밀도가 크다
	// (signed 타입 : 부호 비트)
	// 절댓값을 이진법으로 나타낸 후 소수점을 왼쪽으로 이동시켜 왼쪽에는 1만 남게 만든다(정규화)
	// 가수부는 소수점의 오른쪽 부분으로 부족한 비트 수 부분만큼 0으로 채운다
	// 지수에 Bias를 더한 후 이진법으로 변환한다
	// 최종적으로 메모리에는 부동소수점 방식으로 근사값이 저장된다
	float f1 = 1.2345f;
	float f2 = 10.f / 3.f;
	float f3 = 3.f * f2;	// 10.f 으로 복구가 안될수도 있음
	
	// 3. 형변환
	float f = 123.4f;
	int cast = f;
	
	int a = 10;
	int b = 3;
	int div1 = a / b;
	float div2 = a / b;
	float div3 = (float)a / (float)b;

	return 0;
}
*/
