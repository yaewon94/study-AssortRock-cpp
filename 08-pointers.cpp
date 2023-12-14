#include <stdio.h>	// #define NULL 0 포함

int main()
{
	// 일반 변수
	//int i = nullptr;	// 포인터 타입이 아닌 변수에 nullptr 대입 불가
	int i2 = NULL;		// "변수의 값"으로 0을 넣는다

	//
	// 1. 포인터 : 메모리의 주소값을 저장하기 위한 변수
	// * 크기 : 타겟 플랫폼에 따라 다름 (ex. 64비트 플랫폼 => 8 바이트)
	// 	 (ex. char* 의 크기는 1 byte 가 아님)
	// * 타입 : 포인터가 가리킬 변수의 타입을 나타냄
	int* ptr = nullptr;	// 어떤 메모리도 가리키지 않는 상태
	int* ptr2 = NULL;	// 포인터변수가 가리키는 "메모리의 주소값"에 0을 넣는다

	//
	// 2. 포인터와 (포인터가 아닌) 변수
	int val = 0;
	ptr = &val;	// 포인터변수 ptr이 변수 val 의 메모리주소를 가리키게 한다
	*ptr = 100;	// 역참조 : 포인터변수 ptr이 가리키는 메모리(변수 val)의 값으로 100을 대입한다

	// 포인터 변수는 본인의 타입과 다른 타입의 메모리를 가리킬 수 없다
	// (역참조할때 자료형의 크기를 이용해서 주소값을 계산하기 때문)
	// 포인터 변수가 저장하는 주소값 만으로는 해당 주소의 실제 타입을 알 수 없다
	// 따라서 포인터를 선언할 때 가리킬 주소의 타입을 미리 정해놓고 선언한다
	unsigned int val2 = -100;
	//ptr = &val2;	// error

	// 값이 동일해도 해석 방식에 따라서 값을 다르게 해석할 수 있다
	char c = -100;
	char* cptr = &c;
	unsigned char* ucptr = (unsigned char*)c;	// char 타입을 강제로 unsigned char 로 바꿈 => 그러나 ucptr 이 가리키는 메모리엔 unsigned char 의 관점으로 보임
	int val3 = *cptr;							// val3 의 값은 c 에 저장된 값과 다름

	// void* 는 모든 타입의 메모리를 가리킬 수 있다
	void* vptr = nullptr;
	vptr = &val;
	vptr = &val2;
	//*vptr;	// 역참조 불가능 (타입 크기를 이용해서 메모리 주소를 계산하지 못하기 때문)
	//vptr++;	// 주소연산 불가능

	//
	// 3. 사용자 정의 타입과 포인터
	struct MyStruct
	{
		int member;
	};

	MyStruct myStruct = {};
	MyStruct* strptr = nullptr;
	strptr = &myStruct;
	(*strptr).member = 0;	// 포인터를 이용해 구조체(또는 클래스) 멤버에 접근
	strptr->member = 0;		// (*포인터이름).멤버이름 == 포인터이름->멤버이름

	//
	// 4. 주소 연산
	// 주소의 최소 단위 : byte (주소값의 표현체계는 정수타입)
	// 포인터 변수의 크기 : 운영체제 플랫폼에 따라 최대 크기로 지정됨
	// ex. 32비트 플랫폼 기준, 4GB 이상의 메모리 주소에 접근하려면 우회하는 방법을 써야 하는 등의 문제 생김
	int arr[5] = {0,1,2,3,4};	// 배열은 연속적인 메모리 구조를 가짐 (=> 포인터 연산 가능)
	int* pArr = arr;			// 배열의 이름은 주소값을 나타냄
	*(pArr + 2) = 20;			// pArr[2] = 20 과 동일
	pArr++;						// pArr은 int타입 포인터 이므로 4byte 후의 메모리를 가리킨다
	pArr--;

	//
	// 5. const 포인터
	int num = 1;
	const int* cp1 = &num;
	int result = *cp1;
	//*cp = 100;	// 포인터가 가리키는 곳의 값을 수정할 수 없음
	*((int*)cp1) = 100;	// 상수화된 포인터를 강제로 캐스팅해서 바꾼 경우 (미친거임)

	int* const cp2 = &num;
	*cp2 = 100;
	//cp2 = &result;	// 포인터가 가리키는 곳을 바꿀 수 없음

	const int* const cp3 = &num;
	//*cp3 = 100;		// 포인터가 가리키는 곳의 값을 바꿀 수 없음
	//cp3 = &result;	// 포인터가 가리키는 곳을 바꿀 수 없음

	//
	// 6. 상수화된 변수와 포인터
	const int cVal = 0;
	int* p = (int*)&cVal;
	*p = 100;	// 강제로 캐스팅해서 상수화된 변수의 값을 바꿀 수 있음



	return 0;
}
