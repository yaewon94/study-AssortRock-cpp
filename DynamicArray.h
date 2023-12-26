#pragma once

//
// C++ 의 vector.h 에 구현되어 있음
//

// 동적배열 역할을 수행할 수 있는 자료형 정의 (int값 예시)
//struct DynamicArray
template<typename T>	// 클래스 템플릿은 cpp가 아닌 h에 모두 구현해야 링킹 에러가 일어나지 않음
class DynamicArray
{
	private:
		void Resize();

	public:
		T* pData;			// 데이터를 저장할 주소
		int maxLength;		// 허용 가능한 최대 길이
		int currentLength;	// 현재 저장된 길이

		DynamicArray(const int);
		~DynamicArray();
		void Push(const T&);
		T Get(const int);
		
		// 인라인 함수 : 함수 호출 시 별도의 스택이 생성되는 것이 아니라 그 코드 구문이 그대로 cpp 파일에 복사된다
		// => 남발하면 호출하는 곳마다 복사되어서 코드의 양이 엄청나게 늘어남
		// 헤더파일에 구현해도 코드의 양이 긴 경우 컴파일러가 인라인함수로 처리하지 않음
		// => Getter, Setter 같은 함수에 적합
		int Capacity() { return maxLength; }
		int Size() { return currentLength; }
		//
		// [] 연산자 오버로딩
		int& operator[](int index) { return pdata[index]; }
};

/*
void InitArray(DynamicArray*, const int);
void Push(DynamicArray*, const int);
void Resize(DynamicArray*);
int Get(DynamicArray*, const int);
*/

// 생성자
template<typename T>
DynamicArray<T>::DynamicArray(const int MaxLength)
{
	//pData = (int*)malloc(sizeof(int) * MaxLength);
	pData = new T[MaxLength];
	maxLength = MaxLength;
	currentLength = 0;
}

// 소멸자
template<typename T>
DynamicArray<T>::~DynamicArray()
{
	//if (pData != nullptr) free(pData);
	if (pData != nullptr) delete[] pData;
}

// 값 삽입
template<typename T>
void DynamicArray<T>::Push(const T& Value)
{
	if (currentLength == maxLength) Resize();
	pData[currentLength++] = Value;
}

// 메모리 재할당
template<typename T>
void DynamicArray<T>::Resize()
{
	//int* newArr = (int*)malloc(maxLength * 2 * sizeof(int));
	T* newArr = new T[maxLength *= 2];

	for (int i = 0; i < maxLength; i++)
	{
		newArr[i] = pData[i];
	}

	//free(pData);
	delete[] pData;

	pData = newArr;

	//maxLength *= 2;
}

// 배열 값 가져오기
template<typename T>
T DynamicArray<T>::Get(const int Index)
{
	if (Index >= currentLength) assert(!(Index >= currentLength));

	return pData[Index];
}
