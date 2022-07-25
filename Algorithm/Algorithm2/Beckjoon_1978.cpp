#include <iostream>

using namespace std;

int main()
{


	bool sosu[1005] = { false };

	//소수 배열 만들기 => 소수 일땐 true 로 담기게 한다.
	// 1-1. 소수 의 법칙을 지정한다.
	// 1-2. 소수는 1과 자기 자신 이외에 약수를 가지지 않는 수를 이야기 한다.
	for (int sosuNum = 2; sosuNum <= 1000; sosuNum++)
	{
		bool exist = true;
		for (int j = 2; j <= 1000; j++)
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

	for (int i = 0; i < 100; i++)
	{
		if (sosu[i])
		{
			cout << i << endl;
		}
	}

	
	//문제
	// 입력
	// 1. 첫 줄에 개수 n을 입력 받는다.
	// 2. n개의 수만큼 숫자를 입력한다.
	int n = 0;
	cin >> n;


	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;

		// 처리	
		// 1. n개의 입력 숫자중에 소수의 개수를 센다.
		//소수면 카운트 해준다.
		if (sosu[num])
		{
			count++;
		}
	}

	// 출력
	// 1. 셈한 소수의 개수를 출력 한다.
	cout << count;

}
