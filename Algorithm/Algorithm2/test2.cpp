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

	int array[100] = { 0 };

	cin >> N >> M;

	int size = 0;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		array[i] = num;
		size++;
	}

	int updateNum = M;

	//ī�尡 2���̸� ���߱�
	while (size >= 3)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k < j; k++)
				{
					if (M >= array[i] + array[j] + array[k])
					{
						if (updateNum > array[i] + array[j] + array[k])
						{
							updateNum = array[i] + array[j] + array[k];
						}
					}
				}
			}

		}


		//�� ���ϰ� ���������� ��ó�� �迭 ����
		array[size - 1] = 0;
		size--;
	}

	cout << updateNum << "\n";

	return 0;
}