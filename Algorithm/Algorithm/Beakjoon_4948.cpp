#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime_number[123458] = { 0 };

int main()
{
	//문제
	// 1. 자연수 n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하기
	// 입력
	// 1. 2n만큼의 반복문을 돌려 시간복잡도를 낮추는 방식 사용
	// 처리
	// 출력
	for (int i = 2; i <= 123456; i++)
	{
		for (int j = 2; i * j <= 123456; j++)
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

		int test = num * 2;

		if (test > 123456)
		{
			test = 123456;
		}

		for (int i = num + 1; i <= test; i++)
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