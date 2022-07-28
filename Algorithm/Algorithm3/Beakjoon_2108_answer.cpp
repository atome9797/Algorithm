#include <iostream>
#include<cmath> 

using namespace std;

int search[10000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//절댓값 4000을 넘지 않으므로 -4000 ~ 4000사이 수이다.
	int N = 0;
	int sum = 0;

	int Max = 0;
	int MaxNumber = -4000;
	int MinNumber = 987654321;
	//이전 최빈값과 새로운 최빈값을 담는 그릇을 생성하자
	int MaxCount = 0;
	int MaxCountTest = 0;
	int count = 0;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		search[num + 4000] += 1;
		sum += num;

		if (search[num + 4000] >= Max)
		{
			Max = search[num + 4000];
		}

		if (num >= MaxNumber)
		{
			MaxNumber = num;
		}
		if (num < MinNumber)
		{
			MinNumber = num;
		}

	}

	//산술평균
	float everage = round((float)sum / N);
	if (everage == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << round((float)sum / N) << "\n";
	}

	//중앙값
	for (int i = 0; i < 8005; i++)
	{
		if (search[i] != 0)
		{
			count += search[i];

			if (count >= (N / 2) + 1)
			{
				cout << i - 4000 << "\n";
				break;
			}
		}
	}

	for (int i = 0; i < 8005; i++)
	{
		if (search[i] == Max)
		{
			MaxCountTest++;
		}
	}


	for (int i = 0; i < 8005; i++)
	{
		if (search[i] == Max)
		{
			MaxCount++;
		}

		if (MaxCountTest >= 2)
		{
			if (search[i] == Max && MaxCount == 2)
			{
				cout << i - 4000 << "\n";
				break;
			}
		}
		else
		{
			if (search[i] == Max)
			{
				cout << i - 4000 << "\n";
				break;
			}
		}
	}

	//범위 출력
	cout << MaxNumber - MinNumber << "\n";



	return 0;
}