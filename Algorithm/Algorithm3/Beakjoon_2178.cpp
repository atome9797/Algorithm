#include <iostream>
#include <queue>

using namespace std;

int graph[100][100] = { 0 };
int check[100][100] = { 0 };
int N, M;
bool isVisited[100][100] = { false };
int dx[4] = { 0,0,-1,1 }; //����
int dy[4] = { -1,1,0,0 }; //����

int minNum = 10000;

void dfs(int x, int y, int depth)
{

	isVisited[x][y] = true;

	if (x == (N - 1) && y == (M - 1))
	{
		if (depth < minNum)
		{
			minNum = depth;
		}
		return;
	}


	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (graph[nx][ny] == 1 && isVisited[nx][ny] == false)
			{
				dfs(nx, ny, depth + 1);
				isVisited[nx][ny] = false;
			}
		}
	}
}

void bfs(int i , int j)
{
	queue <pair<int,int>> que;
	que.push({i,j});
	isVisited[i][j] = true;

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
				if (isVisited[nx][ny] == false && graph[nx][ny] == 1)
				{
					isVisited[nx][ny] = true; //���� ���� true�� �ٲ�� ���� �����ٴ� ���̴�.
												//���� ����� �Ÿ��� ����ǰ� ���� �ȵȴ�.
					check[nx][ny] = check[x][y] + 1;
					que.push({ nx,ny });
				}
			}
		}
		
	}

}


int main()
{
	 
	// dfs������� Ǫ�� ������� ��� ����� ���� ���Ҷ� �ð� ���⵵�� �ö󰣴�. 
	// �׷��� bfs������� Ǯ��� �Ѵ�.
	// 
 	// ����
	// 1. (1,1)���� ����ؼ� (N,M)�� ��ġ�� �̵��Ҷ� �������ϴ� �ּ� ĭ���� ���Ͻÿ�.
	// 2. �̵��Ҷ� ������ ĭ���θ� �̵��Ҽ� ����
	// �Է�
	// 1. ���� N�� ���� M�� �Է� �޴´�.
	// 2. ���� �Է� ���� ���� M��ŭ �ݺ����� ������ map�� �����Ѵ�.
	// ó��
	// 1. ������ġ�� (1,1)�� ��� dfs������� �����Ѵ�.
	// 2. dfs�� �����Ҷ� �����ִ� ����� ���� ���� �������� ������ ���� ����Ѵ�.
	// 3. ����Լ��� �����ϰ� �ѹ��� ���� �̿��Ҷ� �ִܰŸ��� ���Ѵ�.
	// 4. ���� ���� ���� + 1�۾��� ���ְ� �湮 ���θ� true ���ش���, ��� ������ �������� �ٽ� false �� �ٲ��ش�. => �׷��� ���� ����ʿ��� true�� üũ�� �������� �˻��ϱ� ������ �����ϴ�.
	// 5. ������ ��ǥ�� ����������, ��ǥ�� �ּڰ����� �� ������ �������ְ� �����Ѵ�.
	// ���


	// bfs���
	// ����ġ�� ��� ������ ��� bfs���� �ִ� �Ÿ��� ���Ҽ��ִ�.
	// 
	// ����
	// 1. (1,1)���� ����ؼ� (N,M)�� ��ġ�� �̵��Ҷ� �������ϴ� �ּ� ĭ���� ���Ͻÿ�.
	// 2. �̵��Ҷ� ������ ĭ���θ� �̵��Ҽ� ����
	// �Է�
	// 1. ���� N�� ���� M�� �Է� �޴´�.
	// 2. ���� �Է� ���� ���� M��ŭ �ݺ����� ������ map�� �����Ѵ�.
	// ó��
	// 1. ������ġ�� (1,1)�� ��� bfs������� �����Ѵ�.
	// 2. bfs�� �����Ҷ� �����ִ� ����� ���� ���� �������� ������ ���� ����Ѵ�.
	// 3. �湮 ǥ�ø� üũ�� 2���� �迭�� �����ϰ�, �̵��� ��ǥ�� ���� ��ǥ + 1���ָ鼭 
	//		���� ��ǥ���� + 1�� �ؼ� �� �ܱ� ���� ã�� ���
	// ���



	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = str[j] - '0';
		}
	}

	//dfs�� ��θ� Ž���ϴµ� �ð��� ���� �ɸ���. ��� ����� ���� �� �˻��ؾ� �ϱ� ����
	// ���� bfs������� ����Ѵ�.
	//
	//dfs(0, 0, 1);

	bfs(0 , 0);

	cout << check[N - 1][M - 1] + 1 << "\n";



	return 0;
}