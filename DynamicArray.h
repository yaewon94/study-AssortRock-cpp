#pragma once

//
// C++ 의 vector.h 에 구현되어 있음
//

// 동적배열 역할을 수행할 수 있는 자료형 정의 (int값 예시)
//struct DynamicArray
class DynamicArray
{
	public:
		int* pData;	// 데이터를 저장할 주소
		int maxLength;		// 허용 가능한 최대 길이
		int currentLength;	// 현재 저장된 길이
		
		DynamicArray(const int);
		~DynamicArray();
		void Push(const int);
		void Resize();
		int Get(const int);
};

/*
void InitArray(DynamicArray*, const int);
void Push(DynamicArray*, const int);
void Resize(DynamicArray*);
int Get(DynamicArray*, const int);
*/
