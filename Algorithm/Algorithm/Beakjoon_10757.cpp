#include <iostream>

using namespace std;

//10의 10만승은 10001임 10^2 => 100이므로 3자리수가됨
char A[10001] = { 0 };
char B[10001] = { 0 };
char C[10001] = { 0 };
char a_alpha[10001] = { 0 };
char b_alpha[10001] = { 0 };

int main()
{

	/*
		문제
			1. 두 정수의 합을 출력
		입력
			1. 두 정수를 배열형태로 입력받는다.
		처리
			1. 입력 받은 배열을 올림하는 방식으로 더해준다.
		출력
	*/

	
	cin >> A;
	cin >> B;

	int array_a = 0;
	int array_b = 0;
	int array_c = 0;

	for (int i = 0; A[i] != '\0'; i++)
	{
		array_a++;
	}


	int count = 0;
	for (int i = array_a -1 ; i >= 0; i--)
	{
		a_alpha[count] = A[i];
		count++;
	}

	for (int i = 0; B[i] != '\0'; i++)
	{
		array_b++;
	}

	int count2 = 0;
	for (int i = array_b - 1; i >= 0; i--)
	{
		b_alpha[count2] = B[i];
		count2++;
	}
	

	//연산하는 부분
	if (array_a >= array_b) {
		int upCount = 0;
		for (int i = 0; i < array_a; i++)
		{
			int num = a_alpha[i] - '0';
			int num2 = 0;
			if (b_alpha[i] == '\0')
			{
				num2 = b_alpha[i];
			}
			else
			{
				num2 = b_alpha[i] - '0';
			}

			C[i] = ((num + num2 + upCount) % 10) + '0';
			upCount = (num + num2 + upCount) / 10;

			//array_a이 끝이고 올림이 발생했다면 하나 더 넣어주기
			if (array_a - 1 == i && upCount == 1)
			{
				C[array_a] = upCount + '0';
			}

		}
	}
	else {
		int upCount = 0;
		for (int i = 0; i < array_b; i++)
		{
			int num = b_alpha[i] - '0';
			int num2 = 0;
			if (a_alpha[i] == '\0')
			{
				num2 = a_alpha[i];
			}
			else
			{
				num2 = a_alpha[i] - '0';
			}

			C[i] = ((num + num2 + upCount) % 10) + '0';
			upCount = (num + num2 + upCount) / 10;

			//array_a이 끝이고 올림이 발생했다면 하나 더 넣어주기
			if (array_b - 1 == i && upCount == 1)
			{
				C[array_b] = upCount + '0';
			}

		}
	}


	for (int i = 0; C[i] != '\0'; i++)
	{
		array_c++;
	}
	

	for (int i = array_c - 1; i >= 0; i--)
	{
		cout << C[i];
	}


	return 0;
}