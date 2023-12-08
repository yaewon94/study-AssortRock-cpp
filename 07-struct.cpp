// 구조체 크기 확장규칙을 1바이트로 제한
#pragma pack(1)

// 구조체 정의
// 크기 : 구조체를 구성하는 변수들 중 메모리의 크기가 가장 큰 변수의 배수로 확장됨
// ex. int가 가장 클 경우 int(4),char(1),char(1) 이더라도 int(4)*2 byte 가 됨 (6 < 8)
// #pragma pack(크기) : 기존의 구조체 메모리 확장 규칙을 무시하고, 해당 크기의 배수로 확장됨 
struct Town
{
	int index;
};

int main()
{
	// 구조체 변수 선언, 초기화
	Town town = { 0 };
	int index = town.index; // 구조체 변수 접근
	
	return 0;
}