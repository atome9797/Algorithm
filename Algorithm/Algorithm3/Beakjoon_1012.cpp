#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dx[4] = { 1,-1,0,0 }; //����
int dy[4] = { 0,0,1,-1 }; //����
int T = 0, M = 0, N = 0, K = 0;

//�迭�� �����ͷ� ��밡���ؼ� �Ű������� �ѱ涧 �����ؼ� ����Ҽ� �ִ�.
void dfs(int x , int y, vector<int> graph[] , int isVisited[][50])
{

	//true�� �ٲ��ְ� ���� Ž������
	isVisited[x][y] = true;


	//�����¿� �˻��Ѵ�.
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];//����
		int ny = y + dy[i];//����

		if (nx >=0 && ny >= 0 && nx < M && ny < N)
		{
			if (isVisited[nx][ny] == false && graph[nx][ny] == 1)
			{
				dfs(nx, ny, graph, isVisited);
			}
		}
	}
}

int main()
{

	//
	// ����
	// 1. �����̴� ������(�����¿�) �ٸ� ���߷� �̵��Ҽ��ְ� , ���� ���ִ°��� 1������ �������
	// 2. ���ߵ��� �� ������ ���� �ִ��� �����ϰ� �ʿ��� �������� ������ ���Ͻÿ�.
	// �Է�
	// 1. �׽�Ʈ ���̽� T�� �Է� �޴´�.
	// 2. �׽�Ʈ ���̽� ��ŭ �ݺ����� ������.
	// 3. ���߹��� ���α��� M, ���α��� N , ���߰� �ɾ��� �ִ� ���� K�� �Է¹޴´�.
	// 4. K���� ��ŭ �ݺ����� ���� �ش� ��ǥ�� 1�� �־��ش�.
	// ó��
	// 1. ������ �׷������� 2���� �迭�� boolŸ������ �湮���θ� Ȯ���� �湮���� �ʾ����� �湮���ش�.
	// 2. dfs������� �̿��� ������ for������ �湮���ش�.
	// 3. �� �湮������ cnt���� ��ȯ�Ѵ�.
	// 4. cnt���� ���ο� ���� �迭�� ����ش�.
	// ��� 
	// 1. ���� �迭�� ũ�⸦ ��ȯ���ش�.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	//�� ����
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		int cnt = 0;
		vector <int> graph[50];
		int isVisited[50][50] = { false };

		//��ü ���� 0�����ʱ�ȭ
		for (int posX = 0; posX < M; posX++)
		{
			for (int posY = 0; posY < N; posY++)
			{
				graph[posX].push_back(0);
			}
		}

		//���� ��ǥ�� 1�� ����
		for (int j = 0; j < K; j++)
		{
			int posX_t = 0;
			int posY_t = 0;

			cin >> posX_t >> posY_t;

			graph[posX_t][posY_t] = 1;
		}

		//2���� �迭�� ��ü���� �˻��Ͽ� �湮���� �������� ������
		for (int posX = 0; posX < M; posX++)
		{
			for (int posY = 0; posY < N; posY++)
			{
				if (graph[posX][posY] == 1 && isVisited[posX][posY] == false)
				{
					dfs(posX, posY , graph , isVisited);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

	}



	return 0;
}