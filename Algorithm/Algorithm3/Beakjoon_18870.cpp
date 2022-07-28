#include <iostream>
#include <vector>

using namespace std;

bool number[20000002] = { false };
vector<int> number2(1000001);

vector <int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. 
	// 입력
	// 처리
	// 출력
	//

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		number[num + 1000001] = true;
		vec.push_back(num);
	}

	int count = 0;
	for (int i = 0; i < 1000001; i++)
	{
		if (number[i])
		{
			//number2[i] = count;
			count++;
		}
	}

	for (int element : vec)
	{
		cout << number2[element + 1000001] << " ";
	}





	return 0;
}