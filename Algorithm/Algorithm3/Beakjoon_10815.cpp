#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main()
{

	//
	// 문제
	// 1. 정수 M개가 주어졌을때 이수가 숫자카드를 상근이가 가지고 있는지 없는지를 구하시오.
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 반복문을 돌리며 숫자를 입력 받는다. (중복 없음)
	// 3. M을 입력 받는다.
	// 4. M 만큼 반복문을 돌리며 숫자를 입력 받는다. 
	// 4-1. 
	// 
	// 출력
	//
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int M = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;
		if (binary_search(vec.begin(), vec.end(), num))
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}


	return 0;
} 