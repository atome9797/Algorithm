#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// 문제
	// 1. 666이 들어간 종말의 숫자를 작은 순서대로 뽑았을때 N번째 종말의 숫자를 출력하시오.
	// 입력
	// 1. N을 입력 받는다.
	// 2. 영화 제목을 받을 변수 moveNum 를 선언한다.
	// 3. 몇 번째 영화인지 카운트해줄 변수를 선언한다.
	// 처리
	// 1. 카운트횟수와 입력한 N이 다를때까지 반복문을 돌린다.
	// 2. moveNum 을 +1해준다. moveNum을 temp이라는 임시객체에 대입해준다.
	// 3. temp이 0이 아닐때까지 반복해준다.
	// 4. temp 을 1000으로 나눈 나머지가 666이면 카운트해준다. 그리고 나간다.
	// 5. temp을 10으로 나눈다.
	// 출력
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int moveNum = 0;
	int countNum = 0;
	int temp = 0;

	cin >> N;

	while (N != countNum)
	{
		moveNum++;
		temp = moveNum;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				countNum++;
				break;
			}
			else
			{
				temp = temp / 10;
			}
		}

	}
	
	cout << moveNum;


	return 0;
}