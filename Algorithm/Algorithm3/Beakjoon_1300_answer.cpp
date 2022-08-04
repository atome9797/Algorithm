#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int s, e, m;
	int result = 0;
	s = 1;
	e = K;

	while (s <= e)
	{
		m = (s + e) / 2;

		int cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(N , m / i);
		}

		//ÀûÀ»¶©
		if (cnt < K)
		{
			s = m + 1;
		}
		else
		{
			result = m;
			e = m - 1;
		}
	}

	cout << result;

	return 0;
}