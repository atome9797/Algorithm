#include <iostream>

using namespace std;

int lan[1000000];

int main()
{
	//
	// 문제
	// 1. 적어도 M 미터의 나무를 집에 가져가기 위해서 절단기에 설정할수 있는 높이의 최댓값을 구하시오.
	// 입력
	// 1. 나무의 수 N과 상근이의 원하는 나무길이 M 을 입력 받는다.
	// 처리
	// 출력
	// 1. 적어도 M미터 나무를 집에 가져가기 위해서 절단기 높이 최댓값을 출력하시오.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0, Max = 0;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> lan[i];
		if (Max < lan[i])
		{
			Max = lan[i]; //최댓값을 구한다.
		}
	}

	int s = 1;
	int e = Max + 1;
	int result = 0;
	while (s < e)
	{

		int m = (s + e) / 2;

		int count = 0;

		//벌목해서 얻을수 있는 길이를 구한다.
		for (int i = 0; i < N; i++)
		{
			if (lan[i] >= m)
			{
				count += lan[i] - m;
			}
		}

		if (count >= M)
		{
			if (result < m)
			{
				result = m;//해당 m값을 저장해둠
			}

			s = m + 1; //늘리는 작업
		}
		else
		{
			e = m; //줄이는 작업
		}
	}

	cout << result;


}