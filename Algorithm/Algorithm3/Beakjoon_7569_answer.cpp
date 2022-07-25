#include <iostream>
#include <queue>

using namespace std;

int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,1,-1,0,0 };

queue<pair<int, pair<int, int>>> que; //3차원 배열을 받기 위한 작업
int graph[100][100][100] = { 0 };
bool isVisited[100][100][100] = { false };
int N, M, H;
int tomatoCount = 0;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> graph[i][j][k];

				if (graph[i][j][k] == 1)
				{
					isVisited[i][j][k] = true;
					pair<int, int> pair1 = { j , k };
					que.push({i, pair1});
				}
				else if (graph[i][j][k] == 0)
				{
					tomatoCount++;
				}

			}
		}
	}

	//queue에 1인 경우가 다 들어 있음
	int dayCount = 0;
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int x = que.front().second.first;
			int y = que.front().second.second;
			int z = que.front().first;
			que.pop();

			for (int i = 0; i < 6; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H)
				{
					if (isVisited[nz][nx][ny] == false && graph[nz][nx][ny] == 0)
					{
						graph[nz][nx][ny] = 1;
						isVisited[nz][nx][ny] = true;
						pair<int, int> pair2 = { nx, ny };
						que.push({ nz,pair2 });
						tomatoCount--;
					}
				}
			}
		}
		dayCount++;
	}

	if (tomatoCount != 0)
	{
		cout << -1 << "\n";
		return 0;
	}

	cout << dayCount - 1 << "\n";
	


}