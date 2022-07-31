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
	// 1. 문서에 중요도가 있을때 해당 문서의 출력순서를 구하시오. (왼족부터 출력하는 방식)
	// 입력
	// 1. 테스트 케이스수 test_case 를 입력 받는다.
	// 2. 문서의 개수 N과 queue 의 요쇼중 M번째 요소가 출력되는 번호를 출력하게 한다.
	// 처리
	// 1. 전체를 검사한뒤 맨 앞보다 중요도가 큰게 있으면 맨뒤로 이동하게한다.
	// 출력
	//

	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		int N, QueueIndex;
		cin >> N >> QueueIndex;
		
		priority_queue<int> pq;
		queue<pair<int, bool>> que;


		for (int i = 0; i < N; i++)
		{
			int document = 0;
			bool result = false;
			cin >> document;

			if (QueueIndex == i)
			{
				result = true;
			}
			else
			{
				result = false;
			}

			que.push({ document, result });
			pq.push(document);
		}
		int count = 1;
		
		while (!pq.empty())
		{
			while (pq.top() > que.front().first)
			{
				que.push({ que.front().first , que.front().second });
				que.pop();
			}
			pq.pop();

			if (que.front().second == true)
			{
				cout << count << "\n";
				break;
			}
			que.pop();
			count++;
		}

		

	}

	return 0;
}