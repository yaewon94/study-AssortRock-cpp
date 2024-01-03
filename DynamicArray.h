#pragma once
#include "assert.h"
#include <iostream>
using std::cout;

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
		T* pData;
		int maxLength;
		int currentLength;

		// 생성자
		DynamicArray(const int MaxLength)
		{
			pData = new T[MaxLength];
			maxLength = MaxLength;
			currentLength = 0;
		}
		
		// 소멸자
		~DynamicArray()
		{
			if (pData != nullptr) delete[] pData;
		}

		void Push(const T&);
		T Get(const int);
		
		// 인라인 함수 : 함수 호출 시 별도의 스택이 생성되는 것이 아니라 그 코드 구문이 그대로 cpp 파일에 복사된다
		// => 남발하면 호출하는 곳마다 복사되어서 코드의 양이 엄청나게 늘어남
		// 헤더파일에 구현해도 코드의 양이 긴 경우 컴파일러가 인라인함수로 처리하지 않음
		// => Getter, Setter 같은 함수에 적합
		int Capacity() { return maxLength; }
		int Size() { return currentLength; }

		// [] 연산자 오버로딩
		T& operator[](int index) { return pData[index]; }

		// 반복자 클래스
		class iterator
		{
			private:
				DynamicArray<T>* dArr;
				int currentIndex;

			public:
				// 생성자
				iterator(DynamicArray<T>* dArr, int index) : dArr(dArr), currentIndex(index){}
				
				// 참조 연산자 오버로딩
				T& operator* () 
				{ 
					assert(dArr 
							&& currentIndex >= 0 
							&& currentIndex < dArr->currentLength);
					return dArr->pData[currentIndex];
				}
				
				// 전위 연산자 오버로딩
				iterator& operator++ () 
				{
					assert(dArr 
							&& currentIndex < dArr->currentLength);
					++currentIndex;
					return *this;
				}

				iterator& operator-- () 
				{ 
					assert(dArr 
							&& currentIndex > 0);
					--currentIndex;
					return *this;
				}

				// 후위 연산자 오버로딩
				iterator operator++ (int)
				{
					iterator copyiter = *this;
					++(*this);
					return copyiter;
				}

				iterator operator-- (int)
				{
					iterator copyiter = *this;
					--(*this);
					return copyiter;
				}

				// == 연산자 오버로딩
				bool operator== (const iterator& other)
				{
					if (dArr == other.dArr && currentIndex == other.currentIndex) return true;
					else return false;
				}

				// != 연산자 오버로딩
				bool operator!= (const iterator& other)
				{
					return !(*this == other);
				}
		};

		// DynamicArray 시작 인덱스를 가리키는 포인터 리턴
		iterator begin() 
		{
			iterator iter = iterator(this, 0);

			// [?] iter 는 지역변수인데 함수종료뒤에 왜 안사라지는거임? 
			// [?] 클래스 객체는 new 안써도 스택이 아니라, 힙에 생성되는건가?
			//cout << "iterator 지역변수 주소 테스트 = " << &iter << "\n";
			return iter; 
		}

		// DynamicArray 인덱스의 끝의 다음을 가리키는 포인터 리턴
		iterator end()
		{
			return iterator(this, -1);
		}
};

/*
void InitArray(DynamicArray*, const int);
void Push(DynamicArray*, const int);
void Resize(DynamicArray*);
int Get(DynamicArray*, const int);
*/

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
