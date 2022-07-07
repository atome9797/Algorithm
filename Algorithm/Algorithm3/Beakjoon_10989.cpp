#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N = 0;
	cin >> N;
	
	priority_queue<int>pq;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (!pq.empty() && num == 0)
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
		else if (pq.empty() && num == 0)
		{
			cout << 0 << "\n";
		}
		else if (num != 0)
		{
			pq.push(num);
		}
	}

	return 0;
}