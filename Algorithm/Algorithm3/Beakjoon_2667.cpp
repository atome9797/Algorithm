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
	// ����
	// 1. ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����Ͻÿ�.
	// �Է�
	// 1. ������ ũ�� N�� �Է� �޴´�.
	// 2. N * N�� ������ �Է� �޴´�. �ݺ���
	// ó��
	// 1. �׷��� �׷������� 1���� n������ ������ �̾��� ������ Ƚ���� �����ش�.
	// 2. 1�� �̾��� �κ��� �����͸� �ҷ��� bfs�� 1�� �̾��� �κ��� �˻��Ѵ�.
	// 3. 
	// ���
	// 1. �� �������� ����Ѵ�.
	// 2. �� ������ ���� ���Ǽ��� ����Ѵ�.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	//���� ��ķ� ������
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