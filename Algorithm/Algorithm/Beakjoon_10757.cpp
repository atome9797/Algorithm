#include <iostream>

using namespace std;
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

	char A[10000];
	char B[10000];
	char C[10000];

	cin >> A;
	cin >> B;

	int array_a = 0;
	int array_b = 0;

	for (int i = 0; A[i] != '\0'; i++)
	{
		array_a++;
	}

	for (int i = 0; B[i] != '\0'; i++)
	{
		array_b++;
	}

	//연산하는 부분
	if (array_a > array_b) {
		int upCount = 0;
		for (int i = 0; i < array_a; i++)
		{
			int num = A[i] - '0';
			int num2 = B[i] - '0';

			C[i] = ((num + num2 + upCount) % 10) + '0';
			upCount = (num + num2 + upCount) / 10;

		}
	}
	else {
		for (int i = 0; i < array_b; i++)
		{

		}
	}

	

	cout << A << endl;
	cout << B << endl;
	

	cout << "합계" << C << endl;


	return 0;
}