#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// ����
	// 1. N���� �����Կ� Ű�� ��� �Է��� �о �� ��ġ ����� ����Ͽ� ����Ѵ�.
	// �Է�
	// 1. ��ü �Է� Ƚ�� N�� �Է��Ѵ�.
	// 2. N�� �ݺ����� ������.
	// 3. �ΰ��� �迭�� �Է� �޴´�.
	// 4. �迭 �Ѱ��� �� �Է� �޾� ī��Ʈ �Ѵ�.
	// 4-1. ī��Ʈ�� �� ū ���� ���ö� �Ѵ�.
	// ó��
	// 1. ī��Ʈ�� �� ������� ū ���ϼ��� 1�� �ǰ� ����
	// ���
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	
	int array1[50] = { 0 };
	int array2[50] = { 0 };
	int sort[50] = { 0 };

	for (int i = 0; i < N; i++)
	{
		int kgram = 0;
		int height = 0;

		cin >> kgram >> height;

		array1[i] = kgram;
		array2[i] = height;
		sort[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (array1[i] < array1[j] && array2[i] < array2[j])
			{
				sort[i] += 1;
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		cout << sort[i] << " ";
	}

	return 0;
}