#include <iostream>
#include <stack>

using namespace std;

int main()
{
	/*
	*	문제
	*	1. 재민이는 모든 수를 받아 적은 후 그 수의 합을 알고 싶다. 
		입력
		1. 정수 K을 입력 받는다.
		2. K 만큼 반복문을 돌려 입력을 받는다.
		2-1. 입력값이 0일때 가장 최근에 쓴 수를 지운다.
		2-2. 아닐경우 그 수을 입력 받는다.
		처리
		출력
	*/
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> stack1;
	int K = 0;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int num = 0;
		cin >> num;

		if (num == 0 && stack1.empty() == false)
		{
			stack1.pop();
		}
		else
		{
			stack1.push(num);
		}
	}

	int sum = 0;
	while (stack1.empty() == false)
	{
		sum += stack1.top();
		stack1.pop();
	}
	
	cout << sum << "\n";

	return 0;

}