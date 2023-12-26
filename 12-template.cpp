// 템플릿은 다른 자료형으로 선언할 때 마다 컴파일러가 각각 별개의 함수, 클래스로 본다

// 함수 템플릿
template<typename T>
T Add(T a, T b)
{
  return a+b;
}

// 클래스 템플릿
template<typename T1, T2>
class TemplateTest
{
 private:
  T1 t1;
  T2 t2;
 public:
  TemplateTest(T1 t1, T2 t2)
  {
     this->t1 = t1;
     this->t2 = t2;
  }
  
  T1 GetT1() { return t1; }
};
 

int main()
{
  int value = Add<int>(10, 20);
  TemplateTest t(10, 2.f);

  return 0;
}
