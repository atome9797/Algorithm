#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> graph[100001];
bool isVisited[100001] = { false };
int check[100001] = { 0 };

void bfs()
{
	queue<int> que;
	que.push(1);
	isVisited[1] = true;

	while (!que.empty())
	{
		int node = que.front();
		que.pop();

		//자식노드에 부모노드 박아주면됨
		for (int newNode : graph[node])
		{
			if (isVisited[newNode] == false)
			{
				check[newNode] = node;
				isVisited[newNode] = true;
				que.push(newNode);
			}
		}
	}


}

int main()
{
	//
	// 문제
	// 1. 트리의 루트를 1이라고 정했을때 각 노드의 부모를 구하는 프로그램을 작성하시오.
	// 입력
	// 1. 노드의 개수 N을 입력 받는다.
	// 2. n-1개의 간선을 연결할 정점이 주어진다.
	// 처리
	// 1.bfs 방식으로 모든 노드가 정점의 위치를 가지도록 설정함
	// 출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int x = 0;
		int y = 0;
		cin >> x;
		cin >> y;
		graph[y].push_back(x);
		graph[x].push_back(y);
	}

	bfs();

	for (int i = 2; i <= N; i++)
	{
		cout << check[i] << "\n";
	}

	return 0;
}