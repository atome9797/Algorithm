#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//
	// 문제
	// 1. 배열 B[k]를 구해보자
	// 입력
	// 1. N을 입력 받는다.
	// 2. K를 입력 받는다. (K는 min(10의 9승, N의 2승) 보다 작거나 같은 자연수이다.)
	// 처리
	// 1. N*N의 일차원 배열을 만든다.
	// 2. 일차원 배열에서 이분탐색으로 k 값
	// 출력
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int s = 1;
	int e = K;
	int m;
	int result = 0;


	while (s <= e)
	{
		m = (s + e) / 2;
		int cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(N , m / i); 
			//각 행에서(각 행의 숫자를 비교해야 함으로 나누기 i해준다.)  
			//나눗셈을 통해서 각 행의 숫자의 개수를 알수있다.
		}

		if (cnt < K)
		{
			s = m + 1;
		}
		else
		{
			result = m;
			e = m - 1;
		}
	}

	cout << result << "\n";
	

	return 0;
}