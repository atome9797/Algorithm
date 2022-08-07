#include <iostream>
#include <queue>

using namespace std;

int main()
{
	//
	// ����
	// 1. ���� ���� �ڷᱸ�� 
	// �Է�
	// 1. ������ ���� N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������.
	// 2-1. 0�� �ƴ϶�� �迭�� �� �߰�
	// 2-2. 0�̶�� ������ ���� ���� ���� ����ϰ� �迭���� ����
	// 2-2-1. ���밪�� ���� �������� �������� ���� �������� ����Ѵ�.
	// ó��
	// ���
	// 1. 0�Է� Ƚ����ŭ ���� ����Ѵ�. (���� ������)
	// 1-1. ����ִµ� ���밪�� ���� ���� ���� ����Ϸ��� �ϴ� ��� 0�� ����Ѵ�.

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	//0�� ���̳ʽ���
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		//�Է��� ���
		if (num != 0)
		{
			//���̳ʽ��� ���
			if (num < 0)
			{
				pq.push({ num, 1 });
			}
			else 
			{
				num *= -1;
				pq.push({ num, 0 });
			}
		}

		//����� ��� 
		else if (num == 0 && !pq.empty())
		{
			if (pq.top().second == 0)
			{
				cout << pq.top().first * (-1) << "\n";
			}
			else
			{
				cout << pq.top().first << "\n";
			}
			pq.pop();
		}
		else
		{
			cout << 0 << "\n";
		}
	}


	return 0;
}