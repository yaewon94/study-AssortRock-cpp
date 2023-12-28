#include <list>
#include <set>
#include <vector>
using namespace std;

int main()
{
	const int Size = 10;

	//
	// vector : �����迭, �޸��� �������� ������ ����(�ε����� ������ �� ȿ����)
	//
	// 1. �ʱ�ȭ
	vector<int> vec;		// size=0, capacity=0
	vector<int> vec2(Size);	// size=Size(����Ʈ ����� ä��), capacity=Size
	//
	// 2. ũ�� ��ȯ
	vec.size();				// ���� ������ ����
	vec.capacity();			// �ִ� ������
	//
	// 3. ũ�� ���Ҵ�
	//
	// reverse(size_t) : size=0, capacity=Size
	// ���Ҵ� �� �� ����, ���� ���Ұ� ���ο� �޸𸮷� ����ǹǷ�
	// ���� ��ü ���� ���� reserve(size_t)�� ����ϸ� �̷� ����� ���� �� �ִ�
	vec.reserve(Size);
	//
	// resize(size) : size=Size(�ش� Ÿ���� ����Ʈ ����� ä��), capacity=Size
	vec.resize(Size);
	//
	// vector�� ���� �������� ���� ũ��� ���Ҵ� �Ұ����ϱ� ������
	// �̰��� �ذ��ϱ� ���� �ӽ� vector��ü�� ����� �ٲ��ش�
	vector<int> vecTemp;
	vecTemp = vec;
	vec.swap(vecTemp);
	//
	// 4. ������ ����
	vec.push_back(10);	// ����
	vec[0];				// �ش� �ε����� ���ҿ� ����
	vec.at(0);			// �ش� �ε����� ���ҿ� ���� (�迭 ������ �Ѿ�� ��� ���ܸ� ������)


	//
	// list : �޸𸮿� ���������� ����Ǿ� ���� �ʰ�, �����͸� ���� ���� ����� �ּҸ� ����Ű�� ���
	// => �ε����� ���� �Ұ�
	// => �����Ϳ� �����ϱ� ���ؼ� ������ ���������� �����ؾ� �� (������ ���� ��� ��ȿ����)
	// => �������� ����, ������ ����� ���� ȿ����
	list<int> list;
	//
	// ������ ����
	list.push_back(10);	// ����

	//
	// set
	set<int> set;
	//
	// ������ ����
	set.insert(10);	// ����


	return 0;
}