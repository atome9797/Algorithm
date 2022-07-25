#include <iostream>

using namespace std;

int main()
{

	//����
	//	1. �ִ񰪰� �ּڰ��� �����ϰ� ���� ���� �Ҽ��� ���� �հ� �ּ� �Ҽ����� ����Ѵ�.
	// �Է�
	// 1. �ִ� n�� �ּڰ� m�� �Է� �޴´�. 
	// ó��
	// 1. �Ҽ��� ���Ѵ�.
	// 2. �Ҽ� �ּڰ��� ���Ѵ�.
	// 3. �Ҽ��� ������ -1 �� ó�� �Ѵ�.
	// ���

	bool sosu[10005] = { false };

	//�Ҽ� �迭 ����� => �Ҽ� �϶� true �� ���� �Ѵ�.
	// 1-1. �Ҽ� �� ��Ģ�� �����Ѵ�.
	// 1-2. �Ҽ��� 1�� �ڱ� �ڽ� �̿ܿ� ����� ������ �ʴ� ���� �̾߱� �Ѵ�.
	for (int sosuNum = 2; sosuNum <= 10000; sosuNum++)
	{
		bool exist = true;
		for (int j = 2; j <= 10000; j++)
		{
			//�Ҽ��� �ƴҶ� false
			if (sosuNum != j && sosuNum % j == 0)
			{
				exist = false;
			}
		}

		if (sosuNum == 2) {
			exist = true;
		}
		sosu[sosuNum] = exist;
	}

	//�Է�
	int min = 0;
	int max = 0;

	cin >> min >> max;

	//ū���� �����Ѵ�.
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}

	int min_sosu = 0;
	int sosu_sum = 0;
	int sosucount = 0;
	for (int i = max; i >= min; i--)
	{
		if (sosu[i])
		{
			min_sosu = i;
			sosu_sum += i;
			sosucount++;
		}
	}
	if (min_sosu == 0)
	{
		cout << -1 << "\n";
	}
	else {
		cout << sosu_sum << "\n";
		cout << min_sosu << "\n";
	}


	return 0;
}