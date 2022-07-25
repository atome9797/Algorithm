#include <iostream>
#include <vector>

using namespace std;

int num[10000001][2] = {0};

int main()
{

	//문제
	// 1. 상근이가 가지고 있는 숫자카드의 개수를 구하시오.
	// 입력
	// 1. N을 입력 받는다.
	// 2. N만큼 반복문을 돌리며 숫자들을 입력 받는다.
	// 3. M을 입력 받는다.
	// 4. M만큼 반복문을 돌리며 숫자들을 입력 받는다.
	// 처리
	// 1. M만큼 반복문을 돌리며 숫자들이 몇개인지 입력 받는건 숫자들의 카운트를 담을 배열을 N만틈 반복문 돌릴때 따로 저장해둔 배열의 값을 불러오는 형식을 사용한다.
	// 출력
	//
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;

		if (input >= 0)
		{
			num[input][0] += 1;
		}
		else
		{
			int test = input * (- 1);
			num[test][1] += 1;
		}
	}

	int M = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input2 = 0;
		cin >> input2;
		
		if (input2 >= 0)
		{
			cout << num[input2][0] << " ";
		}
		else
		{
			int test = input2 * (-1);
			cout << num[test][1] << " ";
		}
	}

	return 0;
}