#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime_number[1000010] = { 0 };

int main()
{

	//
	// ����
	// 1.  M �̻� N������ �Ҽ��� ����ϴ� ���α׷��� �ۼ��ϱ�
	// �Է�
	// 1. M�� N�� �Է� �޴´�.
	int M = 0;
	int N = 0;
	scanf("%d %d", &M, &N);

	prime_number[1] = 1;

	// ó��
	//�Ҽ� �迭 ����� => �Ҽ� �϶� true �� ���� �Ѵ�.
	// 1-1. �Ҽ� �� ��Ģ�� �����Ѵ�.
	// 1-2. �Ҽ��� 1�� �ڱ� �ڽ� �̿ܿ� ����� ������ �ʴ� ���� �̾߱� �Ѵ�.
	//����϶��� ���� �ϸ�ȴ�.
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; i * j <= N; j++)
		{
			prime_number[i * j] = 1;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (prime_number[i] == 0)
		{
			printf("%d\n", i);
		}
	}



	return 0;
}