#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
char map[25][25];
int check[25][25];
//단지는 1차원배열로선언,최악의경우 n=5일때 모든칸이 1로채워질때
int danji[25 * 25 + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
int cnt;
int index;
void bfs(int y, int x);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//길이있고, 방문하지않은 노드면?
			if (map[i][j] == '1' && check[i][j] == 0)
			{
				//그 자리서부터 연산돌림
				bfs(i, j);
				//단지의 갯수, 그 단지의마을갯수를 구하기위한 선언
				danji[index++] = cnt;
				cnt = 0;
			}
		}
	}
	//단지의 마을갯수가적은순으로정렬
	sort(danji, danji + index);
	//단지갯수
	cout << index << endl;

	for (int i = 0; i < index; i++)
		cout << danji[i] << endl;
}
void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });
	//까먹지말자 check 
	check[y][x] = 1;
	//일단 bfs조건을 맞추고왔으므로 카운팅
	cnt++;
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		//까먹지말자pop
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			//범위내에있으며, 단지가있고 방문하지않은곳이면
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				if (map[ny][nx] == '1' && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = 1;
					//카운팅
					cnt++;
				}
			}
		}
	}
}