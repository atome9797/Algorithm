#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime_number[250001] = { 0 };

int main()
{
	//����
	// 1. �ڿ��� n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ������ ���ϱ�
	// �Է�
	// 1. 2n��ŭ�� �ݺ����� ���� �ð����⵵�� ���ߴ� ��� ���
	// ó��
	// ���
	for (int i = 2; i <= 250000; i++)
	{
		for (int j = 2; i * j <= 250000; j++)
		{
			prime_number[i * j] = 1;
		}
	}
	prime_number[1] = 1;

	int num = 0;
	while(true)
	{
		

		int cnt = 0;
		
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}


		for (int i = num + 1; i <= num*2; i++)
		{
			if (prime_number[i] == 0)
			{
				cnt++;
			}
		}

		printf("%d\n", cnt);

	}



	return 0;
}