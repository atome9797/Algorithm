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

		//�ڽĳ�忡 �θ��� �ھ��ָ��
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
	// ����
	// 1. Ʈ���� ��Ʈ�� 1�̶�� �������� �� ����� �θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ����� ���� N�� �Է� �޴´�.
	// 2. n-1���� ������ ������ ������ �־�����.
	// ó��
	// 1.bfs ������� ��� ��尡 ������ ��ġ�� �������� ������
	// ���
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