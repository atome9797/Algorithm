#include <iostream>
using namespace std;

int setNum[10001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int N = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		setNum[num] += 1;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (setNum[i] != 0)
		{
			cout << i << "\n";
			setNum[i] -= 1;
			i--;
		}
	}
	
	
	return 0;
}