#include <iostream>
#include <queue>

using namespace std;

int main()
{

	//
	// ����
	// 1. ť�� �̿��Ͽ� ���� �������� ���ԵǴ� ī�带 ���ϴ� ���α׷��� ����ÿ�.
	// �Է�
	// 1. N���� ī�� ������ �Է��Ѵ�.
	// ó��
	// 1. N���� ī�� ��ŭ �ݺ����� ���� �����͸� �����.
	// 2. while���� ���� ���� ī�尡 1���� �ɶ� ���� �ݺ��Ѵ�.
	// 2-1. �������� ī�带 ������.
	// 2-2. ���� ���� ī�带 ������ ī�尡 1�� ���̸� while���� ������.
	// 2-3. �ι�° ���� ī�带 ������ ī��� �ű��.
	// ���
	

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	queue<int> que;

	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}


	while (1)
	{
		if (que.size() == 1)
		{
			break;
		}

		que.pop();
		
		if (que.size() == 1)
		{
			break;
		}

		int num = que.front();
		que.pop();
		que.push(num);
	}

	cout << que.front() << "\n";

}