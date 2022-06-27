#include <iostream>
#include <stack>

using namespace std;

int main()
{

	//문제
	// 1. 정수를 저장하는 스택을구현한 다음 명령을 처리하라 
	// 입력
	// 1. 명령어 수 N을 입력 받는다.
	// 2. 명령어와 정수를 입력 한다.
	// 처리
	// 1. 명령어와 입력받은 정수로 stack을 구현한다.
	// 출력
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> stack1;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int num = 0;
			cin >> num;
			stack1.push(num);
		}
		else if (str == "pop")
		{
			if (stack1.empty() == false)
			{
				cout << stack1.top() << "\n";
				stack1.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (str == "size")
		{
			cout << stack1.size() << "\n";
		}
		else if (str == "empty")
		{
			if (stack1.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (str == "top")
		{
			if (stack1.empty())
			{
				cout << -1 << "\n";
			}
			else {
				cout << stack1.top() << "\n";
			}
		}

	}

	return 0;
}