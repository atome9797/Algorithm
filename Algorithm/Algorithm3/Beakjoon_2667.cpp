#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[25];
vector<int> danjiVec;

//������ �迭�� �޾ƾ� �Ѵ�.
bool isVisited[25][25] = {false};
int cnt = 0; //ī��Ʈ�� ������

int dx[4] = {1,-1,0,0}; // x
int dy[4] = {0,0,-1,1}; // y
int N = 0;
void bfs(int y, int x)
{
	queue<pair<int, int>> que;

	que.push({ y,x });
	isVisited[y][x] = true;
	cnt++;

	while (!que.empty())
	{

		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && nx < N && ny < N && graph[ny][nx] == 1 && isVisited[ny][nx] == false)
			{
				isVisited[ny][nx] = true;
				cnt++;
				que.push({ ny,nx });
			}
		}
	}

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
	// 1. �ݺ����� ���� ������ �迭�� ���� 1�̰� ������ �迭 bool Ÿ���� false�϶� bfs�Լ��� �����Ų��.
	// 2. bfs���� �ش� ��ǥ���� queue�� ������ true�� �ٲ��ְ� count+1�� �� while���� ������.
	// 2-1. while�������� ��ǥ���� �����ְ� for���� ������.for���� ������ 4�� ����  �����¿�� ���������� 1�� ���� ������ true�� �ٲ��ְ� push���ش�. ���� count+1���ش�.
	// 3. ī��Ʈ���� �� �������� �Լ��� ������ �������� �÷��ְ� ī��Ʈ�� �ʱ�ȭ ��Ų��.
	// 4. ���� �������� �迭�� �� ã�Ƽ� �����ϴ� ������� ����Ѵ�.
	// ���
	// 1. ���������� � ī��Ʈ ����� ����Ѵ�.
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

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

	int danji = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1 && isVisited[i][j] == false)
			{
				bfs(i,j);
				danjiVec.push_back(cnt);
				cnt = 0;
			}
		}
	}

	cout << danjiVec.size() << "\n";

	sort(danjiVec.begin(), danjiVec.end());

	for (int element : danjiVec)
	{
		cout << element << "\n";
	}



	return 0;
}