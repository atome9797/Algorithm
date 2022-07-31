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
	// ����
	// 1. ������ ����� �ִ� stack�۾� ������ �˾Ƴ��� (stack �� ������ ������������ �Է��Ѵ�.)
	// �Է�
	// 1. N�� �־�����.
	// 2. N��ŭ �ݺ����� ������. ������ ������������ stack�� �����͸� �״´�.
	// ó��
	// 1. push �� +, pop�� -�� �����Ѵ�.
	// 2. ������ ù ��° ���ڸ� ���������� push���ش�.
	// 2-1. ù ���ڸ� �������� pop���ش�.
	// 3. ���������� �� ������ ���Ͽ� ������ �ٸ��� ���ϰ� �ٸ��� N�� ����Ѵ�.
	// ���
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