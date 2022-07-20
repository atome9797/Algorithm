#include <iostream>
#include <unordered_set>

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

	unordered_set<string> set1;

	for (int i = 0; i < S.size(); i++)
	{
		string str;
		for (int j = 0; j < S.size(); j++)
		{
			str += S[j];
			set1.insert(str);
		}
	}

	

	cout << set1.size() << "\n";



	return 0;
}