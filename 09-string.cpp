int main()
{
	// 문자 (정수타입)
	char c = 'a';		// 1 byte (아스키코드)
	wchar_t wc = L'가';	// 2 byte (유니코드, 2byte로도 전세계의 언어를 표현할 수는 없기 때문에, 나라별로 언어설정을 하면 그 나라 언어에 맞게 나옴)

	// 문자 배열
	// 문자열의 끝 : 널문자('\0')가 1 byte (wchar_t 는 2 byte) 차지
	wchar_t wcArr[3] = L"안녕";
	char cArr[6] = "hello";

	// 문자열
	// => 문자열은 포인터변수가 가리키고 있는 메모리 주소에 연속적으로 저장된 char 또는 wchar_t 값들이다
	//char* str = "hello";	// 문자열을 const 가 아닌 타입으로 가리킬 수 없다 (ROM에 저장된 상수이므로)
	const char* cStr = "hello";
	char ch1 = *cStr;
	char ch2 = cStr[0];
	//((char*) cStr)[0] = 'b';	// 런타임에러 : 강제캐스팅해도 ROM 영역에 저장된 값을 수정할 수 없음

	// ★★★★★ 문자열의 주소 ★★★★★
	// 같은 구조의 문자열은 동일한 곳의 주소를 나타낸다
	// 코드상에서 동일한 문자열이 여러 번 나오더라도, 해당 문자열은 ROM 상에 딱 1개만 존재한다
	// 즉, &cArr == &str

	return 0;
}