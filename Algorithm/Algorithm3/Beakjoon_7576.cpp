#include <iostream>
#include <queue>

int graph[1000][1000] = { 0 };
bool isVisited[1000][1000] = { false };
int dx[4] = { 0,0,-1,1 }; //����
int dy[4] = { -1,1,0,0 }; //����
int M, N;

using namespace std;


void bfs(int i, int j)
{
	queue<pair<int , int>> que;
	que.push({ i,j });
	isVisited[i][j] = true;

	int x = que.front().first;
	int y = que.front().second;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			isVisited[nx][ny] = true;
		}
	}
}

int countNum = 0;

//��� 1�� ��ġ���� for������ �����¿� true�� ����� ���������
void dfs()
{
	//��� 1 �˻��ϰ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isVisited[i][j] == false && graph[i][j] == 1)
			{
				
				for (int i = 0; i < 4; i++)
				{
					int nx = i + dx[i];
					int ny = j + dy[i];

					if (nx >= 0 && ny >= 0 && nx < N && ny < M)
					{
						if (graph[nx][ny] == 0)
						{
							isVisited[nx][ny] = true;
							graph[nx][ny] = 1;
						}
					}
				}

			}
		}
	}

	countNum++;
	dfs();

}


int main()
{
	//
	// ����
	// 1. �丶�䰡 ���� �ʹ� �ּ��ϼ��� ���Ͻÿ�.
	// 2. ���� 1�� ���� �丶��, ���� 0�� �������� �丶��, ���� -1�� �丶�䰡 �� ���� ���� ĭ
	// 3. �������� �Ǹ� ������(�����¿�)���� ��ġ�� �丶�䰡 �ʹ´�.
	// �Է�
	// 1. ���� N ���� M�� �Է� �޴´�.
	// 2. N ��ŭ �ݺ����� ���� M��ŭ ���ڸ� �Է� �޴´�.
	// ó��
	// 1. 2�� �ݺ������� ������, �丶�䰡 1�λ����� ��� ���� �����¿� �˻��Ͽ� �丶�� üũ���ش�.
	// 2. 
	// ���
	// 1. ����ɶ� ���� �丶�䰡 ��� ���� ���¸� 0�� ����ϰ�, ��� ������ N�� ����ϰ�,
	// ��� ���� ���� ���¶�� -1�� ����ؾ��Ѵ�.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tomato = 0;
			cin >> tomato;
			graph[i][j] = tomato;
		}
	}

	dfs();
	
	cout << countNum << "\n";


	return 0;
}