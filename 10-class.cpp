#include <iostream>

// 연산자 오버로딩
class String
{
	private: // (접근제한자 디폴트 값)
		char* pStr;
		int maxLength;
		int length;
		
		// 문자열을 저장할 메모리 크기 확장
		void Resize(const int Size)
		{
			// 1. 문자열의 최대 입력가능 사이즈 변경
			maxLength = Size + 1;	// 널 문자(\0) 감안

			// 2. 메모리 재할당
			char* pNew = (char*)malloc(sizeof(char) * maxLength);

			// 3. 원본 데이터를 재할당받은 메모리에 옮긴다
			for (int i = 0; i < length; i++)
			{
				pNew[i] = pStr[i];
			}

			// 4. 기존 메모리 해제
			free(pStr);

			// 5. 새로 할당한 공간을 가리킨다
			pStr = pNew;
		}

	public:
		// 생성자
		String() : maxLength(10), length(0)
		{
			pStr = (char*)malloc(sizeof(char) * (maxLength));
		}

		String(const char* str) : maxLength(10), length(0)
		{
			pStr = (char*)malloc(sizeof(char) * (maxLength));
			*this = str;
		}

		String(const String& str) : maxLength(str.maxLength), length(str.length)
		{
			pStr = (char*)malloc(sizeof(char) * (maxLength));
			*this = str;
		}

		// 소멸자
		~String()
		{
			if (pStr != nullptr) free(pStr);
		}

		// 연산자 오버로딩
		// 대입 연산자
		void operator= (const char* str)
		{
			// 1. 대입하려는 문자열 길이 파악
			int length = 0;
			while (str[length] != '\0')
			{
				length++;
			}

			// 2. 필요시 메모리 확장
			if (length >= maxLength) Resize(length);

			// 3. 입력한 문자열 대입
			for (int i = 0; i < length; i++)
			{
				pStr[i] = str[i];
			}

			// 4. 마지막에 널 문자 추가
			pStr[length] = '\0';

			// 5. 문자열 길이 갱신
			this->length = ++length;	// 널 문자 때문에 1 증가
		}

		void operator= (const String& str)
		{
			// 생성자 이니셜라이저에서 문자열의 현재길이, 최대길이는 초기화 해주었으므로
			// 문자열만 대입해주면 된다
			for (int i = 0; i < length; i++)
			{
				pStr[i] = str.pStr[i];
			}
		}

		// 덧셈 대입 연산자
		void operator+= (const char* str)
		{
			// 1. 추가하려는 문자열 길이 파악
			int length = 0;
			while (str[length] != '\0')
			{
				length++;
			}

			// 2. 필요시 메모리 확장, 최대 길이 갱신
			if (this->length + length > this->maxLength) Resize(this->maxLength = this->length + length);

			// 3. 문자열 이어붙이기
			for (int i = 0; i < length; i++)
			{
				pStr[this->length-1+i] = str[i];
			}

			// 4. 끝에 널 문자 추가, 현재 문자열 길이 갱신
			this->length += length;
			pStr[this->length - 1] = '\0';
		}

		void operator+= (const String& str)
		{
			// 1. 필요시 메모리 확장, 최대 길이 갱신
			if (length + str.length > maxLength) Resize(maxLength = length + str.length);

			// 2. 문자열 이어붙이기
			for (int i=0; i<str.length; i++)
			{
				pStr[length - 1 + i] = str.pStr[i];
			}

			// 3. 끝에 널 문자 추가, 현재 문자열 길이 갱신
			length += str.length;
			pStr[length - 1] = '\0';
		}

		// 덧셈 연산자
		String operator+ (const String& str)
		{
			String newStr = pStr;
			newStr += str.pStr;

			return newStr;
		}

		// private 멤버 Getter
		int Length()
		{
			return length;
		}

		const char* GetString() const
		{
			return pStr;
		}

		/*
		// 주소 테스트용
		char**const GetStrAddress()
		{
			return &pStr;
		}
		*/
};

// 전역 연산자 오버로딩
// 덧셈 연산자
String operator+ (const char* str1, const String& str2)
{
	String newStr = str1;
	newStr += str2;

	return newStr;
}

int main()
{
	// String::operator=.(const char*)가 호출됨
	String str1;
	str1 = "abc";
	str1 += "def";

	// String::생성자(const char*) 가 호출됨
	String str2 = "hello";

	// 객체 소멸시 동적할당 메모리를 정리할 때 문제를 일으키는 경우
	String str3 = str2;	// 생성자 로그가 안찍힘
	String str4(str2);	// 생성자 로그가 안찍힘
	//std::cout << "str4 " << str4.GetStrAddress() << std::endl;	// 셋이서 똑같은 pStr 가리키는것도 아닌데 왜?
	//std::cout << str4.GetString() << std::endl;
	//std::cout << "str3 " << str3.GetStrAddress() << std::endl;
	//std::cout << str3.GetString() << std::endl;
	//std::cout << "str2 " << str2.GetStrAddress() << std::endl;
	//std::cout << str2.GetString() << std::endl;
	// => String::생성자(const String&) 을 정의하면 문제가 해결됨. 근데 이 생성자를 정의하지 않았을때도 세 객체의 주소값이 각각 달랐는데 뭐지

	// String::operator+.(const String&) 가 호출됨
	String concat1 = str1 + str2;
	String concat2 = str1 + "zzz";

	// ::operator+.(const String&) 가 호출됨
	String concat3 = "ABC" + str1;

	return 0;
}