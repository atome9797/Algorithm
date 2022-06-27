#include <iostream>

using namespace std;

int main()
{
	//
	// 문제
	// 1. 정수 n이 주어졌을때 소인수분해하는 프로그램 만들기
	// 입력
	// 1. 정수 n을 입력받는다. 
	int N = 0;
	cin >> N;
	// 처리
	// 1. N이 양수일때 반복문을 돌려준다.
	//1-1. cal을 반복문으로 늘려주면서 나눠질때  
	//1-1-1. N을 나눈값으로 가지게 하고 cal을 다시 초기화 해줌으로써 인수분해 될수있도록 처리한다.
	int cal = 2;
	while (N > 1)
	{
		if (N % cal == 0)
		{
			N = N / cal;
			cout << cal << endl;

			cal = 2;
		}
		else {
			cal++;
		}
	}
	// 2. 
	// 출력
	//
	

	return 0;
}