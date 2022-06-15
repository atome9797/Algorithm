#include <iostream>

using namespace std;



int main()
{

	//문제 
	// 1. 해당층의 해당 호수에 살고 잇는 인원수를 출력하기
	//입력
	// 1. 테스트 케이스 T를 입력한다.
	// 2. 테스트 케이스 만큼 반복문을 돌려 층수와 호수를 입력받는다.
	//처리
	// 1. 반복문을 돌려 for(i<j)방식으로 더해주는 방식으로 인원수를 늘려간다.
	//출력
	//해당 층의 호수의 인원수를 출력한다.

	//부녀 회장
	//2차원 배열로 호수별 인원 배열 만들기
	int department[15][15] = { 0 };

	for (int i = 0; i < 14; i++)
	{
		department[0][i] = i + 1;
	}

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 0; j < 14; j++) //0은 1호
		{
			int sum = 0;
			for (int k = 0; k <= j; k++)
			{

				sum += department[i - 1][k];

			}
			department[i][j] = sum;
		}
	}


	//입력
	// 1. 테스트 캐이스와 테스트 케이스에 따른 k층과 n호를 입력 받는다.
	int test_case = 0;
	cin >> test_case;

	//처리
	// 1.  
	for (int i = 0; i < test_case; i++)
	{

		int k = 0;
		int n = 0;

		cin >> k;
		cin >> n;

		cout << department[k][n - 1] << "\n";
	}
	////출력


	return 0;
}