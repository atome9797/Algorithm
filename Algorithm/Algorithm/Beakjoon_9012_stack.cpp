#include <iostream>
#include <stack>

using namespace std;

int main()
{
	
	// 문제
	// 1. 괄호 문자열은 ( ,  ) 만으로 구성된 문자열이다. 한쌍의 ( ) 문자열은 기본 vps라 부름
	// 2. 문자 x가 vps라면 (x)도 vps다. 쌍을 이루지 않으면 vps가 아닌 문자열이다.
	// 3. vps인지 아닌지 판단해서 그결과를 yes, no 로 나타내어야 한다.
	// 입력
	// 1. 테스트 케이스 T를 입력 받는다.
	// 2. 테스트 케이스 만큼 반복문을 돌려 준다.
	// 3. 입력 input을 괄호 문자열이 주어진다.
	// 처리
	// 1. 올바른 괄호 문자열이면 yes, 아니면 no를 출력 한다.
	// 1-1. 문자열을 입력 받고 입력 받은 문자열에서 ) 괄호를 만났을때 이전 top이 ( 면 같이 삭제해줌
	// 출력

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case = 0;
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++)
	{
		string str;
		cin >> str;
		stack<char> stack1;

		for (char ch : str)
		{
			char front = '0';
			char back = '0';
			if (stack1.empty() == false)
			{
				front = stack1.top();
			}
			
			stack1.push(ch);
			
			if (stack1.empty() == false)
			{
				back = stack1.top();
			}

			if (back == ')' && front == '(')
			{
				stack1.pop();
				stack1.pop();
			}
		}

		if (stack1.empty())
		{
			std::cout << "YES" << "\n";
		}else 
		{
			std::cout << "NO" << "\n";
		}
	}


	return 0;
}