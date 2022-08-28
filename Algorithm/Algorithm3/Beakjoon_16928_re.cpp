#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int graph[101] = {0};
int isVisited[101] = {0};


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;

	cin >> N >> M;

	memset(isVisited, -1, sizeof(isVisited));

	for (int i = 0; i < N + M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u] = v;
	}

	queue<int> que;
	que.push(1);
	isVisited[1] = 0;

	while (!que.empty())
	{
		int current = que.front();
		que.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = current + i;

			if (next > 100)
			{
				continue;
			}

			if (graph[next] != 0)
			{
				next = graph[next];
			}

			if (isVisited[next] == -1)
			{
				isVisited[next] = isVisited[current] + 1;
				que.push(next);
			}
		}

	}

	cout << isVisited[100] << "\n";



	return 0;
}