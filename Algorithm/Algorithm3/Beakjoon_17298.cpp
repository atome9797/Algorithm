#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> vec(1000001);
stack <int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. 집합 A의 원소의 index에 해당하는 값보다 큰수가 오른쪽에 있을때 가장 왼쪽에 있는수를 구하라
	// 2. 없을 경우 -1로 처리한다.
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 vector에 입력한다.
	// 처리
	// 1. 매반복문 돌때마다 stack에 번호를 쌓아두고 다음 반복문의 번호와 비교해서 작으면 stack에서 삭제한다. 
	// 2. 큰수가 있으면 큰수로 출력 배열에 담아두고 , 없으면 -1을 담아둔다.
	// 출력
	// =
 	

	int N = 0;
	cin >> N;
	vector<int> result(N);
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= vec[i])
		{
			st.pop();
		}

		if (st.empty())
		{
			result[i] = -1;
		}
		else 
		{
			//큰수가 있다는 뜻이므로 넣어준다.
			result[i] = st.top();
		}

		st.push(vec[i]);
	}

	for (int element : result)
	{
		cout << element << " ";
	}

	return 0;
}