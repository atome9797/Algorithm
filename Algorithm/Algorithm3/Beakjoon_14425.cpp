#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//
	// 문제
	// 1. N개의 문자열로 이루어진 집합 S가 주어진다.
	// 2. 입력으로 주어지는 M개의 문자열 중 집합 s에 포함되어 있는 것이 총 몇개인지 구하시오.
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 반복문을 돌리며 문자열을 입력 받는다.
	// 3. M을 입력 받는다.
	// 4. M만큼 반복문을 돌리며 문자열을 입력 받는다.
	// 처리
	// 1. M만큼 반복문을 돌리며 문자열을 입력 받을때 N에 문자열이 있는지 없는지 검사한다.
	// 1-1. 있으면 카운트 해준다.
	// 출력
	// 1. 카운트한 값을 출력한다.

	int N = 0;
	int M = 0;
	cin >> N >> M;

	vector<string> vec;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		
		vec.push_back(str);
	}
	
	sort(vec.begin(), vec.end());
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		string str = "";
		cin >> str;

		if (binary_search(vec.begin(), vec.end(), str))
		{
			count++;
		}
	}


	cout << count;

	return 0;
}