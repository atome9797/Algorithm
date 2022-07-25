#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int x[200000];

int main()
{

	//
	// 문제
	// 1. C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 
	//		최대로 하는 프로그램을 작성하시오.
	// 입력
	// 1. 집의 개수 N과 공유기 개수 C를 입력 받는다. (나눗셈 사용)
	// 처리
	// 2. 공유기 개수만큼 
	// 출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1.집의 개수와 공유기의 개수를 입력 받는다.
	cin >> N >> C;

	//2. 집의 좌표를 입력 받는다.
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}

	//3. 공유기 사이의 거리를 구하기 위해 집의 좌표를 정렬한다.
	sort(x, x + N);
	
	//4.이진 검색을 할 범위는 가장 인접한 공유기 사이의 거리
	// [1, x[N - 1]] (최소 거리 1, 최대 거리 x[N - 1])
	int s = 1; // 0 ~ 1 , 1 ~ 2
	int e = x[N - 1] + 1; // 0 ~ 9
	int result = 0;

	while (s < e)
	{
		// 4-1. 중앙값을 해의 후보로 정한다.
		//s : 1, e : 10, m : 5
		int m = (s + e) / 2; //공유기 거리


		//4-2. 실제로 m거리 만큼 떨어뜨려 몇개의 공유기를 배치할수 있는지 확인한다.
		int count = 1;
		/*int distance = x[0] + m;
		
		for (int i = 0; i < N; i++)
		{
			if (distance <= x[i])
			{
				distance = x[i] + m;
				count++;
			}
		}*/

		int p = 0;
		for (int i = 0; i < N; i++)
		{
			if (x[i] - x[p] >= m)
			{
				++count;
				p = i;
			}
		}


		if (count >= C)
		{
			//4-3. 최대 길이 최신화
			if (result < m)
			{
				result = m;
			}

			//4-4. 더 찾을수 있는지 범위 조절
			s = m + 1;
		}
		else
		{
			e = m;
		}
	}


	//4. 최대 거리를 출력한다.
	cout << result;

}