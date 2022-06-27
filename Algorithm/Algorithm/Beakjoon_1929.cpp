#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime_number[1000010] = { 0 };

int main()
{

	//
	// 문제
	// 1.  M 이상 N이하의 소수를 출력하는 프로그램을 작성하기
	// 입력
	// 1. M과 N을 입력 받는다.
	int M = 0;
	int N = 0;
	scanf("%d %d", &M, &N);

	prime_number[1] = 1;

	// 처리
	//소수 배열 만들기 => 소수 일땐 true 로 담기게 한다.
	// 1-1. 소수 의 법칙을 지정한다.
	// 1-2. 소수는 1과 자기 자신 이외에 약수를 가지지 않는 수를 이야기 한다.
	//배수일때를 제외 하면된다.
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