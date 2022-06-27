#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int prime_number[10001] = { 0 };

int main()
{
	//문제
	// 1. 짝수n이 주어졌을때 소수 2개 를 출력한다.
	// 입력
	// 1. 테스트케이스 T를 입력 받는다.
	// 2. 테스트 케이스 만큼 반복문을 돌린다.
	// 2-1. 짝수 n을 입력한다.
	// 처리
	// 1. 짝수n 이 소수 2개로 어떻게 나타낼지 궁리한다.
	// 1-1. 소수들로 2차원 배열을 돌린다.
	// 1-2. 소수 2개를 합한 값이 짝수와 같으면 break걸어준다.
	// 1-2-1. 소수의 차가 가장 적은 값이 어야 한다.
	// 1-2-2. 소수 2개를 미리 받아 두고 그 두 소수의 차보다 더 적은 소수차가 나오면 업데이트되게 해서 최종적으로 그 소수를 출력하게 한다.
	// 출력
	// 1. 소수 2개를 출력한다.
	
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
				//입력값 - 소수
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