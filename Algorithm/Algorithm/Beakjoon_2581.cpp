#include <iostream>

using namespace std;

int main()
{

	//문제
	//	1. 최댓값과 최솟값을 지정하고 범위 안의 소수의 값의 합과 최소 소수값을 출력한다.
	// 입력
	// 1. 최댓값 n과 최솟값 m을 입력 받는다. 
	// 처리
	// 1. 소수면 합한다.
	// 2. 소수 최솟값을 구한다.
	// 3. 소수가 없으면 -1 로 처리 한다.
	// 출력

	bool sosu[10005] = { false };

	//소수 배열 만들기 => 소수 일땐 true 로 담기게 한다.
	// 1-1. 소수 의 법칙을 지정한다.
	// 1-2. 소수는 1과 자기 자신 이외에 약수를 가지지 않는 수를 이야기 한다.
	for (int sosuNum = 2; sosuNum <= 10000; sosuNum++)
	{
		bool exist = true;
		for (int j = 2; j <= 10000; j++)
		{
			//소수가 아닐때 false
			if (sosuNum != j && sosuNum % j == 0)
			{
				exist = false;
			}
		}

		if (sosuNum == 2) {
			exist = true;
		}
		sosu[sosuNum] = exist;
	}

	//입력
	int min = 0;
	int max = 0;

	cin >> min >> max;

	//큰수로 정렬한다.
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}

	int min_sosu = 0;
	int sosu_sum = 0;
	int sosucount = 0;
	for (int i = max; i >= min; i--)
	{
		if (sosu[i])
		{
			min_sosu = i;
			sosu_sum += i;
			sosucount++;
		}
	}
	if (min_sosu == 0)
	{
		cout << -1 << "\n";
	}
	else {
		cout << sosu_sum << "\n";
		cout << min_sosu << "\n";
	}


	return 0;
}