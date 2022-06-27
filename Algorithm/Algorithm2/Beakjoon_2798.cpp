#include <iostream>
#include <deque>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//문제
	// 1. N장의 카드에 숫자가 써있을때 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구하시오.
	// 입력
	// 1. N개의 카드 개수와 M숫자를 입력 받는다. (3개의 숫자 합은 M을 넘지 않는다.)
	// 2. N개의 카드 수만큼 숫자를 입력 받는다.
	// 3. 경우의 수를 구해 M의 숫자와 가장 가까운 숫자의 합인 데이터를 갱신하도록 한다.
	// 처리 
	// 1. deque를 사용하여 순환되는 숫자를 받을수 있게 함
	// 2. 순환 되는 숫자를 3개씩 담은뒤 3개의 합과 M을 비교한후 가까운 숫자면 갱신해주기
	// 3. 앞 자리 숫자로 다 조합했으면 삭제하고 다음 자리 숫라조 조합하기
	// 4. 최종적으로 비슷한 숫자를 출력하기
	// 출력
	//

	int N = 0;
	int M = 21;

	deque<int> deque1;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		deque1.push_back(num);
	}

	int updateNum = 0;

	//카드가 2장이면 멈추기
	while (deque1.size() >= 3)
	{
		int num = deque1.front();
		//다 비교하고 갱신했으면 맨처음 배열 삭제
		deque1.pop_front();


		for (int i = 0; i < deque1.size(); i++)
		{
			int num2 = deque1.front();
			deque1.pop_front();

			for (deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); iter++)
			{
				if (M >= num + num2 + *iter && updateNum < num + num2 + *iter)
				{
					updateNum = num + num2 + *iter;
				}
			}

			deque1.push_back(num2);
		}
	}

	cout << updateNum << "\n";

	return 0;
}