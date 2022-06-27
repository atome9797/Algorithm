#include <iostream>

using namespace std;

int count(int num)
{
	if (num < 10)
	{
		return num;
	}

	int sum = num % 10;
	num = num / 10;

	return sum + count(num);
}


int main()
{

	//
	// ����
	// 1. N�� ���� ���� �����ڸ� ���Ͻÿ�
	// 2. �������� ���ϴ� ������ 216 = M + 
	// �Է�
	// ó��
	// ���

	int N = 0;
	cin >> N;
	int num = 0;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		num = i + count(i);

		if (num == N)
		{
			answer = i;
			break;
		}
	}

	cout << answer << "\n";

	return 0;
}