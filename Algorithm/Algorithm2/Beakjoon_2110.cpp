#include <iostream>

using namespace std;

using ll = long long;

ll N, C, M = 0;
ll lan[200000];

int main()
{

	//
	// 문제
	// 1. C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 
	//		최대로 하는 프로그램을 작성하시오.
	// 입력
	// 1. 집의 개수 N과 공유기 개수 C를 입력 받는다. (나눗셈 사용)
	// 처리
	// 출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> lan[i];
		if (M < lan[i])
		{
			M = lan[i];
		}
	}

	
	ll s = 1, e = M + 1;

	while (s < e)
	{
		int m = (s + e) / 2;

		int count = 0;

		for (int i = 0; i < N; i++)
		{
			count += lan[i] / m;
		}
	}



}