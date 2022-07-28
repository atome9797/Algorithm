#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. x좌표, y좌표 를 정렬하는 순서대로 출력하라
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 반복문을 돌리며 x, y좌표를 입력 받는다.
	// 처리
	// 1. sort 문을 써서 정렬시킨다.
	// 출력
	//

	multiset<pair<int, int>> set;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X = 0;
		int Y = 0;
		cin >> X >> Y;

		set.insert({ X, Y });
	}

	//sort(set.begin(), set.end());
	for (multiset<pair<int, int>>::iterator iter = set.begin(); iter != set.end(); iter++)
	{
		pair<int, int> p1 = *iter;
		cout << p1.first << " " << p1.second << "\n";
	}


	/*for (pair <int, int> p1 : set)
	{
		cout << p1.first << " " << p1.second << "\n";
	}*/

	return 0;
}