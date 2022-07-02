#include <iostream>

using namespace std;

char map[51][51] = {0};
char BlackWhiteCh[2] = {'B', 'W'};

int  check(int x, int y)
{
	int min = 987654321;
	//시작이 black 패턴일때
	
	for (int i = 0; i < 2; i++)
	{
		int count = 0;
		bool num = i;
		for (int i = x; i < 8 + x; i++)
		{
			for (int j = y; j < 8 + y; j++)
			{
				if (map[i][j] != BlackWhiteCh[num])
				{
					count++;
				}
				num = !num;
			}
			num = !num;
		}

		if (min > count)
		{
			min = count;
		}
	}


	return min;
}

int main()
{
	
	//
	// 문제
	// 1. 지민이는 8*8 크기의 체스판을 만들려고 한다. 지민이가 다시 칠해야 하는 정사각형의 최소
	// 개수를 구하는 프로그램을 만드시오.
	// 입력
	// 1. N과M을 입력 받는다.
	// 2. N과 M 크기 만큼 반복해서 입력 받는다.
	// 처리
	// 1. 체스판의 크기에 따라 8*8 체스판의 경우의 수 만큼 반복문을 돌린다.
	// 1-1. 체스판의 크기가 9*9면 총 4개의 경우의수를 가질수 있다. 4개의 경우의 수중 가장 최솟값으로 수정해야 하는 부분을 찾는다.
	// 2. 체스판의 경우의 수를 구하기 위해 입력값과 - 8 해준 값을 for문의 시작 점과 끝 부분에 넣어준다.
	// 3. 그리고 시작점이 B 인경우는  B패턴으로 생각한다. 아닌경우 W패턴으로 생각한다.
	// 출력
	
	int N = 0;
	int M = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
		}
	}

	int caseNUmX = N - 8;
	int caseNUmY = M - 8;

	int min = 978654321;

	for (int i = 0; i <= caseNUmX; i++)
	{
		for (int j = 0; j <= caseNUmY; j++)
		{
			int count = check(i,j);
			if (min > count)
			{
				min = count;
			}
		}
	}

	cout << min << "\n";
	

	return 0;
}