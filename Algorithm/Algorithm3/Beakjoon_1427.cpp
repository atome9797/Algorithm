#include <iostream>
#include <set>

using namespace std;

int main()
{
	//
	// ����
	// 1. ���� �� �ڸ����� ������������ ��������
	// �Է�
	// 1. N�� �Է¹޴´�.
	// ó��
	// ���
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	multiset<int> set;

	while (1)
	{
		int num = N % 10;
		set.insert(num);

		N = N / 10;

		if (N == 0)
		{
			break;
		}
	}

	int count = 1;
	int result = 0;
	for (int element : set)
	{
		result += element * count;

		count *= 10;
	}

	cout << result << "\n";

	return 0;
}