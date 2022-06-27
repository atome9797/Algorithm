#include <iostream>

using namespace std;

int prime_number[300000] = { 0 };

int main()
{
	
	while (1)
	{
		int cnt = 0;

		int n = 0;
		cin >> n;

		if (n == 0) 
		{
			break;
		}

		for (int i = 2; i <= n * 2; i++)
		{
			for (int j = i * 2; j <= n * 2; j += i)
			{
				if (prime_number[j] != 1)
				{
					prime_number[j] = 1;
				}
			}

		}

		for (int i = n + 1; i <= n * 2; i++)
		{
			if (prime_number[i] == 0)
			{
				cnt++;
			}
		}

		cout << cnt << "\n";

	}

	return 0;
}