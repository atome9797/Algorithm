#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, R;
vector<int> vec[100001];
bool isChecked[100001] = { false };
int CountNum = 1;
int result[100001];

void bfs(int num)
{

	queue<int> que;
	que.push(num);
	isChecked[num] = true;
	result[num] = CountNum;
	CountNum++;


	while (!que.empty())
	{
		int index = que.front();
		que.pop();
		

		for (int element : vec[index])
		{
			if (isChecked[element] == false)
			{
				result[element] = CountNum;
				CountNum++;
				isChecked[element] = true;
				que.push(element);

			}
		}
	}


}

int main()
{

	//
	// ����
	// 1. �ʺ� �켱 Ž������ ������������ �湮�ϰ� �ϱ�
	// �Է�
	// 1. N M R �� �Է� �޴´�.
	// ó��
	// ���
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	bfs(R);


	for (int i = 1; i <= N; i++)
	{
			cout << result[i] << "\n";
	}

	return 0;
}