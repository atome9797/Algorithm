#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	//
	// 문제
	// 1. 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
	// 입력
	// 1. 수열의 개수 N을 입력 받는다.
	// 2. 수열의 개수만큼 반복문을 돌린다.
	// 처리
	// 1. 최장 증가 부분 수열의 경우 나중에 반복 되더라도 가장 긴 수열을 이루면 그 수열의 크기가 최장 증가 부분 수열이 된다. 예) 10 , 1 ,2 , 3, 4, 50 이면 10을 제외한 나머지가 최장 증가 부분 수열이 된다.
	// 2. 기존 이분 탐색에서 기준점을 기준으로 계산했을때 0부터 끝까지 검색해서 수열을 구하고, 25부터 끝까지 검색해서 수열을 구해 비교하고 큰 쪽으로 범위를 줄인다.
	// 3. 범위를 좁혀가며 검색해준다.
	// 4. 25로 검색했을때 더 많으면 25부터 50까지로 범위를 좁히고, 더 적으면 1 부터 25범위로 줄인다.
	// 출력
	// 1. 배열의 크기를 측정한다.


	int N = 0;
	int Max = 0;
	cin >> N;
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (Max < num)
		{
			Max = num;
		}
		vec.push_back(num);
	}

	int s = 0;
	int total = vec.size();
	int e = vec.size();

	int result = 0;

	while (s <= e)
	{
		int m = (s + e) / 2;

		int count1 = 0;
		int count2 = 0;
		int testMax1 = 0;
		int testMax2 = 0;
		for (int i = m; i < total; i++)
		{
			if (testMax1 < vec[i])
			{
				testMax1 = vec[i];
				count1 += 1;
			}
		}

		for (int j = s; j < total; j++)
		{
			if (testMax2 < vec[j])
			{
				testMax2 = vec[j];
				count2 += 1;
			}
		}

		//25 ~ 50범위
		if (count1 >= count2)
		{
			if (result < count1)
			{
				result = count1;
			}
			s = m + 1;
		}
		else
		{
			if (result < count2)
			{
				result = count2;
			}
			e = m;
		}
	}
	
	cout << result;

	return 0;
}