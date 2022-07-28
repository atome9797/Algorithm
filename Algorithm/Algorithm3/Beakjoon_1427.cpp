#include <iostream>
#include <set>

using namespace std;

int main()
{
	//
	// 문제
	// 1. 수의 각 자리수를 내림차순으로 정렬하자
	// 입력
	// 1. N을 입력받는다.
	// 처리
	// 출력
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	multiset<int> set;

	while (1)
	{
		int num = N % 10;
		set.insert(num);

		N = N / 10;

		if (N == 0)
		{
			break;
		}
	}

	int count = 1;
	int result = 0;
	for (int element : set)
	{
		result += element * count;

		count *= 10;
	}

	cout << result << "\n";

	return 0;
}