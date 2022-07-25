#include <iostream>
#include <queue>

using namespace std;

int graph[1000][1000] = { 0 };
int check[1000][1000] = { 0 };
bool isVisited[1000][1000] = { false };
int dx[4] = { 0,0,-1,1 }; //����
int dy[4] = { -1,1,0,0 }; //����
int M, N;
queue<pair<int , int>> que;


void bfs()
{
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (graph[nx][ny] == 0 && isVisited[nx][ny] == false)
				{
					isVisited[nx][ny] = true;
					graph[nx][ny] = 1;
					check[nx][ny] = check[x][y] + 1;
					que.push({ nx,ny });
				}
			}
		}
	}
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
	// 1. 2�� �ݺ����� ���� �丶�䰡 1�� ���¸� �˾Ƴ��� 1�϶� queue�� ������� ��ǥ�� �־���
	// 2. bfs�� ����� �ݺ����� ���� �����¿쿡 0�� �丶�䰡 �ְ� �� ��ǥ�� �湮���� �ʾ����� �湮���ְ� queue�� �־���, �׸��� ���� ������ �Ÿ��� ������ִ� �迭�� ���� ��������
	// => �Ÿ��� �����������ν� queue���� ù��° 1�� ����, �ι�° 1������, ����° 1������...���� �׿����� 
	// ���
	// 1. �丶�䰡 ���;��� �湮 �� ���� ������ -1��ȯ����
	// 1. �丶�� �Ÿ��迭�� ���� ���� ���� ��ȯ����
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 1 && isVisited[i][j] == false)
			{
				que.push({i,j});
				isVisited[i][j] = true;
			}
		}
	}

	bfs();
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0 && isVisited[i][j] == false)
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	int max = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (max < check[i][j])
			{
				max = check[i][j];
			}
		}
	}

	cout << max << "\n";


}