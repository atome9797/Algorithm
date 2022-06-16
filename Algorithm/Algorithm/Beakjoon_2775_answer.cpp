#include <iostream>

using namespace std;

int department(int flow, int host)
{

	//0층의 인원수를 1 2 3 방식으로 더해줘서 올라온다.

	if (flow == 0) //0층의 호수별 인원수를 더해준다.
	{
		return host; 
	}
	else if (host == 1) //각층의 1호는 1명이므로 리턴값이 고정된다.
	{
		return 1;
	}

	//이전 층의 현재 호수와 , 현재 층의 이전 호수의 합을 구한다.
	return department(flow, host - 1) + department(flow - 1, host);
}

int main()
{

	//아파트 재귀 함수로 풀기
	//사용자가 층수와 호수를 입력받는다.
	int flow = 0;
	int host = 0;
	cin >> flow >> host;
	int sum = department(flow,host);
	cout << sum << endl;

	return 0;
}