// 전처리기
#define BLEED	1
#define SLOW	2
#define STURN	4
#define SHORK	8
#define BURN	0x10
#define ICE		0x20
#define ATT_UP	0x40
#define DEF_UP	0x80
#define DEX_UP	0x100

#define SPECIAL_DEBUF1	(BLEED | BURN)	// 상태 조합도 가능
#define SPECIAL_DEBUF2	(BLEED | \
						 SLOW | \
						 STURN)

int main()
{
	// 증감 연산자 : ++, --
	int val1 = 0; int val2 = 0;
	int forward = ++val1;
	int post = val2++;

	// 사칙 연산자 :+, -, *, /, %
	int mod = 10 % 3;

	// 비교 연산자 : ==, !=, >, >=, <, <=
	// C++ 컴파일러는 0을 false 로 본다, 0외의 값은 true(1로 바꾸어 저장됨)
	if (0 > 5) {}

	// 논리 연산자 :&&(and), ||(or), !(not)
	// && 조건문 중 하나라도 false 면 나머지 조건문은 검사 안함
	// || 조건문 중 하나라도 true 면 나머지 조건문은 검사 안함
	if (0 < 100 && 0 > -1) {}

	// 비트 시프트 연산자
	// << : n칸 만큼 비트를 왼쪽으로 이동, 나머지 비트는 0으로 채움 (*=2 와 같은 효과)
	// >> : n칸 만큼 비트를 오른쪽으로 이동, 나머지 비트는 0으로 채움 (/=2 와 같은 효과)
	int shift = 1 << 1;
	
	// 비트 연산자
	// 비트 단위로 연산
	// & (and) : 모든 비트가 1이여야 1
	// | (or) : 비트 하나라도 1이면 1
	// ~ (not) : 1이면 0, 0이면 1로 반전
	// ^ (xor) : 두 비트가 같으면 0, 다르면 1
	// ex. 사용예시 : 캐릭터의 상태값을 bool값 묶음 대신 define 전처리기와 비트연산자로 표현 
	unsigned int status = 0;
	status |= SLOW;			// 상태넣기
	if (status & SLOW) {}	// 해당 상태가 맞는지 확인
	status &= ~SLOW;		// 상태제거

	// 연산자 우선순위
	// 전위 증감 연산자
	// *, /
	// +, -
	// =
	// 후위 증감 연산자

	return 0;
}