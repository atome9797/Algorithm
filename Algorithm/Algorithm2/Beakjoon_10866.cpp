#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// ����
	// 1. ������ ���� ������ ���� ���ó���ϱ�
	// �Է�
	// 1. ��ɾ� �� N �� �Է��Ѵ�.
	// 2. ��ɾ� ����ŭ �ݺ����� ������.
	// 3. �ݺ��� Ƚ����ŭ �Է� input �� �޴´�.
	// ó��
	// ���

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	deque<int> dq;

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{

		string str = "";
		cin >> str;

		if (str == "push_front")
		{
			int num = 0;
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back")
		{
			int num = 0;
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				int num = dq.front();
				dq.pop_front();

				cout << num << "\n";
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				int num = dq.back();
				dq.pop_back();

				cout << num << "\n";
			}
		}
		else if (str == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (str == "empty")
		{
			if (dq.empty())
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
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
			}
		}
		else if (str == "back")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
			}
		}

	}


	return 0;
}