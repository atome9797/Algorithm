#include <iostream>
#include <set>
#include <cmath>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. N개의 수가 주어졌을때 네가지 기본 통계값을 구하는 프로그램을 작성하시오.
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 반복문을 돌려 multiset에 정수를 입력 받는다.
	// 처리
	// 1. 최댓값과 최솟값을 산출한뒤 
	// 2. N의 절반만큼 반복문을 돌려 중앙값을 출력한다.
	// 출력
	//

	int N = 0;
	cin >> N;

	float sum = 0;
	multiset<int> ms;
	int mustCount = 0;
	int mustKey = 0;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		ms.insert(num); 
		
		if (ms.count(num) > mustCount)
		{
			mustKey = num;
			mustCount = ms.count(num);
		}
		else if (ms.count(num) == mustCount)
		{
			if (mustKey < num)
			{

			}
		}
		sum += num;
	}
	
	if (round((float)sum / N) == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << round((float)sum / N) << "\n";
	}

	int count = 0;
	for (multiset<int>::iterator iter = ms.begin(); iter != ms.end();)
	{
		if (count < N /2)
		{
			iter++;
		}
		else
		{
			cout << *iter << "\n";
			break;
		}

		count++;
	}

	cout << mustKey << "\n";

	multiset<int>::iterator iter1 = ms.begin();
	multiset<int>::iterator iter2 = ms.end();

	int Min = *iter1;
	int Max = *(--iter2);

	cout << Max - Min << "\n";


	return 0;
}