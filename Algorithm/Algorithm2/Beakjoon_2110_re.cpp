#include <iostream>
#include <limits.h>

using namespace std;

using ll = long long; //오버플로우를 방지하기위해 longlong타입을 사용

ll K, N, M = 0;
ll lan[10000];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	// 문제
	// 1. 만들수 있는 최대 랜선의 길이를 구하시오.
	// 입력
	// 1. K와 N을 입력 받는다.
	cin >> K >> N;
	// 2. 가지고 있는 랜선의 길이를 입력 받는다.
	for (ll i = 0; i < K; i++)
	{
		cin >> lan[i];

		if (M < lan[i])
		{
			M = lan[i]; //최댓값으로 지정
		}
	}

	// 3. 이진 검색
	// 범위 : 자를수 있는 랜선의 길이
	//[1,M + 1) 가장 큰 길이
	ll s = 1, e = M + 1;

	ll result = 0; //문제에 대한 해
	while (s < e) //최솟값으로 설정하면 범위를 벗어나게 된다.
	{
		ll m = (s + e) / 2; //목표지점을 탐색한다.

		ll count = 0;

		for (ll i = 0; i < K; i++)
		{
			count += lan[i] / m;
		}

		//해
		//[115 ~ 229]
		if (count >= N)
		{
			if (result < m)
			{
				result = m;//해당 m값을 저장해둠
			}

			s = m + 1;
		}
		else
		{
			e = m;
		}
	}

	// 처리

	// 출력
	cout << result;
	//
}
