#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

	//����
	// 1. �������� ���ڿ����� �ƴ��� �Ǵ��ϱ�
	// �Է�
	// 1. �������� ���ڿ����ް� �Ұ�ȣ�� ���ȣ�� �̷���� �ִ�.
	// 1-1. �� ���� ��ħǥ�� ������.
	// 1-2. �ƹ��͵� �Է����� �ʰ� ��ħǥ�� �Է��ϸ� ���ڿ��� ������.
	// ó��
	// 1. �� �ٸ��� �������� ������ true, ������ false�� ����Ѵ�.
	// 1-1. stack�� ���ڿ��� ����ش�.
	// ���

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1)
	{
		stack<char> stack1;
		
		/*char ss[101] = {0};
		cin.getline(ss , 100);*/

		string str;
		getline(cin, str);
		
		if (str[0] == '.')
		{
			break;
		}

		for (int i = 0; i < str.size(); i++)
		{

			//() [] . �� ���ÿ� ������
			char front = '0';
			char back = '0';

			if (stack1.empty() == false)
			{
				front = stack1.top();
			}

			if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
			{
				stack1.push(str[i]);
			}

			if (stack1.empty() == false)
			{
				back = stack1.top();
			}

			if ((back == ')' && front == '(') || (back == ']' && front == '['))
			{
				stack1.pop();
				stack1.pop();
			}

		}

		if (stack1.empty())
		{
			std::cout << "yes" << "\n";
		}
		else
		{
			std::cout << "no" << "\n";
		}

	}
	
}