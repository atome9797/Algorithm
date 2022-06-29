#include <iostream>
#include <queue>

using namespace std;

int graph[100][100] = { 0 };
int check[100][100] = { 0 };
int N, M;
bool isVisited[100][100] = { false };
int dx[4] = { 0,0,-1,1 }; //세로
int dy[4] = { -1,1,0,0 }; //가로

int minNum = 10000;

void dfs(int x, int y, int depth)
{

	isVisited[x][y] = true;

	if (x == (N - 1) && y == (M - 1))
	{
		if (depth < minNum)
		{
			minNum = depth;
		}
		return;
	}


	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (graph[nx][ny] == 1 && isVisited[nx][ny] == false)
			{
				dfs(nx, ny, depth + 1);
				isVisited[nx][ny] = false;
			}
		}
	}
}

void bfs(int i , int j)
{
	queue <pair<int,int>> que;
	que.push({i,j});
	isVisited[i][j] = true;

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
				if (isVisited[nx][ny] == false && graph[nx][ny] == 1)
				{
					isVisited[nx][ny] = true; //가장 먼저 true로 바뀌면 가장 가깝다는 뜻이다.
												//가장 가까운 거리가 저장되고 업뎃 안된다.
					check[nx][ny] = check[x][y] + 1;
					que.push({ nx,ny });
				}
			}
		}
		
	}

}


int main()
{
	 
	// dfs방식으로 푸는 방식으로 모든 경우의 수를 구할때 시간 복잡도가 올라간다. 
	// 그래서 bfs방식으로 풀어야 한다.
	// 
 	// 문제
	// 1. (1,1)에서 출발해서 (N,M)의 위치로 이동할때 지나야하는 최소 칸수를 구하시오.
	// 2. 이동할때 인접한 칸으로만 이동할수 있음
	// 입력
	// 1. 세로 N과 가로 M을 입력 받는다.
	// 2. 가로 입력 받은 값을 M만큼 반복문을 돌리며 map에 저장한다.
	// 처리
	// 1. 시작위치를 (1,1)로 잡고 dfs방식으로 구현한다.
	// 2. dfs로 구현할때 갈수있는 경우의 수중 제일 작은값을 가지는 길을 출력한다.
	// 3. 재귀함수로 구현하고 한번만 길을 이용할때 최단거리를 구한다.
	// 4. 깊이 들어갈때 깊이 + 1작업을 해주고 방문 여부를 true 해준다음, 재귀 끝나는 지점에서 다시 false 로 바꿔준다. => 그러면 다음 노드쪽에서 true로 체크한 나머지를 검사하기 때문에 유용하다.
	// 5. 마지막 좌표에 도달했을때, 좌표가 최솟값보다 더 작으면 갱신해주고 리턴한다.
	// 출력


	// bfs방식
	// 가중치가 모두 동일한 경우 bfs통해 최단 거리를 구할수있다.
	// 
	// 문제
	// 1. (1,1)에서 출발해서 (N,M)의 위치로 이동할때 지나야하는 최소 칸수를 구하시오.
	// 2. 이동할때 인접한 칸으로만 이동할수 있음
	// 입력
	// 1. 세로 N과 가로 M을 입력 받는다.
	// 2. 가로 입력 받은 값을 M만큼 반복문을 돌리며 map에 저장한다.
	// 처리
	// 1. 시작위치를 (1,1)로 잡고 bfs방식으로 구현한다.
	// 2. bfs로 구현할때 갈수있는 경우의 수중 제일 작은값을 가지는 길을 출력한다.
	// 3. 방문 표시를 체크할 2차원 배열을 선언하고, 이동할 좌표에 이전 좌표 + 1해주면서 
	//		이전 좌표값에 + 1을 해서 최 단기 길을 찾는 방법
	// 출력



	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = str[j] - '0';
		}
	}

	//dfs는 경로를 탐색하는데 시간이 오래 걸린다. 모든 경우의 수를 다 검색해야 하기 때문
	// 따라서 bfs방식으로 사용한다.
	//
	//dfs(0, 0, 1);

	bfs(0 , 0);

	cout << check[N - 1][M - 1] + 1 << "\n";



	return 0;
}