#include <iostream>
#include <limits.h>

using namespace std;

using ll = long long; //�����÷ο츦 �����ϱ����� longlongŸ���� ���

ll K, N, M = 0;
ll lan[10000];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	// ����
	// 1. ����� �ִ� �ִ� ������ ���̸� ���Ͻÿ�.
	// �Է�
	// 1. K�� N�� �Է� �޴´�.
	cin >> K >> N;
	// 2. ������ �ִ� ������ ���̸� �Է� �޴´�.
	for (ll i = 0; i < K; i++)
	{
		cin >> lan[i];

		if (M < lan[i])
		{
			M = lan[i]; //�ִ����� ����
		}
	}

	// 3. ���� �˻�
	// ���� : �ڸ��� �ִ� ������ ����
	//[1,M + 1) ���� ū ����
	ll s = 1, e = M + 1;

	ll result = 0; //������ ���� ��
	while (s < e) //�ּڰ����� �����ϸ� ������ ����� �ȴ�.
	{
		ll m = (s + e) / 2; //��ǥ������ Ž���Ѵ�.

		ll count = 0;

		for (ll i = 0; i < K; i++)
		{
			count += lan[i] / m;
		}

		//��
		//[115 ~ 229]
		if (count >= N)
		{
			if (result < m)
			{
				result = m;//�ش� m���� �����ص�
			}

			s = m + 1;
		}
		else
		{
			e = m;
		}
	}

	// ó��

	// ���
	cout << result;
	//
}