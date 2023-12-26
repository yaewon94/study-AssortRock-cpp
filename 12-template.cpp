// 함수 템플릿
template<typename T>
T Add(T a, T b)
{
  return a+b;
}

int main()
{
  int value = Add<int>(10, 20);

  return 0;
}
