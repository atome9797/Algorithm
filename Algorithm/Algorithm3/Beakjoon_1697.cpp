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
	// 문제
	// 1. 수빈이가 동생을 찾을수 있는 가장 빠른 시간이 몇초후인지 구하시오.
	// 입력
	// 1. N과 K 좌표를 입력 받는다.
	// 2. 100000 배열을 생성한다.
	// 처리
	// 3. 배열의 인덱스값에 이동 위치 + 1을 해준다.
	// 출력
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

		//이동방법은 3가지임
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