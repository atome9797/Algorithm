#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int graph[101][101][101] = {0};
int isVisited[101][101][101] = { false };
int check[101][101][101] = { 0 };
int M = 0, N = 0, H = 0;
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,1,-1,0,0 };

queue<pair<int , pair<int,int>>> que;

void bfs()
{
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
						isVisited[nz][nx][ny] = true;
						graph[nz][nx][ny] = 1;
						check[nz][nx][ny] = check[z][x][y] + 1;
						pair<int, int> pr = { nx,ny };
						que.push({ nz , pr });
					}

				}

			}
		}
		
	}
}

int main()
{

	// 문제
	// 1. 토마토가 인접한 곳은 상하좌우위아래 이다.
	// 2. 며칠이 지나면 모든 토마토가 익는지 최소일수를 구하는 프로그램을 구하시오.
	// 입력
	// 1. 상자크기를 나타내는 M ,N을 입력 받는다. 
	// 2. 쌓아 올려진 상자의 수 H를 입력 받는다.
	// 3.H M N을 반복문을 돌려 3차원 배열을 입력 받는다.
	// 처리
	// 1. 익은 토마토일 경우 queue에 각 층마다의 정보를 저장한다.
	// 2. bfs에서 각 층의 queue가 비어 있으면 while문이 끝나게 한다.
	// 2-1. 각 층마다 한번씩 queue에 저장되게 한다.
	// 출력
	
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
				int tomato = 0;
				cin >> tomato;

				graph[i][j][k] = tomato;
			}
		}
	}

	/// <summary>
	/// 각층의 토마토 1인 익은 상태 일때  queue에 넣어준다.
	/// </summary>
	/// <returns></returns>
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				//토마토가 익어 있고 방문안했을때 queue에 담음
				if (graph[i][j][k] == 1 && isVisited[i][j][k] == false)
				{
					pair<int, int> pr = {j,k};
					que.push({i, pr });
					isVisited[i][j][k] = true;
				}
			}
		}
	}

	bfs();

	//방문 안했고 토마토가 안익었을때
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (graph[i][j][k] == 0 && isVisited[i][j][k] == false)
				{
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}

	//다 방문했을때 카운트 해줌
	int max = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (check[i][j][k] > max)
				{
					max = check[i][j][k];
				}
			}
		}
	}

	cout << max << "\n";


}