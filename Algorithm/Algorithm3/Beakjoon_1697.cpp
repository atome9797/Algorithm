#include <iostream>
#include <queue>

int dx[3] = { -1,1,2 };
int N, K;
int check[100001] = { 0 };
bool isVisited[100001] = { false };

using namespace std;

int main()
{
	//
	// ����
	// 1. �����̰� ������ ã���� �ִ� ���� ���� �ð��� ���������� ���Ͻÿ�.
	// �Է�
	// 1. N�� K ��ǥ�� �Է� �޴´�.
	// 2. 100000 �迭�� �����Ѵ�.
	// ó��
	// 3. �迭�� �ε������� �̵� ��ġ + 1�� ���ش�.
	// ���
	//
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	queue<int> que;
	que.push(N);
	isVisited[N] = true;

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		//�̵������ 3������
		for (int i = 0; i < 3; i++)
		{
			int nx = 0;

			if (dx[i] == 2)
			{
				nx = x * 2;
			}
			else
			{
				nx = x + dx[i];
			}
			
			if (nx >= 0 && nx <= 100000)
			{
				if (isVisited[nx] == false)
				{
					isVisited[nx] = true;
					check[nx] = check[x] + 1;
					que.push(nx);
				}
			}
		}
	}
	
	cout << check[K];

}