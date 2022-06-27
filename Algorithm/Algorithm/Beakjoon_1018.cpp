#include <iostream>

using namespace std;

int main()
{

	//
	// ����
	// 1. ü���ǿ� �ٽ� ĥ�ؾ� �ϴ� �κ��� ���ڸ� ����϶�
	// �Է�
	// 1. N�� M �� �Է� �޾ƶ�. N�� M�� 8���� ũ�� 50���� �۴�.
	// 2. N���� �ٸ�ŭ �ݺ����� ������.
	// 3. M���� ���ڸ� �Է��Ѵ�.
	// ó��
	// 4. M���� ���ڰ� W�� �����ϰ� ���ľ� �� �κ��� ������ ī��Ʈ���ش�.
	// 5. �������� B�� �����ϰ� ���ľ� �� �κ��� ������ ī��Ʈ ���ش�.
	// 6. ù��° ���� ù��° ���ڰ� W�� whiteBlack�� true, �ƴϸ� false
	// 6-1. whiteBlack�̸� Ȧ���� B ¦���� W 
	// 7. �������� whiteBlack�� not���� ����
	// 8. 
	// ���
	//

	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	cin >> N >> M;

	bool whiteBlack = false;

	int count[50][50] = {0};

	//N = 9�� 2�� ������
	for (int k = 0; k <= N - 8; k++)
	{
		for (int m = 0; m <= M - 8; m++)
		{
			for (int i = k; i < k + 8; i++)
			{
				char chess[51] = { 0 };

				for (int j = m; j < m + 8; j++)
				{
					cin >> chess[j];

					if (chess[k * M] == 'W' && i == 0)
					{
						whiteBlack = true; //white�϶� true
					}

					if (whiteBlack == true)
					{
						//¦�� �̰� j�� w�̸� �հ� //Ȧ�� �̰� j�� B�̸� �հ�
						if (!((j % 2 == 0 && chess[j] == 'W') || (j % 2 == 1 && chess[j] == 'B')))
						{
							count[k][m]++;
						}
					}
					else
					{
						//¦�� �̰� j�� w�̸� �հ� //Ȧ�� �̰� j�� B�̸� �հ�
						if (!((j % 2 == 1 && chess[j] == 'W') || (j % 2 == 0 && chess[j] == 'B')))
						{
							count[k][m]++;
						}
					}

				}

				whiteBlack = !whiteBlack;
			}
		}
	}

	int result = N * M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (count[i][j] < result)
			{
				result = count[i][j];
			}
		}
	}

	
	cout << result;

	return 0;
}