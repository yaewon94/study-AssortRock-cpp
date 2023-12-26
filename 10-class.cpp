#include <iostream>

// ������ �����ε�
class String
{
	private: // (���������� ����Ʈ ��)
		char* pStr;
		int maxLength;
		int length;
		
		// ���ڿ��� ������ �޸� ũ�� Ȯ��
		void Resize(const int Size)
		{
			// 1. ���ڿ��� �ִ� �Է°��� ������ ����
			maxLength = Size + 1;	// �� ����(\0) ����

			// 2. �޸� ���Ҵ�
			char* pNew = (char*)malloc(sizeof(char) * maxLength);

			// 3. ���� �����͸� ���Ҵ���� �޸𸮿� �ű��
			for (int i = 0; i < length; i++)
			{
				pNew[i] = pStr[i];
			}

			// 4. ���� �޸� ����
			free(pStr);

			// 5. ���� �Ҵ��� ������ ����Ų��
			pStr = pNew;
		}

	public:
		// ������
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

		// �Ҹ���
		~String()
		{
			if (pStr != nullptr) free(pStr);
		}

		// ������ �����ε�
		// ���� ������
		void operator= (const char* str)
		{
			// 1. �����Ϸ��� ���ڿ� ���� �ľ�
			int length = 0;
			while (str[length] != '\0')
			{
				length++;
			}

			// 2. �ʿ�� �޸� Ȯ��
			if (length >= maxLength) Resize(length);

			// 3. �Է��� ���ڿ� ����
			for (int i = 0; i < length; i++)
			{
				pStr[i] = str[i];
			}

			// 4. �������� �� ���� �߰�
			pStr[length] = '\0';

			// 5. ���ڿ� ���� ����
			this->length = ++length;	// �� ���� ������ 1 ����
		}

		void operator= (const String& str)
		{
			// ������ �̴ϼȶ��������� ���ڿ��� �������, �ִ���̴� �ʱ�ȭ ���־����Ƿ�
			// ���ڿ��� �������ָ� �ȴ�
			for (int i = 0; i < length; i++)
			{
				pStr[i] = str.pStr[i];
			}
		}

		// ���� ���� ������
		void operator+= (const char* str)
		{
			// 1. �߰��Ϸ��� ���ڿ� ���� �ľ�
			int length = 0;
			while (str[length] != '\0')
			{
				length++;
			}

			// 2. �ʿ�� �޸� Ȯ��, �ִ� ���� ����
			if (this->length + length > this->maxLength) Resize(this->maxLength = this->length + length);

			// 3. ���ڿ� �̾���̱�
			for (int i = 0; i < length; i++)
			{
				pStr[this->length-1+i] = str[i];
			}

			// 4. ���� �� ���� �߰�, ���� ���ڿ� ���� ����
			this->length += length;
			pStr[this->length - 1] = '\0';
		}

		void operator+= (const String& str)
		{
			// 1. �ʿ�� �޸� Ȯ��, �ִ� ���� ����
			if (length + str.length > maxLength) Resize(maxLength = length + str.length);

			// 2. ���ڿ� �̾���̱�
			for (int i=0; i<str.length; i++)
			{
				pStr[length - 1 + i] = str.pStr[i];
			}

			// 3. ���� �� ���� �߰�, ���� ���ڿ� ���� ����
			length += str.length;
			pStr[length - 1] = '\0';
		}

		// ���� ������
		String operator+ (const String& str)
		{
			String newStr = pStr;
			newStr += str.pStr;

			return newStr;
		}

		// private ��� Getter
		int Length()
		{
			return length;
		}

		const char* GetString() const
		{
			return pStr;
		}

		/*
		// �ּ� �׽�Ʈ��
		char**const GetStrAddress()
		{
			return &pStr;
		}
		*/
};

// ���� ������ �����ε�
// ���� ������
String operator+ (const char* str1, const String& str2)
{
	String newStr = str1;
	newStr += str2;

	return newStr;
}

int main()
{
	// String::operator=.(const char*)�� ȣ���
	String str1;
	str1 = "abc";
	str1 += "def";

	// String::������(const char*) �� ȣ���
	String str2 = "hello";

	// ��ü �Ҹ�� �����Ҵ� �޸𸮸� ������ �� ������ ����Ű�� ���
	String str3 = str2;	// ������ �αװ� ������
	String str4(str2);	// ������ �αװ� ������
	//std::cout << "str4 " << str4.GetStrAddress() << std::endl;	// ���̼� �Ȱ��� pStr ����Ű�°͵� �ƴѵ� ��?
	//std::cout << str4.GetString() << std::endl;
	//std::cout << "str3 " << str3.GetStrAddress() << std::endl;
	//std::cout << str3.GetString() << std::endl;
	//std::cout << "str2 " << str2.GetStrAddress() << std::endl;
	//std::cout << str2.GetString() << std::endl;
	// => String::������(const String&) �� �����ϸ� ������ �ذ��. �ٵ� �� �����ڸ� �������� �ʾ������� �� ��ü�� �ּҰ��� ���� �޶��µ� ����

	// String::operator+.(const String&) �� ȣ���
	String concat1 = str1 + str2;
	String concat2 = str1 + "zzz";

	// ::operator+.(const String&) �� ȣ���
	String concat3 = "ABC" + str1;

	return 0;
}