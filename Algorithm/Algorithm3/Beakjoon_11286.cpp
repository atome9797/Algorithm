#include <iostream>
#include <queue>

using namespace std;

int main()
{
	//
	// 문제
	// 1. 절댓값 힙의 자료구조 
	// 입력
	// 1. 연산의 개수 N을 입력 받는다.
	// 2. N만큼 반복문을 돌린다.
	// 2-1. 0이 아니라면 배열에 값 추가
	// 2-2. 0이라면 절댓값이 가장 작은 값을 출력하고 배열에서 제거
	// 2-2-1. 절대값이 가장 작은값이 여러개면 가장 작은수를 출력한다.
	// 처리
	// 출력
	// 1. 0입력 횟수만큼 답을 출력한다. (가장 작은값)
	// 1-1. 비어있는데 절대값이 가장 작은 값을 출력하려고 하는 경우 0을 출력한다.

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	//0면 마이너스임
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		//입력할 경우
		if (num != 0)
		{
			//마이너스일 경우
			if (num < 0)
			{
				pq.push({ num, 1 });
			}
			else 
			{
				num *= -1;
				pq.push({ num, 0 });
			}
		}

		//출력할 경우 
		else if (num == 0 && !pq.empty())
		{
			if (pq.top().second == 0)
			{
				cout << pq.top().first * (-1) << "\n";
			}
			else
			{
				cout << pq.top().first << "\n";
			}
			pq.pop();
		}
		else
		{
			cout << 0 << "\n";
		}
	}


	return 0;
}