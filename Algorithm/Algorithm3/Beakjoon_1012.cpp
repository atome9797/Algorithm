#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dx[4] = { 1,-1,0,0 }; //세로
int dy[4] = { 0,0,1,-1 }; //가로
int T = 0, M = 0, N = 0, K = 0;

//배열은 포인터로 사용가능해서 매개변수로 넘길때 참조해서 사용할수 있다.
void dfs(int x , int y, vector<int> graph[] , int isVisited[][50])
{

	//true로 바꿔주고 깊은 탐색해줌
	isVisited[x][y] = true;


	//상하좌우 검색한다.
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];//세로
		int ny = y + dy[i];//가로

		if (nx >=0 && ny >= 0 && nx < M && ny < N)
		{
			if (isVisited[nx][ny] == false && graph[nx][ny] == 1)
			{
				dfs(nx, ny, graph, isVisited);
			}
		}
	}
}

int main()
{

	//
	// 문제
	// 1. 지렁이는 인접한(상하좌우) 다른 배추로 이동할수있고 , 배추 모여있는곳에 1마리만 있으면됨
	// 2. 배추들이 몇 군데에 퍼져 있는지 조사하고 필요한 지렁이의 개수를 구하시오.
	// 입력
	// 1. 테스트 케이스 T를 입력 받는다.
	// 2. 테스트 케이스 만큼 반복문을 돌린다.
	// 3. 배추밭의 가로길이 M, 세로길이 N , 배추가 심어져 있는 개수 K를 입력받는다.
	// 4. K개수 만큼 반복문을 돌려 해당 좌표에 1을 넣어준다.
	// 처리
	// 1. 구성된 그래프에서 2차원 배열로 bool타입으로 방문여부를 확인후 방문하지 않았으면 방문해준다.
	// 2. dfs방식으로 이웃한 곳까지 for문으로 방문해준다.
	// 3. 다 방문했으면 cnt값을 반환한다.
	// 4. cnt값은 새로운 벡터 배열에 담아준다.
	// 출력 
	// 1. 벡터 배열의 크기를 반환해준다.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	//맵 세팅
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		int cnt = 0;
		vector <int> graph[50];
		int isVisited[50][50] = { false };

		//전체 맵을 0으로초기화
		for (int posX = 0; posX < M; posX++)
		{
			for (int posY = 0; posY < N; posY++)
			{
				graph[posX].push_back(0);
			}
		}

		//일정 좌표를 1로 설정
		for (int j = 0; j < K; j++)
		{
			int posX_t = 0;
			int posY_t = 0;

			cin >> posX_t >> posY_t;

			graph[posX_t][posY_t] = 1;
		}

		//2차원 배열로 전체맵을 검색하여 방문하지 않은곳을 가져옴
		for (int posX = 0; posX < M; posX++)
		{
			for (int posY = 0; posY < N; posY++)
			{
				if (graph[posX][posY] == 1 && isVisited[posX][posY] == false)
				{
					dfs(posX, posY , graph , isVisited);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

	}



	return 0;
}