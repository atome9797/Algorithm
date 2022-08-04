#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//
	// ����
	// 1. �迭 B[k]�� ���غ���
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. K�� �Է� �޴´�. (K�� min(10�� 9��, N�� 2��) ���� �۰ų� ���� �ڿ����̴�.)
	// ó��
	// 1. N*N�� ������ �迭�� �����.
	// 2. ������ �迭���� �̺�Ž������ k ��
	// ���
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int s = 1;
	int e = K;
	int m;
	int result = 0;


	while (s <= e)
	{
		m = (s + e) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(N , m / i); 
			//�� �࿡��(�� ���� ���ڸ� ���ؾ� ������ ������ i���ش�.)  
			//�������� ���ؼ� �� ���� ������ ������ �˼��ִ�.
		}

		if (cnt < K)
		{
			s = m + 1;
		}
		else
		{
			result = m;
			e = m - 1;
		}
	}

	cout << result << "\n";
	

	return 0;
}