#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

<<<<<<< Updated upstream
int prime_number[1000010] = { 0 };
=======
int sosu[1000001] = { 0 };
>>>>>>> Stashed changes

int main()
{
	sosu[1] = 1;
	//
	// ����
	// 1.  M �̻� N������ �Ҽ��� ����ϴ� ���α׷��� �ۼ��ϱ�
	// �Է�
	// 1. M�� N�� �Է� �޴´�.
	int M = 0;
	int N = 0;
<<<<<<< Updated upstream
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
=======
	scanf("%d", &M);
	scanf("%d", &N);
	
	// ó��
	// 1. M�� N���̸� �ݺ����� ���� �Ҽ��� ���Ѵ�.
	
	//�Ҽ� �迭 ����� => �Ҽ� �϶� true �� ���� �Ѵ�.
	// 1-1. �Ҽ� �� ��Ģ�� �����Ѵ�.
	// 1-2. �Ҽ��� 1�� �ڱ� �ڽ� �̿ܿ� ����� ������ �ʴ� ���� �̾߱� �Ѵ�.
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; i*j <= N; j++)
		{
			sosu[i * j] = 1;
>>>>>>> Stashed changes
		}
	}

<<<<<<< Updated upstream
	for (int i = M; i <= N; i++)
	{
		if (prime_number[i] == 0)
		{
			printf("%d\n", i);
		}
	}


=======
	}


	for (int i = M; i <= N; i++)
	{
		if (sosu[i] == 0)
		{
			printf("%d\n", i);
		}
	}
	
>>>>>>> Stashed changes

	return 0;
}