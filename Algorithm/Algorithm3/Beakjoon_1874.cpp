#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. 수열를 만들수 있는 stack작업 순서를 알아내자 (stack 은 무조건 오름차순으로 입력한다.)
	// 입력
	// 1. N이 주어진다.
	// 2. N만큼 반복문을 돌린다. 돌릴때 오름차순으로 stack에 데이터를 쌓는다.
	// 처리
	// 1. push 는 +, pop은 -로 연산한다.
	// 2. 수열의 첫 번째 숫자를 만날때까지 push해준다.
	// 2-1. 첫 숫자를 만났으면 pop해준다.
	// 3. 마지막으로 두 수열을 비교하여 같은지 다른지 비교하고 다르면 N를 출력한다.
	// 출력
	//

	int N = 0;
	cin >> N;

	stack<int> st;
	vector<string> vec;
	st.push(1);
	vec.push_back("+");

	int count = 1;
	int count2 = 0;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		while (!st.empty())
		{
			if (num == st.top())
			{
				vec.push_back("-");
				count2++;
				st.pop();

				if (st.empty() && count2 < N)
				{
					count++;
					st.push(count);
					vec.push_back("+");
				}

				break;
			}

			count++;
			if (count > N)
			{
				break;
			}
			st.push(count);

			vec.push_back("+");

		}
	}

	if (count2 != N)
	{
		cout << "NO";
	}
	else
	{
		for (string str : vec)
		{
			cout << str << "\n";
		}
	}

	return 0;
}