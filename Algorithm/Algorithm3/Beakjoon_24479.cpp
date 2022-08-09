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
	if (visited[r] == 1) { // 방문 한 곳이면 return
		return;
	}

	visited[r] = 1; // 방문하지 않았다면 방문했다고 표시
	cnt++;
	result[r] = cnt;

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]);
	}
}

int main()
{

	//
	// 문제
	// 1. 깊이 우선 탐색으로 노드를 방문할 경우 노드의 방문 순서를 출력하자.
	// 입력
	// 1. 정점의 수N, 간선의 수 M , 시작 정점 R을 입력 받는다.
	// 2. 간선의 수만큼 반복문을 돌리며, 간선이 생기는 배열을 만든다.
	// 처리
	// 1. (2차원 배열임)벡터 배열 생성후 간선으로 생성하기 위해 배열의 인덱스와 값을 설정한다.
	// 2. 정렬
	// 3. stack에 첫 정점을 입력 한다. 1
	// 4. stack이 빌때 까지 while문을 돌린다. 
	// 5. stack의 최상위 값을 불러오고 제거
	// 6. 해당노드가 방문안했으면 true로 만들고 출력
	// 7. 해당 노드를 기준으로 벡터 배열에서 다음위치를 찾는다.
	// 7-1. 이미 방문한 곳이 아닌 방문안한곳이면 스택에 넣는다. (아니면 재귀도 가능)
	// 출력
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