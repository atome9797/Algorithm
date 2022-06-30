#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<pair<int,int>> graph[26];
bool isVisited[26] = {false};
bool isVisited2[26] = {false};
int x, y, z;

string alpha[26] = { "A","B","C","D","E","F","G","H" ,"I","J","K","L" ,"M","N","O","P" ,"Q","R","S","T","U","W","X","Y","Z"};


void dfs(int node)
{
	isVisited[0] = true;
	cout << alpha[node];

	for (pair<int, int> newNode : graph[node])
	{
		//100일때를 생각해야함
		int x = newNode.first;
		int y = newNode.second;

		if (isVisited[x] == false && x < 27)
		{
			isVisited[x] = true;
			dfs(x);
		}
		else if (isVisited[x] == true && isVisited[node] == true && y < 27)
		{
			isVisited[x] = true;
			dfs(y);
		}
	}
}

//중위 우선 => 좌측 방문 했으면 부모 방문하고 우측방문
void center(int node)
{

	int test1 = graph[node].front().first;
	int test2 = graph[node].front().second;

	if (test1 == 100 && test2 == 100)
	{
		cout << alpha[node];
		isVisited2[node] = true;
		return;
	}

	for (pair<int,int> newNode : graph[node])
	{
		//100일때를 생각해야함
		int x = newNode.first;
		int y = newNode.second;

		if (isVisited2[x] == false && x < 27)
		{
			center(x);
			cout << alpha[node];
			isVisited2[node] = true;
		}
		else if (isVisited2[x] == true && isVisited2[node] == true && y < 27)
		{
			center(y);
			cout << alpha[y];
			isVisited2[node] = true;
		}
	}
}



//후위 우선
//void bfs()
//{
//	bool isVisited[26] = { false };
//	queue<int> que;
//	que.push(0);
//	isVisited[0] = true;
//
//	while (!que.empty())
//	{
//		int node = que.front();
//		que.pop();
//
//		for (int newNode : graph[node])
//		{
//			if (isVisited[newNode] == false && )
//			{
//
//			}
//		}
//
//	}
//}


int main()
{

	//
	// 문제
	// 1. 전위 순회, 중위 순회, 후위 순회한 결과를 출력하는 프로그램을 작성하시오.
	// 입력
	// 1. 노드 개수 N을 입력 받는다.
	// 2. N만큼 반복문을 돌린다.
	// 3. 해당 노드 N과 자식 노드 M K 를 입력 받는다. (A가 루트 노드다)
	// 3-1. 자식 노드가 없는 경우에는 . 으로 표현한다.
	// 처리
	// 1. queue 방식으로 
	// 출력
	// 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char chx;
		char chy;
		char chz;
		
		cin >> chz;
		cin >> chx;
		cin >> chy;

		z = chz - 'A';
		if (chx == '.' && chy == '.')
		{
			graph[z].push_back({ 100,100});
		}
		else if (chx == '.')
		{
			y = chy - 'A';
			graph[z].push_back({100,y});
		}
		else if (chy == '.')
		{
			x = chx - 'A';
			graph[z].push_back({x,100});
		}
		else
		{
			x = chx - 'A';
			y = chy - 'A';
			
			graph[z].push_back({ x,y });
		}
	}

	//dfs(0);
	center(0);
	//bfs(0);

	

	return 0;
}