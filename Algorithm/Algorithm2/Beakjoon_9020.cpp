#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int prime_number[10001] = { 0 };

int main()
{
	//����
	// 1. ¦��n�� �־������� �Ҽ� 2�� �� ����Ѵ�.
	// �Է�
	// 1. �׽�Ʈ���̽� T�� �Է� �޴´�.
	// 2. �׽�Ʈ ���̽� ��ŭ �ݺ����� ������.
	// 2-1. ¦�� n�� �Է��Ѵ�.
	// ó��
	// 1. ¦��n �� �Ҽ� 2���� ��� ��Ÿ���� �ø��Ѵ�.
	// 1-1. �Ҽ���� 2���� �迭�� ������.
	// 1-2. �Ҽ� 2���� ���� ���� ¦���� ������ break�ɾ��ش�.
	// 1-2-1. �Ҽ��� ���� ���� ���� ���� ��� �Ѵ�.
	// 1-2-2. �Ҽ� 2���� �̸� �޾� �ΰ� �� �� �Ҽ��� ������ �� ���� �Ҽ����� ������ ������Ʈ�ǰ� �ؼ� ���������� �� �Ҽ��� ����ϰ� �Ѵ�.
	// ���
	// 1. �Ҽ� 2���� ����Ѵ�.
	
	prime_number[1] = 1;

	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i * 2; j <= 10000; j += i)
		{
			if (prime_number[j] != 1)
			{
				prime_number[j] = 1;
			}
		}
	}
	

	int T = 0;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int n = 0;
		scanf("%d", &n);

		int prime = 10000;
		int prime2 = 0;

		for (int i = 2; i <= 10000; i++)
		{
			if (n - i < 0)
			{
				break;
			}
			
			int min = n - i; // 3
			int max = i; //13

			if (min > max)
			{
				int temp = max;
				max = min;
				min = temp;
			}

			if (prime > (max - min) && prime_number[min] == 0 && prime_number[max] == 0)
			{
				//�Է°� - �Ҽ�
				prime = max - min;
				prime2 = min;

			}
		}

		if (prime2 > n - prime2)
		{
			printf("%d %d\n", n - prime2, prime2);
		}
		else
		{
			printf("%d %d\n", prime2, n - prime2);
		}
	}

	return 0;
}