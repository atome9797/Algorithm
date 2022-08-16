#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec[100001];
bool isChecked[100001] = { false };
int result[100001];
int N, M, R;
int countNum = 0;

void bfs(int num)
{

	queue<int> que;
	que.push(num);
	countNum++;
	result[num] = countNum;
	isChecked[num] = true;

	while (!que.empty())
	{
		int index = que.front();

		que.pop();

		for (int element : vec[index])
		{
			if (isChecked[element] == false)
			{
				isChecked[element] = true;
				que.push(element);
				countNum++;
				result[element] = countNum;
			}
		}

	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	//
	// 문제
	// 1. bfs로 방문순서를 구하시오.
	// 입력
	// 처리 
	// 출력
	//

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(vec[i].rbegin(), vec[i].rend());
	}

	bfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}