#include <iostream>

int main()
{

	//
	// 문제
	// 1.  M 이상 N이하의 소수를 출력하는 프로그램을 작성하기
	// 입력
	// 1. M과 N을 입력 받는다.
	int M = 0;
	int N = 0;
	std::cin >> M >> N;
	
	
	// 처리
	// 1. M과 N사이를 반복문을 돌려 소수를 구한다.
	for (int i = M; i <= N; i++)
	{
		bool exist = true;
		for (int j = 2; j <= i; j++)
		{
			//1과 자기 자신이 아닌 다른수로 나눠지면 false
			if (i != j && i % j == 0)
			{
				exist = false;
				break;
			}
		}

		if (exist && i != 1) {
			std::cout << i << "\n";
		}
	}


	
	

	return 0;
}