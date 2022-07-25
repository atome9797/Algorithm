#include <iostream>

using namespace std;

char map[51][51] = {0};
char BlackWhiteCh[2] = {'B', 'W'};

int  check(int x, int y)
{
	int min = 987654321;
	//������ black �����϶�
	
	for (int i = 0; i < 2; i++)
	{
		int count = 0;
		bool num = i;
		for (int i = x; i < 8 + x; i++)
		{
			for (int j = y; j < 8 + y; j++)
			{
				if (map[i][j] != BlackWhiteCh[num])
				{
					count++;
				}
				num = !num;
			}
			num = !num;
		}

		if (min > count)
		{
			min = count;
		}
	}


	return min;
}

int main()
{
	
	//
	// ����
	// 1. �����̴� 8*8 ũ���� ü������ ������� �Ѵ�. �����̰� �ٽ� ĥ�ؾ� �ϴ� ���簢���� �ּ�
	// ������ ���ϴ� ���α׷��� ����ÿ�.
	// �Է�
	// 1. N��M�� �Է� �޴´�.
	// 2. N�� M ũ�� ��ŭ �ݺ��ؼ� �Է� �޴´�.
	// ó��
	// 1. ü������ ũ�⿡ ���� 8*8 ü������ ����� �� ��ŭ �ݺ����� ������.
	// 1-1. ü������ ũ�Ⱑ 9*9�� �� 4���� ����Ǽ��� ������ �ִ�. 4���� ����� ���� ���� �ּڰ����� �����ؾ� �ϴ� �κ��� ã�´�.
	// 2. ü������ ����� ���� ���ϱ� ���� �Է°��� - 8 ���� ���� for���� ���� ���� �� �κп� �־��ش�.
	// 3. �׸��� �������� B �ΰ���  B�������� �����Ѵ�. �ƴѰ�� W�������� �����Ѵ�.
	// ���
	
	int N = 0;
	int M = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
		}
	}

	int caseNUmX = N - 8;
	int caseNUmY = M - 8;

	int min = 978654321;

	for (int i = 0; i <= caseNUmX; i++)
	{
		for (int j = 0; j <= caseNUmY; j++)
		{
			int count = check(i,j);
			if (min > count)
			{
				min = count;
			}
		}
	}

	cout << min << "\n";
	

	return 0;
}