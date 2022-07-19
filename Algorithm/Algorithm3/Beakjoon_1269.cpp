#include <iostream>
#include <set>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. 대칭 차집합의 원소의 개수를 출력하라.
	// 입력
	// 1. 집합 A와 B를 입력 받는다.
	// 2. 집합 A만큼 반복문을 돌려 원소를 입력 받는다.
	// 3. 집합 B만큼 반복문을 돌려 원소를 입력 받는다. 
	// 처리
	// 1. 집합 2개를 받을 set 집합을 입력 받는다.
	// 2. B만큼 원소를 입력 받을때 A와 중복 값이 있는지 체크하고 카운트 한다. => set은 이분탐색
	// 출력
	//
	int A, B;
	cin >> A >> B;

	set<int> set1;
	for (int i = 0; i < A; i++)
	{
		int num;
		cin >> num;
		set1.insert(num);
	}

	int mixCount = 0;
	for (int i = 0; i < B; i++)
	{
		int num;
		cin >> num;
		if (set1.find(num) != set1.end())
		{
			mixCount++;
		}
	}

	cout << A + B - mixCount * 2 << "\n";

	return 0;
}