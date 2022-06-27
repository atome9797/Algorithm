#include <iostream>

using namespace std;

int lan[1000000];

int main()
{
	//
	// ����
	// 1. ��� M ������ ������ ���� �������� ���ؼ� ���ܱ⿡ �����Ҽ� �ִ� ������ �ִ��� ���Ͻÿ�.
	// �Է�
	// 1. ������ �� N�� ������� ���ϴ� �������� M �� �Է� �޴´�.
	// ó��
	// ���
	// 1. ��� M���� ������ ���� �������� ���ؼ� ���ܱ� ���� �ִ��� ����Ͻÿ�.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0, Max = 0;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> lan[i];
		if (Max < lan[i])
		{
			Max = lan[i]; //�ִ��� ���Ѵ�.
		}
	}

	int s = 1;
	int e = Max + 1;
	int result = 0;
	while (s < e)
	{

		int m = (s + e) / 2;

		int count = 0;

		//�����ؼ� ������ �ִ� ���̸� ���Ѵ�.
		for (int i = 0; i < N; i++)
		{
			if (lan[i] >= m)
			{
				count += lan[i] - m;
			}
		}

		if (count >= M)
		{
			if (result < m)
			{
				result = m;//�ش� m���� �����ص�
			}

			s = m + 1; //�ø��� �۾�
		}
		else
		{
			e = m; //���̴� �۾�
		}
	}

	cout << result;


}