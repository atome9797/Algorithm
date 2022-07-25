#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int x[200000];

int main()
{

	//
	// ����
	// 1. C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� 
	//		�ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ���� ���� N�� ������ ���� C�� �Է� �޴´�. (������ ���)
	// ó��
	// 2. ������ ������ŭ 
	// ���
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1.���� ������ �������� ������ �Է� �޴´�.
	cin >> N >> C;

	//2. ���� ��ǥ�� �Է� �޴´�.
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}

	//3. ������ ������ �Ÿ��� ���ϱ� ���� ���� ��ǥ�� �����Ѵ�.
	sort(x, x + N);
	
	//4.���� �˻��� �� ������ ���� ������ ������ ������ �Ÿ�
	// [1, x[N - 1]] (�ּ� �Ÿ� 1, �ִ� �Ÿ� x[N - 1])
	int s = 1; // 0 ~ 1 , 1 ~ 2
	int e = x[N - 1] + 1; // 0 ~ 9
	int result = 0;

	while (s < e)
	{
		// 4-1. �߾Ӱ��� ���� �ĺ��� ���Ѵ�.
		//s : 1, e : 10, m : 5
		int m = (s + e) / 2; //������ �Ÿ�


		//4-2. ������ m�Ÿ� ��ŭ ����߷� ��� �����⸦ ��ġ�Ҽ� �ִ��� Ȯ���Ѵ�.
		int count = 1;
		/*int distance = x[0] + m;
		
		for (int i = 0; i < N; i++)
		{
			if (distance <= x[i])
			{
				distance = x[i] + m;
				count++;
			}
		}*/

		int p = 0;
		for (int i = 0; i < N; i++)
		{
			if (x[i] - x[p] >= m)
			{
				++count;
				p = i;
			}
		}


		if (count >= C)
		{
			//4-3. �ִ� ���� �ֽ�ȭ
			if (result < m)
			{
				result = m;
			}

			//4-4. �� ã���� �ִ��� ���� ����
			s = m + 1;
		}
		else
		{
			e = m;
		}
	}


	//4. �ִ� �Ÿ��� ����Ѵ�.
	cout << result;

}