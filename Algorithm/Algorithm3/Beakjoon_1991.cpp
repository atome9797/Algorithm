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
		//100�϶��� �����ؾ���
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

//���� �켱 => ���� �湮 ������ �θ� �湮�ϰ� �����湮
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
		//100�϶��� �����ؾ���
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



//���� �켱
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
	// ����
	// 1. ���� ��ȸ, ���� ��ȸ, ���� ��ȸ�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ��� ���� N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������.
	// 3. �ش� ��� N�� �ڽ� ��� M K �� �Է� �޴´�. (A�� ��Ʈ ����)
	// 3-1. �ڽ� ��尡 ���� ��쿡�� . ���� ǥ���Ѵ�.
	// ó��
	// 1. queue ������� 
	// ���
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