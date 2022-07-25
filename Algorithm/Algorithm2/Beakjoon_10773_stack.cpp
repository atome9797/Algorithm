#include <iostream>
#include <stack>

using namespace std;

int main()
{
	/*
	*	����
	*	1. ����̴� ��� ���� �޾� ���� �� �� ���� ���� �˰� �ʹ�. 
		�Է�
		1. ���� K�� �Է� �޴´�.
		2. K ��ŭ �ݺ����� ���� �Է��� �޴´�.
		2-1. �Է°��� 0�϶� ���� �ֱٿ� �� ���� �����.
		2-2. �ƴҰ�� �� ���� �Է� �޴´�.
		ó��
		���
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