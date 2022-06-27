#include <iostream>
#include <queue>

using namespace std;

int main()
{

	//
	// 문제
	// 1. N 명의 사람들 에서 K번째 사람을 제거하는 규칙을 만들어라
	// 입력
	// 1. N명과 K번째를 입력받는다.
	// 처리
	// 1. while문을 돌려 큐의 사이즈가 1이 될때 까지 반복한다.
	// 2. 큐에서 3번째 것을 제외한 나머지만 push 되게하는 큐를 하나 더 만든다.
	// 2-1. 리사이즈 큐에서 count 만큼을 나눈 나머지값부분의 원소를 제외한 원소를 큐에 저장한다.
	// 3. 3번째 것은 출력한다
	// 4. 사이즈가 1이 될때 까지 반복한다.
	// 출력

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int K = 0;
	cin >> N >> K;

	queue<int> que;
	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}

	int count = K;
	int maxSize = que.size();

	cout << "<";

	while (1)
	{
		if (que.size() == 1)
		{
			cout << que.front() << ">";
			break;
		}

		queue<int> que2;
		queue<int> que3;
		que3 = que;



		for (int i = 1; i <= que.size(); i++)
		{
			int num = que3.front();
			que3.pop();

			//int t = count % que.size();

			if (count == 0)
			{
				count = que.size();
			}


			if (i != count)
			{
				que2.push(num);
			}
			else
			{
				cout << num << ", ";
			}
		}

		//		//이전 위치 + 카운트
		//count = count + K - 1;
		//
		//if (count == K)
		//{
		//	count = K;
		//}

		//if (count > maxSize)
		//{
		//	count = count - maxSize;
		//}

		count = (count + K - 1) % que2.size();


		//que를 재구성해준다.
		swap(que, que2);

	}


	return 0;
}