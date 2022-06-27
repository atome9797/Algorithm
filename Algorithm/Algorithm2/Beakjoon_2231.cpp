#include <iostream>

using namespace std;

int count(int num)
{
	if (num < 10)
	{
		return num;
	}

	int sum = num % 10;
	num = num / 10;

	return sum + count(num);
}


int main()
{

	//
	// 문제
	// 1. N의 가장 작은 생성자를 구하시오
	// 2. 분해합을 구하는 공식은 216 = M + 
	// 입력
	// 처리
	// 출력

	int N = 0;
	cin >> N;
	int num = 0;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		num = i + count(i);

		if (num == N)
		{
			answer = i;
			break;
		}
	}

	cout << answer << "\n";

	return 0;
}