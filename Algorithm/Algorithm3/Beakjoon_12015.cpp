#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	//
	// ����
	// 1. ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ������ ���� N�� �Է� �޴´�.
	// 2. ������ ������ŭ �ݺ����� ������.
	// ó��
	// 1. ���� ���� �κ� ������ ��� ���߿� �ݺ� �Ǵ��� ���� �� ������ �̷�� �� ������ ũ�Ⱑ ���� ���� �κ� ������ �ȴ�. ��) 10 , 1 ,2 , 3, 4, 50 �̸� 10�� ������ �������� ���� ���� �κ� ������ �ȴ�.
	// 2. ���� �̺� Ž������ �������� �������� ��������� 0���� ������ �˻��ؼ� ������ ���ϰ�, 25���� ������ �˻��ؼ� ������ ���� ���ϰ� ū ������ ������ ���δ�.
	// 3. ������ �������� �˻����ش�.
	// 4. 25�� �˻������� �� ������ 25���� 50������ ������ ������, �� ������ 1 ���� 25������ ���δ�.
	// ���
	// 1. �迭�� ũ�⸦ �����Ѵ�.


	int N = 0;
	int Max = 0;
	cin >> N;
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (Max < num)
		{
			Max = num;
		}
		vec.push_back(num);
	}

	int s = 0;
	int total = vec.size();
	int e = vec.size();

	int result = 0;

	while (s <= e)
	{
		int m = (s + e) / 2;

		int count1 = 0;
		int count2 = 0;
		int testMax1 = 0;
		int testMax2 = 0;
		for (int i = m; i < total; i++)
		{
			if (testMax1 < vec[i])
			{
				testMax1 = vec[i];
				count1 += 1;
			}
		}

		for (int j = s; j < total; j++)
		{
			if (testMax2 < vec[j])
			{
				testMax2 = vec[j];
				count2 += 1;
			}
		}

		//25 ~ 50����
		if (count1 >= count2)
		{
			if (result < count1)
			{
				result = count1;
			}
			s = m + 1;
		}
		else
		{
			if (result < count2)
			{
				result = count2;
			}
			e = m;
		}
	}
	
	cout << result;

	return 0;
}