#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int graph[101][101][101] = {0};
int isVisited[101][101][101] = { false };
int check[101][101][101] = { 0 };
int M = 0, N = 0, H = 0;
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,1,-1,0,0 };

queue<pair<int , pair<int,int>>> que;

void bfs()
{
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int x = que.front().second.first;
			int y = que.front().second.second;
			int z = que.front().first;
			que.pop();

			for (int i = 0; i < 6; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H)
				{

					if (isVisited[nz][nx][ny] == false && graph[nz][nx][ny] == 0)
					{
						isVisited[nz][nx][ny] = true;
						graph[nz][nx][ny] = 1;
						check[nz][nx][ny] = check[z][x][y] + 1;
						pair<int, int> pr = { nx,ny };
						que.push({ nz , pr });
					}

				}

			}
		}
		
	}
}

int main()
{

	// ����
	// 1. �丶�䰡 ������ ���� �����¿����Ʒ� �̴�.
	// 2. ��ĥ�� ������ ��� �丶�䰡 �ʹ��� �ּ��ϼ��� ���ϴ� ���α׷��� ���Ͻÿ�.
	// �Է�
	// 1. ����ũ�⸦ ��Ÿ���� M ,N�� �Է� �޴´�. 
	// 2. �׾� �÷��� ������ �� H�� �Է� �޴´�.
	// 3.H M N�� �ݺ����� ���� 3���� �迭�� �Է� �޴´�.
	// ó��
	// 1. ���� �丶���� ��� queue�� �� �������� ������ �����Ѵ�.
	// 2. bfs���� �� ���� queue�� ��� ������ while���� ������ �Ѵ�.
	// 2-1. �� ������ �ѹ��� queue�� ����ǰ� �Ѵ�.
	// ���
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> M >> N >> H;

	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int tomato = 0;
				cin >> tomato;

				graph[i][j][k] = tomato;
			}
		}
	}

	/// <summary>
	/// ������ �丶�� 1�� ���� ���� �϶�  queue�� �־��ش�.
	/// </summary>
	/// <returns></returns>
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				//�丶�䰡 �;� �ְ� �湮�������� queue�� ����
				if (graph[i][j][k] == 1 && isVisited[i][j][k] == false)
				{
					pair<int, int> pr = {j,k};
					que.push({i, pr });
					isVisited[i][j][k] = true;
				}
			}
		}
	}

	bfs();

	//�湮 ���߰� �丶�䰡 ���;�����
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (graph[i][j][k] == 0 && isVisited[i][j][k] == false)
				{
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}

	//�� �湮������ ī��Ʈ ����
	int max = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (check[i][j][k] > max)
				{
					max = check[i][j][k];
				}
			}
		}
	}

	cout << max << "\n";


}