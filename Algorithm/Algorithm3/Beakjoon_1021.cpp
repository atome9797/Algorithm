#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// ����
	// 1. ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ť��ũ�� N�� �̾Ƴ����� ���� M�� �Է� �޴´�.
	// 2. M�� ��ŭ �̾Ƴ����� ���� ��ġ�� �Է� �޴´�.
	// ó��
	// 1. 1�� ������ ������ 2,3�� ������ �̿��� �ش� ������ �������� ���� ����� ī��Ʈ �Ѵ�.
	// 2. �ش� ������ ������ ���Ҹ� �����ϰ� ���� ���Ҹ� ã���� ����.
	// ���
	//

	int N , M;
	
	cin >> N >> M;
	deque<int> dq;
	deque<int> dq2;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
		dq2.push_back(i);
	}

	int count = 0;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;

		int leftCount = 0;
		int rightCount = 0;
		//num���� ��� ��ġ�� �ִ��� ã�� count ���ֱ�
		//������ ���� �ڷ� ���� � ���� �ּڰ����� ���ϰ� �ּڰ����� ����ϱ�
		while (!dq.empty())
		{
			if (dq.front() == num)
			{
				break;
			}
			dq.push_back(dq.front());
			dq.pop_front();
			leftCount++;
		}

		while (!dq2.empty())
		{
			if (dq2.front() == num)
			{
				break;
			}
			dq2.push_front(dq2.back());
			dq2.pop_back();
			rightCount++;
		}

		if (leftCount < rightCount)
		{
			count += leftCount;
		}
		else
		{
			count += rightCount;
		}

		dq.pop_front();
		dq2.pop_front();
	}
	
	cout << count;

	return 0;
}