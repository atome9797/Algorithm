#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int result[100001];
int cnt = 0;

//void dfs(int index)
//{
//	if (isVisited[index] == true)
//	{
//		return;
//	}
//
//	isVisited[index] = true;
//	countNum++;
//	result[index] = countNum;
//	
//	for (int element : graph[index])
//	{
//		dfs(element);
//	}
//
//}

void dfs(int r) {
	if (visited[r] == 1) { // �湮 �� ���̸� return
		return;
	}

	visited[r] = 1; // �湮���� �ʾҴٸ� �湮�ߴٰ� ǥ��
	cnt++;
	result[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]);
	}
}

int main()
{

	//
	// ����
	// 1. ���� �켱 Ž������ ��带 �湮�� ��� ����� �湮 ������ �������.
	// �Է�
	// 1. ������ ��N, ������ �� M , ���� ���� R�� �Է� �޴´�.
	// 2. ������ ����ŭ �ݺ����� ������, ������ ����� �迭�� �����.
	// ó��
	// 1. (2���� �迭��)���� �迭 ������ �������� �����ϱ� ���� �迭�� �ε����� ���� �����Ѵ�.
	// 2. ����
	// 3. stack�� ù ������ �Է� �Ѵ�. 1
	// 4. stack�� ���� ���� while���� ������. 
	// 5. stack�� �ֻ��� ���� �ҷ����� ����
	// 6. �ش��尡 �湮�������� true�� ����� ���
	// 7. �ش� ��带 �������� ���� �迭���� ������ġ�� ã�´�.
	// 7-1. �̹� �湮�� ���� �ƴ� �湮���Ѱ��̸� ���ÿ� �ִ´�. (�ƴϸ� ��͵� ����)
	// ���
	//

	/*ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	


	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
	{
		int U;
		int V;
		cin >> U >> V;
		graph[U].push_back(V);
		graph[V].push_back(U);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}*/

	int n, m, r;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> r;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // (1,4) (1,2) (2,3) (2,4) (3,4)
		graph[b].push_back(a); // (4,1) (2,1) (3,2) (4,2) (4,3)	
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}