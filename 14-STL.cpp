#include <list>
#include <set>
#include <vector>
using namespace std;

int main()
{
	const int Size = 10;

	//
	// vector : 동적배열, 메모리의 연속적인 공간에 저장(인덱스로 접근할 때 효율적)
	//
	// 1. 초기화
	vector<int> vec;		// size=0, capacity=0
	vector<int> vec2(Size);	// size=Size(디폴트 값들로 채움), capacity=Size
	//
	// 2. 크기 반환
	vec.size();				// 현재 원소의 개수
	vec.capacity();			// 최대 사이즈
	//
	// 3. 크기 재할당
	//
	// reverse(size_t) : size=0, capacity=Size
	// 재할당 할 때 마다, 기존 원소가 새로운 메모리로 복사되므로
	// 벡터 객체 생성 이후 reserve(size_t)를 사용하면 이런 비용을 줄일 수 있다
	vec.reserve(Size);
	//
	// resize(size) : size=Size(해당 타입의 디폴트 값들로 채움), capacity=Size
	vec.resize(Size);
	//
	// vector는 기존 공간보다 작은 크기로 재할당 불가능하기 때문에
	// 이것을 해결하기 위해 임시 vector객체를 만들어 바꿔준다
	vector<int> vecTemp;
	vecTemp = vec;
	vec.swap(vecTemp);
	//
	// 4. 데이터 접근
	vec.push_back(10);	// 삽입
	vec[0];				// 해당 인덱스의 원소에 접근
	vec.at(0);			// 해당 인덱스의 원소에 접근 (배열 범위를 넘어서는 경우 예외를 던져줌)


	//
	// list : 메모리에 연속적으로 저장되어 있지 않고, 포인터를 통해 다음 노드의 주소를 가리키는 방식
	// => 인덱스로 접근 불가
	// => 데이터에 접근하기 위해선 무조건 순차적으로 접근해야 함 (접근이 잦은 경우 비효율적)
	// => 데이터의 삽입, 삭제가 빈번한 경우는 효율적
	list<int> list;
	//
	// 데이터 접근
	list.push_back(10);	// 삽입

	//
	// set
	set<int> set;
	//
	// 데이터 접근
	set.insert(10);	// 삽입


	return 0;
}