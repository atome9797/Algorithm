#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// ladder or snake;
int grpah[101];
int isVisited[101];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		grpah[x] = y;
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		grpah[u] = v;
	}

	queue<int> q;
	memset(isVisited, -1, sizeof(isVisited));
	q.push(1);
	isVisited[1] = 0;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int next = current + i;
			if (next > 100) continue;

			// ladder or snake라면 이동해야 한다.
			if (grpah[next] != 0) {
				next = grpah[next];
			}

			//가장 먼저 방문했을때 갱신된다.
			if (isVisited[next] == -1) {
				isVisited[next] = isVisited[current] + 1;
				q.push(next);
			}
		}
	}
	cout << isVisited[100] << "\n";
	return 0;
}