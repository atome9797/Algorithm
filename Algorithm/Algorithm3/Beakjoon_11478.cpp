#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// 문제
	// 1. 서로 다른 부분 문자열 개수를 구하는 프로그램을 작성하라
	// 입력
	// 1. 문자열 S가 주어진다.
	// 처리
	// 1. set 비선형구조를 사용해 중복없는 문자열을 입력 받는다.
	// 출력
	//

	string S;
	cin >> S;

	int level = 1;
	
	set<string> set1;

	while (level <= S.size())
	{
		int test = level;
		string str;
		for (int i = 0; i < S.size();) //0 ~ 4
		{
			str += S[i];
			if (i + 1 == test)
			{
				i = test;
				test += level;
				set1.insert(str);
				str = "";
				//i값을 카운트해서 올려줌
			}
			else
			{
				i++;
			}
		}
		level++; //0 ~ 4
	}

	cout << set1.size() << "\n";



	return 0;
}