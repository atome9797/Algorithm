#include <iostream>
#include <queue>

using namespace std;

int main()
{

	//
	// 문제
	// 1. 큐를 이용하여 제일 마지막에 남게되는 카드를 구하는 프로그램을 만드시오.
	// 입력
	// 1. N장의 카드 개수를 입력한다.
	// 처리
	// 1. N장의 카드 만큼 반복문을 돌려 데이터를 만든다.
	// 2. while문을 돌려 남는 카드가 1개가 될때 까지 반복한다.
	// 2-1. 제일위의 카드를 버린다.
	// 2-2. 제일 위의 카드를 버리고 카드가 1장 뿐이면 while문을 끝낸다.
	// 2-3. 두번째 위의 카드를 마지막 카드로 옮긴다.
	// 출력
	

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	queue<int> que;

	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}


	while (1)
	{
		if (que.size() == 1)
		{
			break;
		}

		que.pop();
		
		if (que.size() == 1)
		{
			break;
		}

		int num = que.front();
		que.pop();
		que.push(num);
	}

	cout << que.front() << "\n";

}