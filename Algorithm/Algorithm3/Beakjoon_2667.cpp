#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[25];


bool isVisited[25] = { false };

int bfs(int start)
{
	int count = 0;

	queue<int> que;
	que.push(start);
	
	isVisited[start] = true;

	while (!que.empty())
	{
		
		

	}
	

	return count;
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
	// 1. 그려진 그래프에서 1부터 n까지의 정점에 이어진 간선의 횟수를 더해준다.
	// 2. 1로 이어진 부분의 데이터를 불러와 bfs로 1로 이어진 부분을 검색한다.
	// 3. 
	// 출력
	// 1. 총 단지수를 출력한다.
	// 2. 각 단지에 속한 집의수를 출력한다.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
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

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (bfs(i) != 0)
		{
			count++;
		}
	}

	cout << count << "\n";
	for (int i = 0; i < N; i++)
	{
		if (bfs(i) != 0)
		{
			cout << bfs(i) << "\n";
		}
	}

	



	return 0;
}