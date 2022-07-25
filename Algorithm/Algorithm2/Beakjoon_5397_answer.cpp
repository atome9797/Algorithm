#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//for (char ch : input)
	//{
	//	//컨테이너에 데이터를 삽입하거나 삭제하면 안됨
	//}

	int testCase;
	cin >> testCase;
	while (testCase--)
	{

		//1.문자열을 입력 받는다.
		string input;
		cin >> input;
		//2. 컨테이너 2개를 만든다.
		//하나는 커서 왼편에 존재하는 문자열로 정방향으로 저장
		// 다른 하나는 커서 오른편에 존재하는 문자열로 역방향으로 저장
		vector<char> left, rightReversed;

		//3. 각 문자를 적절하게 처리한다.
		//알파벳 대소문자, 숫자 , 백스페이스(-), 화살표 (<>)
		for (char ch : input)
		{
			switch (ch)
			{
			case '<' :
				if (false == left.empty())
				{
					rightReversed.push_back(left.back());
					left.pop_back();
				}
				break;
			case '>':
				if (false == rightReversed.empty())
				{
					left.push_back(rightReversed.back());
					rightReversed.pop_back();
				}
				break;
			case '-':
				if (false == left.empty())
				{
					left.pop_back();
				}
				break;
			default:
				left.push_back(ch);
				break;

			}
		}

		//rightReversed를 거꾸로 출력하는 이유는 입력시 left 에 존재 하던 요소를 반대 순서대로 저장하기 때문에 출력시는 반대로 출력한다.
		cout << string(left.begin(), left.end()) << string(rightReversed.rbegin(), rightReversed.rend()) << "\n"; //endl 은 flush작업까지 수행하기 때문에 느려짐

	}
}