#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[25];
vector<int> danjiVec;

//이차원 배열로 받아야 한다.
bool isVisited[25][25] = {false};
int cnt = 0; //카운트할 단지수

int dx[4] = {1,-1,0,0}; // x
int dy[4] = {0,0,-1,1}; // y
int N = 0;
void bfs(int y, int x)
{
	queue<pair<int, int>> que;

	que.push({ y,x });
	isVisited[y][x] = true;
	cnt++;

	while (!que.empty())
	{

		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && nx < N && ny < N && graph[ny][nx] == 1 && isVisited[ny][nx] == false)
			{
				isVisited[ny][nx] = true;
				cnt++;
				que.push({ ny,nx });
			}
		}
	}

}

int main()
{
	
	//
	// 문제
	// 1. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하시오.
	// 입력
	// 1. 지도의 크기 N을 입력 받는다.
	// 2. N * N의 지도를 입력 받는다. 반복문
	// 처리
	// 1. 반복문을 돌려 이차원 배열의 값이 1이고 이차원 배열 bool 타입이 false일때 bfs함수를 실행시킨다.
	// 2. bfs에서 해당 좌표값을 queue로 받은뒤 true로 바꿔주고 count+1한 후 while문을 돌린다.
	// 2-1. while문에서는 좌표값을 꺼내주고 for문을 돌린다.for문을 돌릴때 4번 돌려  상하좌우로 움직였을때 1인 값이 있으면 true로 바꿔주고 push해준다. 또한 count+1해준다.
	// 3. 카운트값을 다 구했으면 함수를 종료후 단지수를 늘려주고 카운트는 초기화 시킨다.
	// 4. 다음 단지수의 배열에 또 찾아서 삽입하는 방식으로 사용한다.
	// 출력
	// 1. 단지수별로 몇개 카운트 됬는지 출력한다.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	//인접 행렬로 구성됨
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char map;
			cin >> map;
			int test = map - '0';
			graph[i].push_back(test);
		}
	}

	int danji = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1 && isVisited[i][j] == false)
			{
				bfs(i,j);
				danjiVec.push_back(cnt);
				cnt = 0;
			}
		}
	}

	cout << danjiVec.size() << "\n";

	sort(danjiVec.begin(), danjiVec.end());

	for (int element : danjiVec)
	{
		cout << element << "\n";
	}



	return 0;
}