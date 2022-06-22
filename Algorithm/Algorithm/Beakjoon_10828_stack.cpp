#include <iostream>
#include <stack>

using namespace std;

int main()
{

	//����
	// 1. ������ �����ϴ� ������������ ���� ����� ó���϶� 
	// �Է�
	// 1. ��ɾ� �� N�� �Է� �޴´�.
	// 2. ��ɾ�� ������ �Է� �Ѵ�.
	// ó��
	// 1. ��ɾ�� �Է¹��� ������ stack�� �����Ѵ�.
	// ���
	
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