#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. 연산의 최솟값을 출력하는 프로그램을 작성하시오.
	// 입력
	// 1. 큐의크기 N과 뽑아내려는 개수 M을 입력 받는다.
	// 2. M개 만큼 뽑아내려는 수의 위치를 입력 받는다.
	// 처리
	// 1. 1번 절차를 제외한 2,3번 절차를 이용해 해당 원소의 지점까지 가는 방법을 카운트 한다.
	// 2. 해당 지점에 갔으면 원소를 삭제하고 다음 원소를 찾으러 간다.
	// 출력
	//

	int N , M;
	
	cin >> N >> M;
	deque<int> dq;
	deque<int> dq2;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
		dq2.push_back(i);
	}

	int count = 0;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;

		int leftCount = 0;
		int rightCount = 0;
		//num값이 어디 위치해 있는지 찾고 count 해주기
		//앞으로 가고 뒤로 가서 어떤 값이 최솟값인지 구하고 최솟값으로 출력하기
		while (!dq.empty())
		{
			if (dq.front() == num)
			{
				break;
			}
			dq.push_back(dq.front());
			dq.pop_front();
			leftCount++;
		}

		while (!dq2.empty())
		{
			if (dq2.front() == num)
			{
				break;
			}
			dq2.push_front(dq2.back());
			dq2.pop_back();
			rightCount++;
		}

		if (leftCount < rightCount)
		{
			count += leftCount;
		}
		else
		{
			count += rightCount;
		}

		dq.pop_front();
		dq2.pop_front();
	}
	
	cout << count;

	return 0;
}