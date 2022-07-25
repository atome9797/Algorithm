#include <iostream>
#include <queue>

using namespace std;

int graph[1000][1000] = { 0 };
int check[1000][1000] = { 0 };
bool isVisited[1000][1000] = { false };
int dx[4] = { 0,0,-1,1 }; //세로
int dy[4] = { -1,1,0,0 }; //가로
int M, N;
queue<pair<int , int>> que;


void bfs()
{
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (graph[nx][ny] == 0 && isVisited[nx][ny] == false)
				{
					isVisited[nx][ny] = true;
					graph[nx][ny] = 1;
					check[nx][ny] = check[x][y] + 1;
					que.push({ nx,ny });
				}
			}
		}
	}
}


int main()
{
	//
	// 문제
	// 1. 토마토가 전부 익는 최소일수를 구하시오.
	// 2. 정수 1은 익은 토마토, 정수 0은 익지않은 토마토, 정수 -1은 토마토가 들어가 있지 않은 칸
	// 3. 다음날이 되면 인접한(상하좌우)곳에 위치한 토마토가 익는다.
	// 입력
	// 1. 세로 N 가로 M을 입력 받는다.
	// 2. N 만큼 반복문을 돌려 M만큼 숫자를 입력 받는다.
	// 처리
	// 1. 2중 반복문을 돌려 토마토가 1인 상태를 알아내고 1일때 queue에 순서대로 좌표를 넣어줌
	// 2. bfs로 실행시 반복문을 돌려 상하좌우에 0인 토마토가 있고 그 좌표가 방문하지 않았을때 방문해주고 queue에 넣어줌, 그리고 새로 선언한 거리를 계산해주는 배열의 값을 갱신해줌
	// => 거리를 갱신해줌으로써 queue에는 첫번째 1인 지역, 두번째 1인지역, 세번째 1인지역...으로 쌓여나감 
	// 출력
	// 1. 토마토가 안익었고 방문 한 적도 없으면 -1반환해줌
	// 1. 토마토 거리배열의 가장 높은 값을 반환해줌
	// 모두 익지 못한 상태라면 -1을 출력해야한다.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tomato = 0;
			cin >> tomato;
			graph[i][j] = tomato;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 1 && isVisited[i][j] == false)
			{
				que.push({i,j});
				isVisited[i][j] = true;
			}
		}
	}

	bfs();
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0 && isVisited[i][j] == false)
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	int max = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < check[i][j])
			{
				max = check[i][j];
			}
		}
	}

	cout << max << "\n";


}