#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// 문제
	// 1. N명의 몸무게와 키가 담긴 입력을 읽어서 각 덩치 등수를 계산하여 출력한다.
	// 입력
	// 1. 전체 입력 횟수 N을 입력한다.
	// 2. N번 반복문을 돌린다.
	// 3. 두개의 배열을 입력 받는다.
	// 4. 배열 한개를 더 입력 받아 카운트 한다.
	// 4-1. 카운트는 더 큰 수가 나올때 한다.
	// 처리
	// 1. 카운트한 수 순서대로 큰 수일수록 1등 되게 설정
	// 출력
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	
	int array1[50] = { 0 };
	int array2[50] = { 0 };
	int sort[50] = { 0 };

	for (int i = 0; i < N; i++)
	{
		int kgram = 0;
		int height = 0;

		cin >> kgram >> height;

		array1[i] = kgram;
		array2[i] = height;
		sort[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (array1[i] < array1[j] && array2[i] < array2[j])
			{
				sort[i] += 1;
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		cout << sort[i] << " ";
	}

	return 0;
}