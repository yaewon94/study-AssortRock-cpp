#include <iostream>
using namespace std; // 이 파일에서는 std:: 를 붙이지 않고 std의 변수,함수를 사용 가능

namespace MySpace
{
  void Test(){}
}

void Test(){}

int main()
{
  // ::(범위지정 연산자) : 네임스페이스 또는 클래스 내부의 변수,함수를 지정
  MySpace::Test();
  Test();

  //std::cout << "hello";
  cout <<"hello";
  
  return 0;
}
