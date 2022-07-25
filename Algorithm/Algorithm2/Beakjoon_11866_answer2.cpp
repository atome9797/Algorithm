#include <iostream>
#include <queue>

using namespace std;

int main()
{

	//
	// ����
	// 1. N ���� ����� ���� K��° ����� �����ϴ� ��Ģ�� ������
	// �Է�
	// 1. N��� K��°�� �Է¹޴´�.
	// ó��
	// 1. while���� ���� ť�� ����� 1�� �ɶ� ���� �ݺ��Ѵ�.
	// 2. ť���� 3��° ���� ������ �������� push �ǰ��ϴ� ť�� �ϳ� �� �����.
	// 2-1. �������� ť���� count ��ŭ�� ���� ���������κ��� ���Ҹ� ������ ���Ҹ� ť�� �����Ѵ�.
	// 3. 3��° ���� ����Ѵ�
	// 4. ����� 1�� �ɶ� ���� �ݺ��Ѵ�.
	// ���

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int K = 0;
	cin >> N >> K;

	queue<int> que;
	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}

	int count = K;
	int maxSize = que.size();

	cout << "<";

	while (1)
	{
		if (que.size() == 1)
		{
			cout << que.front() << ">";
			break;
		}

		queue<int> que2;
		queue<int> que3;
		que3 = que;



		for (int i = 1; i <= que.size(); i++)
		{
			int num = que3.front();
			que3.pop();

			//int t = count % que.size();

			if (count == 0)
			{
				count = que.size();
			}


			if (i != count)
			{
				que2.push(num);
			}
			else
			{
				cout << num << ", ";
			}
		}

		//		//���� ��ġ + ī��Ʈ
		//count = count + K - 1;
		//
		//if (count == K)
		//{
		//	count = K;
		//}

		//if (count > maxSize)
		//{
		//	count = count - maxSize;
		//}

		count = (count + K - 1) % que2.size();


		//que�� �籸�����ش�.
		swap(que, que2);

	}


	return 0;
}