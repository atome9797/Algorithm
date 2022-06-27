#include <iostream>
#include <algorithm>
using namespace std;

int array1[100000] = { 0 };

bool isExist1(int s, int e , int num)
{

	int m = (s + e) / 2;

	if (s >= e)
	{
		return false;
	}

	if (array1[m] == num)
	{
		return true;
	}

	if (array1[m] < num)
	{
		s = m + 1;
	}
	else
	{
		e = m;
	}

	isExist1(s,e,num);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> array1[i];
	}

	sort(array1, array1+N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		bool isExist = false;
		int s = 0, e = N;
		while (s < e)
		{
			//중간 지점 구하고
			int m = (s + e) / 2;
			//비교하고
			if (array1[m] == num)
			{
				isExist = true;
				break;
			}

			//그거에 따라서 범위 조정
			if (array1[m] < num)
			{
				s = m + 1;
			}
			else
			{
				e = m;
			}
		}

		cout << (isExist ? "1\n" : "0\n");
	}


}