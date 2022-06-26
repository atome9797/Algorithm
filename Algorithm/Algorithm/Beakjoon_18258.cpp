#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// ����
	// 1. ť�� �̿��Ͽ� �Է��� ó���ϴ� ���α׷��� ����ÿ�.
	// �Է�
	// 1. ��ɾ��� ���� �Է��Ѵ�.
	// 2. ��ɾ  �Է��Ѵ�.
	// ó��
	// 1. ��ɾ �°� ť�� �ۼ��Ѵ�.
	// ���

	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> que;

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		if (str == "push")
		{
			int num = 0;
			cin >> num;

			que.push(num);
		}
		else if (str == "pop")
		{
			if (que.empty() == false)
			{
				cout << que.front() << "\n";
				que.pop();
			}
			else 
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "size")
		{
			cout << que.size() << "\n";
		}
		else if (str == "empty")
		{
			if (que.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (str == "front")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << que.front() << "\n";
			}
		}
		else if (str == "back")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << que.back() << "\n";
			}
		}

	}


	return 0;
}