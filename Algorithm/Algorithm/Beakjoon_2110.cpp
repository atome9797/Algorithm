#include <iostream>

using namespace std;

using ll = long long;

ll N, C, M = 0;
ll lan[200000];

int main()
{

	//
	// ����
	// 1. C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� 
	//		�ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ���� ���� N�� ������ ���� C�� �Է� �޴´�. (������ ���)
	// ó��
	// ���
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> lan[i];
		if (M < lan[i])
		{
			M = lan[i];
		}
	}

	
	ll s = 1, e = M + 1;

	while (s < e)
	{
		int m = (s + e) / 2;

		int count = 0;

		for (int i = 0; i < N; i++)
		{
			count += lan[i] / m;
		}
	}



}