#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	//
	// 문제
	// 1. 최소힙을 구하라
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 반복문을 돌리며, x가 자연수이면 x값을 원소로 추가하고, x가 0이면 가장작은값을 출력한다.(제거)
	// 음의 정수는 입력 받지 않는다.
	// 처리
	// 1. 입력 0이 주어진 만큼 답을 출력한다.
	// 2. 배열에 가장 작은값이 있을경우에 가장작은값을 출력하고 배열이 비어있으면 0을 출력한다.
	// 출력
	//

	priority_queue<int> pq;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (num == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() * (- 1) << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(num * -1);
		}
	}

	return 0;
}