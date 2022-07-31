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
	// 1. ������ �߿䵵�� ������ �ش� ������ ��¼����� ���Ͻÿ�. (�������� ����ϴ� ���)
	// �Է�
	// 1. �׽�Ʈ ���̽��� test_case �� �Է� �޴´�.
	// 2. ������ ���� N�� queue �� ����� M��° ��Ұ� ��µǴ� ��ȣ�� ����ϰ� �Ѵ�.
	// ó��
	// 1. ��ü�� �˻��ѵ� �� �պ��� �߿䵵�� ū�� ������ �ǵڷ� �̵��ϰ��Ѵ�.
	// ���
	//

	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		int N, QueueIndex;
		cin >> N >> QueueIndex;
		
		priority_queue<int> pq;
		queue<pair<int, bool>> que;


		for (int i = 0; i < N; i++)
		{
			int document = 0;
			bool result = false;
			cin >> document;

			if (QueueIndex == i)
			{
				result = true;
			}
			else
			{
				result = false;
			}

			que.push({ document, result });
			pq.push(document);
		}
		int count = 1;
		
		while (!pq.empty())
		{
			while (pq.top() > que.front().first)
			{
				que.push({ que.front().first , que.front().second });
				que.pop();
			}
			pq.pop();

			if (que.front().second == true)
			{
				cout << count << "\n";
				break;
			}
			que.pop();
			count++;
		}

		

	}

	return 0;
}