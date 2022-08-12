#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isChecked[100002] = { false };
vector<int> vec[100002];
int result[100002] = {0};
int countNum = 1;

void dfs(int num)
{
	if (isChecked[num] == true)
	{
		return;
	}

	isChecked[num] = true;
	result[num] = countNum;
	countNum++;

	for (int element : vec[num])
	{
		dfs(element);
	}
}

int main()
{
	//
	// 문제
	// 1. 정점 R에서 시작하여 깊이 우선 탐색으로 노드를 방문할 경우 노드 방문 순서를 출력하자.
	// 입력
	// 
	// 처리
	// 출력
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int u = 0;
		int v = 0;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(vec[i].rbegin(), vec[i].rend());
	}


	dfs(R);

	for (int i = 1; i <= N; i++)
	{
		if (result[i] != 0)
		{
			cout << result[i] << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}

	


	return 0;
}