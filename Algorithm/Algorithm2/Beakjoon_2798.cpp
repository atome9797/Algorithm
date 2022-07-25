#include <iostream>
#include <deque>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//����
	// 1. N���� ī�忡 ���ڰ� �������� M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���Ͻÿ�.
	// �Է�
	// 1. N���� ī�� ������ M���ڸ� �Է� �޴´�. (3���� ���� ���� M�� ���� �ʴ´�.)
	// 2. N���� ī�� ����ŭ ���ڸ� �Է� �޴´�.
	// 3. ����� ���� ���� M�� ���ڿ� ���� ����� ������ ���� �����͸� �����ϵ��� �Ѵ�.
	// ó�� 
	// 1. deque�� ����Ͽ� ��ȯ�Ǵ� ���ڸ� ������ �ְ� ��
	// 2. ��ȯ �Ǵ� ���ڸ� 3���� ������ 3���� �հ� M�� ������ ����� ���ڸ� �������ֱ�
	// 3. �� �ڸ� ���ڷ� �� ���������� �����ϰ� ���� �ڸ� ������ �����ϱ�
	// 4. ���������� ����� ���ڸ� ����ϱ�
	// ���
	//

	int N = 0;
	int M = 21;

	deque<int> deque1;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		deque1.push_back(num);
	}

	int updateNum = 0;

	//ī�尡 2���̸� ���߱�
	while (deque1.size() >= 3)
	{
		int num = deque1.front();
		//�� ���ϰ� ���������� ��ó�� �迭 ����
		deque1.pop_front();


		for (int i = 0; i < deque1.size(); i++)
		{
			int num2 = deque1.front();
			deque1.pop_front();

			for (deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); iter++)
			{
				if (M >= num + num2 + *iter && updateNum < num + num2 + *iter)
				{
					updateNum = num + num2 + *iter;
				}
			}

			deque1.push_back(num2);
		}
	}

	cout << updateNum << "\n";

	return 0;
}