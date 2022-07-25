#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

	//문제
	// 1. 균형잡힌 문자열인지 아닌지 판단하기
	// 입력
	// 1. 여러줄의 문자열을받고 소괄호와 대괄호로 이루어져 있다.
	// 1-1. 각 줄은 마침표로 끝난다.
	// 1-2. 아무것도 입력하지 않고 마침표를 입력하면 문자열이 끝난다.
	// 처리
	// 1. 각 줄마다 균형잡혀 있으면 true, 없으면 false를 출력한다.
	// 1-1. stack에 문자열을 담아준다.
	// 출력

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1)
	{
		stack<char> stack1;
		
		/*char ss[101] = {0};
		cin.getline(ss , 100);*/

		string str;
		getline(cin, str);
		
		if (str[0] == '.')
		{
			break;
		}

		for (int i = 0; i < str.size(); i++)
		{

			//() [] . 만 스택에 저장함
			char front = '0';
			char back = '0';

			if (stack1.empty() == false)
			{
				front = stack1.top();
			}

			if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
			{
				stack1.push(str[i]);
			}

			if (stack1.empty() == false)
			{
				back = stack1.top();
			}

			if ((back == ')' && front == '(') || (back == ']' && front == '['))
			{
				stack1.pop();
				stack1.pop();
			}

		}

		if (stack1.empty())
		{
			std::cout << "yes" << "\n";
		}
		else
		{
			std::cout << "no" << "\n";
		}

	}
	
}