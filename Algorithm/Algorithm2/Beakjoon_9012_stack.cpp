#include <iostream>
#include <stack>

using namespace std;

int main()
{
	
	// ����
	// 1. ��ȣ ���ڿ��� ( ,  ) ������ ������ ���ڿ��̴�. �ѽ��� ( ) ���ڿ��� �⺻ vps�� �θ�
	// 2. ���� x�� vps��� (x)�� vps��. ���� �̷��� ������ vps�� �ƴ� ���ڿ��̴�.
	// 3. vps���� �ƴ��� �Ǵ��ؼ� �װ���� yes, no �� ��Ÿ����� �Ѵ�.
	// �Է�
	// 1. �׽�Ʈ ���̽� T�� �Է� �޴´�.
	// 2. �׽�Ʈ ���̽� ��ŭ �ݺ����� ���� �ش�.
	// 3. �Է� input�� ��ȣ ���ڿ��� �־�����.
	// ó��
	// 1. �ùٸ� ��ȣ ���ڿ��̸� yes, �ƴϸ� no�� ��� �Ѵ�.
	// 1-1. ���ڿ��� �Է� �ް� �Է� ���� ���ڿ����� ) ��ȣ�� �������� ���� top�� ( �� ���� ��������
	// ���

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case = 0;
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++)
	{
		string str;
		cin >> str;
		stack<char> stack1;

		for (char ch : str)
		{
			char front = '0';
			char back = '0';
			if (stack1.empty() == false)
			{
				front = stack1.top();
			}
			
			stack1.push(ch);
			
			if (stack1.empty() == false)
			{
				back = stack1.top();
			}

			if (back == ')' && front == '(')
			{
				stack1.pop();
				stack1.pop();
			}
		}

		if (stack1.empty())
		{
			std::cout << "YES" << "\n";
		}else 
		{
			std::cout << "NO" << "\n";
		}
	}


	return 0;
}