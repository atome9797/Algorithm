#include <iostream>

using namespace std;

int main()
{

	//문제
	//1. n킬로그램 설탕 배달할때 봉지 최소개수 구하기
	//입력
	// 1. 사용자의 입력 키로를 받는다.
	// 
	int sugar = 0;
	cin >> sugar;
	//처리

	// 1. 사용자의 입력을 5킬로 단위로 분리하고, 나머지를 3킬로 단위로 분리한다.
	int sugar_5 = 0;
	int sugar_3 = 0;
	
	bool exist = true;

	//5의 배수에 우선권을 두고 반복문을 돌려 -5 -3씩 해주기 (나머지 구하는식)
	while (sugar > 0)
	{
		
		if (sugar >= 5 && (sugar % 3 != 0 || sugar % 5 == 0))
		{
			sugar_5 += 1;
			sugar -= 5;
		}
		else if(sugar >= 3 && sugar % 3 == 0)
		{
			sugar_3 += 1;
			sugar -= 3;
		}
		else {
			exist = false;
			break;
		}

	}

	if (exist) {
		cout << sugar_5 + sugar_3 << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
	//출력
}