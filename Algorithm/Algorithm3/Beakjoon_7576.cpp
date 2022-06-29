#include <iostream>
#include <queue>

int graph[1000][1000] = { 0 };
bool isVisited[1000][1000] = { false };
int dx[4] = { 0,0,-1,1 }; //세로
int dy[4] = { -1,1,0,0 }; //가로
int M, N;

using namespace std;


void bfs(int i, int j)
{
	queue<pair<int , int>> que;
	que.push({ i,j });
	isVisited[i][j] = true;

	int x = que.front().first;
	int y = que.front().second;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			isVisited[nx][ny] = true;
		}
	}
}

int countNum = 0;

//모든 1인 위치에서 for문으로 상하좌우 true로 만들기 재귀적으로
void dfs()
{
	//모든 1 검색하고
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isVisited[i][j] == false && graph[i][j] == 1)
			{
				
				for (int i = 0; i < 4; i++)
				{
					int nx = i + dx[i];
					int ny = j + dy[i];

					if (nx >= 0 && ny >= 0 && nx < N && ny < M)
					{
						if (graph[nx][ny] == 0)
						{
							isVisited[nx][ny] = true;
							graph[nx][ny] = 1;
						}
					}
				}

			}
		}
	}

	countNum++;
	dfs();

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
	// 1. 2중 반복문으로 돌리며, 토마토가 1인상태의 모든 것을 상하좌우 검사하여 토마토 체크해준다.
	// 2. 
	// 출력
	// 1. 저장될때 부터 토마토가 모두 익은 상태면 0을 출력하고, 모두 익으면 N을 출력하고,
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

	dfs();
	
	cout << countNum << "\n";


	return 0;
}