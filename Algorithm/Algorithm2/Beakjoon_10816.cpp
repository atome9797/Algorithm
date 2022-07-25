#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//문제
	// 1. 상근이가 몇개의 카드를 가지고 있는지 구하시오
	//입력
	// 1. 상근이가 가지고 있는 카드 개수 입력
	// 2. 카드 개수만큼 반복문 
	// 2-1. 카드의 번호를 입력
	// 3. 상근이가 가지고 있는 카드를 알기 위한 개수 입력
	// 3-1. 상근이 카드를 알기위한 카드 의 번호 입력
	// 3-2. 상근이 카드의 숫자를 입력
	//처리
	// 
	//출력
	int N = 0;
	cin >> N;

	vector <int> vec;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	int M = 0;
	cin >> M;

	vector <int> vec2;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;
		
		int count_num = count(vec.begin(), vec.end(), num);
		//erase는 컨테이너의 실제 객체를 제거한다. 공간까지 지움
		//remove는 원소를 한칸 씩 당겨서 덮어씌움. 공간은 안지움
		//erase와 remove를 같이 사용함으로써 원소를 지우고 마지막 공간을 없애주는 작업을 한다.
		vec.erase(remove(vec.begin(), vec.end(), num), vec.end());
		
		vec2.push_back(count_num);
	}
	
	for (int i = 0; i < vec2.size(); i++)
	{
		if (i == vec2.size() - 1)
		{
			cout << vec2[i];
		}
		else
		{
			cout << vec2[i] << " ";
		}
	}

	return 0;
}