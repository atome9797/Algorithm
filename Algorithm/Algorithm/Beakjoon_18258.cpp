#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// 문제
	// 1. 큐를 이용하여 입력을 처리하는 프로그램을 만드시오.
	// 입력
	// 1. 명령어의 수를 입력한다.
	// 2. 명령어를  입력한다.
	// 처리
	// 1. 명령어에 맞게 큐를 작성한다.
	// 출력

	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> que;

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		if (str == "push")
		{
			int num = 0;
			cin >> num;

			que.push(num);
		}
		else if (str == "pop")
		{
			if (que.empty() == false)
			{
				cout << que.front() << "\n";
				que.pop();
			}
			else 
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "size")
		{
			cout << que.size() << "\n";
		}
		else if (str == "empty")
		{
			if (que.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (str == "front")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << que.front() << "\n";
			}
		}
		else if (str == "back")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << que.back() << "\n";
			}
		}

	}


	return 0;
}