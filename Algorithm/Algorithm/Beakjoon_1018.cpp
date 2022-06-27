#include <iostream>

using namespace std;

int main()
{

	//
	// 문제
	// 1. 체스판에 다시 칠해야 하는 부분의 숫자를 출력하라
	// 입력
	// 1. N과 M 을 입력 받아라. N과 M은 8보다 크고 50보다 작다.
	// 2. N개의 줄만큼 반복문을 돌린다.
	// 3. M개의 문자를 입력한다.
	// 처리
	// 4. M개의 문자가 W로 시작하고 고쳐야 할 부분이 있으면 카운트해준다.
	// 5. 다음줄은 B로 시작하고 고쳐야 할 부분이 있으면 카운트 해준다.
	// 6. 첫번째 줄의 첫번째 글자가 W면 whiteBlack이 true, 아니면 false
	// 6-1. whiteBlack이면 홀수는 B 짝순는 W 
	// 7. 다음줄은 whiteBlack의 not으로 설정
	// 8. 
	// 출력
	//

	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int M = 0;
	cin >> N >> M;

	bool whiteBlack = false;

	int count[50][50] = {0};

	//N = 9면 2번 실행함
	for (int k = 0; k <= N - 8; k++)
	{
		for (int m = 0; m <= M - 8; m++)
		{
			for (int i = k; i < k + 8; i++)
			{
				char chess[51] = { 0 };

				for (int j = m; j < m + 8; j++)
				{
					cin >> chess[j];

					if (chess[k * M] == 'W' && i == 0)
					{
						whiteBlack = true; //white일때 true
					}

					if (whiteBlack == true)
					{
						//짝수 이고 j가 w이면 합격 //홀수 이고 j가 B이면 합격
						if (!((j % 2 == 0 && chess[j] == 'W') || (j % 2 == 1 && chess[j] == 'B')))
						{
							count[k][m]++;
						}
					}
					else
					{
						//짝수 이고 j가 w이면 합격 //홀수 이고 j가 B이면 합격
						if (!((j % 2 == 1 && chess[j] == 'W') || (j % 2 == 0 && chess[j] == 'B')))
						{
							count[k][m]++;
						}
					}

				}

				whiteBlack = !whiteBlack;
			}
		}
	}

	int result = N * M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (count[i][j] < result)
			{
				result = count[i][j];
			}
		}
	}

	
	cout << result;

	return 0;
}