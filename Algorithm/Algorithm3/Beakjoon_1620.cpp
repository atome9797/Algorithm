#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	//
	// 문제
	// 1. 포켓몬의 번호를 보면 포켓몬의 이름을 말하는 연습을 하라
	// 입력
	// 1. N과 M을 입력받는다.
	// 처리
	// 1. 숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야함.
	// 2. 알파벳으로 들어오면 포켓몬 번호를 말해야 한다.
	// 출력
	//
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> map1;
	unordered_map<int, string> map2;
	bool isNumber = false;
	for (int i = 0; i < N + M; i++)
	{
		if (i < N)
		{
			string str = "";
			cin >> str;
			map1.insert({ str, i + 1});
			map2.insert({ i, str});
		}
		else
		{
			string str = "";
			cin >> str;

			//입력 받는 게 문자인지 숫자인지 구분해줘야한다.
			//유니코드로 구분한다.
			if (str[0] >= '0' && str[0] <= '9')
			{
				isNumber = true;
			}
			else
			{
				isNumber = false;
			}

			if (isNumber)
			{
				int num = stoi(str);
				cout << map2.at(num - 1) << "\n";
			}
			else
			{
				cout << map1.at(str) << "\n";
			}

		}
	}

	return 0;
}