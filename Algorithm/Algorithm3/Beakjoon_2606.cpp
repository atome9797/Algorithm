#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

//vector�� �迭��� ���
vector<int> graph[101];

int bfs()
{
	int count = 0;

	//�湮 ���θ� ����� �迭�� �����Ѵ�.
	bool isVisited[101] = { false };

	//ť�� ����
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

	//�湮 ���θ� ����� �迭�� �����Ѵ�.
	bool isVisited[101] = {false};

	//stack�� ����
	stack<int> st;

	//1�� ��ǻ�Ϳ��� ����
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

	//����
	// 1. 1�� ��ǻ�Ͱ� ���̷��� �ɷ����� �� ���̷����� �ɸ��� ��ǻ���� ���� ����Ͻÿ�. (bfs�� Ǯ�� dfs�� Ǯ��)
	// �Է�
	// 1. �� ��ǻ�� ��(����) N�� �Է� �޴´�.
	// 2. ������ ���� M�� �Է� �޴´�.
	// 3. M������ŭ �ݺ����� ������ ������ �̾��ش�.
	// ó��
	// 4. ������ ���� �������ش�.
	// ���
	// 1. ���ĵ� ������ ù ��°�κ��� ��� ī��Ʈ�Ǵ��� ����Ѵ�.

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	
	cin >> N >> M;

	//������ �����ִ� ��������Ʈ ����� ���
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