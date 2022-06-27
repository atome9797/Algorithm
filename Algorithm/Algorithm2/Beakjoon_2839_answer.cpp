#include <iostream>

using namespace std;


int main()
{

	//설탕 봉지 문제
	//5킬로를 활용한 횟수를 뺀 나머지를 3으로 나눠지면 정답을 출력한다.
	//안 나눠 지면 5킬로 횟수 -1 해줌
		//3킬로도 안나눠지면 -1

	int sugar = 0;
	cin >> sugar;

	int sugar_5 = sugar / 5;//5킬로로 나눈 총 횟수를 구한다.
	int sugar_3 = 0;

	while (true)
	{
		//0일때 까진 허용하고 -1 부터 허용하지 않는다.
		if (sugar_5 < 0)
		{
			cout << -1 << "\n";
			return 0; //리턴 해줌으로써 메인 함수를 끝낸다.
		}

		//5봉지를 최대한 사용하면서 3봉지를 사용해 최소 개수를 구할수 있다.
		if ((sugar - (5 * sugar_5)) % 3 == 0)
		{
			sugar_3 = (sugar - (5 * sugar_5)) / 3;
			break;
		}
		sugar_5--;
	}
	
	cout << sugar_5 + sugar_3 << "\n";

	return 0;
}