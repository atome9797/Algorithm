#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

//vector를 배열대신 사용
vector<int> graph[101];

int bfs()
{
	int count = 0;

	//방문 여부를 담아줄 배열을 선언한다.
	bool isVisited[101] = { false };

	//큐로 구현
	queue<int> que;
	que.push(1);
	isVisited[1] = true;
	
	while (!que.empty())
	{
		
		int node = que.front();
		que.pop();

		for (int nextNode : graph[node])
		{
			if (isVisited[nextNode] == false)
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
				count++;
			}
		}
	}

	return count;

}


int dfs()
{
	int count = 0;

	//방문 여부를 담아줄 배열을 선언한다.
	bool isVisited[101] = {false};

	//stack로 구현
	stack<int> st;

	//1번 컴퓨터에서 시작
	st.push(1);
	isVisited[1] = true;

	while (!st.empty())
	{
		int node = st.top();
		if (isVisited[node] == false)
		{
			isVisited[node] = true;
			count++;
		}
		st.pop();
		
		for (int newNode : graph[node])
		{
			if (isVisited[newNode] == false)
			{
				st.push(newNode);
			}
		}
	}


	return count;
}

int main()
{

	//문제
	// 1. 1번 컴퓨터가 바이러스 걸렸을때 웜 바이러스가 걸리는 컴퓨터의 수를 출력하시오. (bfs로 풀고 dfs로 풀기)
	// 입력
	// 1. 총 컴퓨터 수(정점) N을 입력 받는다.
	// 2. 간선의 갯수 M을 입력 받는다.
	// 3. M갯수만큼 반복문을 돌리며 간선을 이어준다.
	// 처리
	// 4. 정점의 수를 정렬해준다.
	// 출력
	// 1. 정렬된 정점의 첫 번째로부터 몇개가 카운트되는지 출력한다.

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	
	cin >> N >> M;

	//간선을 이저주는 인접리스트 방식을 사용
	for (int i = 0; i < M; i++)
	{
		int node, node2;
		cin >> node >> node2;

		graph[node].push_back(node2);
		graph[node2].push_back(node);
	}
	

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	//cout << bfs();

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].rbegin(), graph[i].rend());
	}

	cout << dfs();


	return 0;
}