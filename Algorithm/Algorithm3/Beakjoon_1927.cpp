#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	//
	// ����
	// 1. �ּ����� ���϶�
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������, x�� �ڿ����̸� x���� ���ҷ� �߰��ϰ�, x�� 0�̸� ������������ ����Ѵ�.(����)
	// ���� ������ �Է� ���� �ʴ´�.
	// ó��
	// 1. �Է� 0�� �־��� ��ŭ ���� ����Ѵ�.
	// 2. �迭�� ���� �������� ������쿡 ������������ ����ϰ� �迭�� ��������� 0�� ����Ѵ�.
	// ���
	//

	priority_queue<int> pq;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (num == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() * (- 1) << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(num * -1);
		}
	}

	return 0;
}