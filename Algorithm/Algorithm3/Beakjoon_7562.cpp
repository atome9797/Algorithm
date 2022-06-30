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
	// 문제
	// 1. 나이트가 최소 몇번으로원하는 좌표로 이동할수 있는지 구하시오.
	// 입력
	// 1. 테스트 케이스를 입력 받는다.
	// 2. 테스트 케이스 만큼 반복문을 돌린다.
	// 3. 체스판의 한 변의 길이를 입력받는다.
	// 4. 나이트가 현재 있는 칸을 입력 받는다.
	// 5. 나이트가 이동하려는 칸을 입력 받는다.
	// 6. 체스판 check 2차원 배열을 생성한다.
	// 7. 지나갔는지 여부를 확인할 isVisited 2차원 배열을 생성한다.
	// 8. 체스 말이 이동하는 8개의 패턴을 지정한다.
	// 처리
	// 1. 체스말이 이동할수 있는 최단거리를 입력한다.
	// 출력
	// 1. 각 테스트 케이스마다 최단 거리를 출력해준다.
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