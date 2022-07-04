#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;

int main()
{

	//
	// 문제
	// 1. N개의 수가 주어졌을때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
	// 입력
	// 1. N을 입력 받는다.
	// 2. N개 만큼 입력 받는다.
	// 처리
	// 출력
	//

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << "\n";
	}

	return 0;
}