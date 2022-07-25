#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	//
	// ����
	// 1. ���ϸ��� ��ȣ�� ���� ���ϸ��� �̸��� ���ϴ� ������ �϶�
	// �Է�
	// 1. N�� M�� �Է¹޴´�.
	// ó��
	// 1. ���ڷθ� ������, ���ϸ� ��ȣ�� �ش��ϴ� ���ڸ� ����ؾ���.
	// 2. ���ĺ����� ������ ���ϸ� ��ȣ�� ���ؾ� �Ѵ�.
	// ���
	//
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> map1;
	unordered_map<int, string> map2;
	bool isNumber = false;
	for (int i = 0; i < N + M; i++)
	{
		if (i < N)
		{
			string str = "";
			cin >> str;
			map1.insert({ str, i + 1});
			map2.insert({ i, str});
		}
		else
		{
			string str = "";
			cin >> str;

			//�Է� �޴� �� �������� �������� ����������Ѵ�.
			//�����ڵ�� �����Ѵ�.
			if (str[0] >= '0' && str[0] <= '9')
			{
				isNumber = true;
			}
			else
			{
				isNumber = false;
			}

			if (isNumber)
			{
				int num = stoi(str);
				cout << map2.at(num - 1) << "\n";
			}
			else
			{
				cout << map1.at(str) << "\n";
			}

		}
	}

	return 0;
}