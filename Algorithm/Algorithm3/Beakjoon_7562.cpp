#include <iostream>
#include <queue>

using namespace std;
int current_position_x = 0;
int current_position_y = 0;
int move_position_x = 0;
int move_position_y = 0;
int cheseSize = 0;
int movePoint[8][2] = { {-2 , 1}, {-1, 2}, {1 , 2}, { 2, 1}, {2, -1}, {1, -2},{-1, -2}, {- 2, -1} };

int main()
{
	//
	// ����
	// 1. ����Ʈ�� �ּ� ������ο��ϴ� ��ǥ�� �̵��Ҽ� �ִ��� ���Ͻÿ�.
	// �Է�
	// 1. �׽�Ʈ ���̽��� �Է� �޴´�.
	// 2. �׽�Ʈ ���̽� ��ŭ �ݺ����� ������.
	// 3. ü������ �� ���� ���̸� �Է¹޴´�.
	// 4. ����Ʈ�� ���� �ִ� ĭ�� �Է� �޴´�.
	// 5. ����Ʈ�� �̵��Ϸ��� ĭ�� �Է� �޴´�.
	// 6. ü���� check 2���� �迭�� �����Ѵ�.
	// 7. ���������� ���θ� Ȯ���� isVisited 2���� �迭�� �����Ѵ�.
	// 8. ü�� ���� �̵��ϴ� 8���� ������ �����Ѵ�.
	// ó��
	// 1. ü������ �̵��Ҽ� �ִ� �ִܰŸ��� �Է��Ѵ�.
	// ���
	// 1. �� �׽�Ʈ ���̽����� �ִ� �Ÿ��� ������ش�.
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		int check[301][301] = { 0 };
		bool isVisited[301][301] = { false };
		cin >> cheseSize;
		cin >> current_position_x;
		cin >> current_position_y;
		cin >> move_position_x;
		cin >> move_position_y;

		queue<pair<int,int>>que;
		que.push({ current_position_x , current_position_y });
		isVisited[current_position_x][current_position_y] = true;

		while (!que.empty())
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int i = 0; i < 8; i++)
			{
				int dx = x + movePoint[i][0];
				int dy = y + movePoint[i][1];

				if (dx >= 0 && dy >= 0 && dx < cheseSize && dy < cheseSize)
				{
					if (isVisited[dx][dy] == false)
					{
						isVisited[dx][dy] = true;
						check[dx][dy] = check[x][y] + 1;
						que.push({ dx,dy });
					}
				}

			}
		}

		cout << check[move_position_x][move_position_y] << "\n";
	}
	


	return 0;
}