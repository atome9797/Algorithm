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

	int array[100] = { 0 };

	cin >> N >> M;

	int size = 0;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		array[i] = num;
		size++;
	}

	int updateNum = M;

	//카드가 2장이면 멈추기
	while (size >= 3)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k < j; k++)
				{
					if (M >= array[i] + array[j] + array[k])
					{
						if (updateNum > array[i] + array[j] + array[k])
						{
							updateNum = array[i] + array[j] + array[k];
						}
					}
				}
			}

		}


		//다 비교하고 갱신했으면 맨처음 배열 삭제
		array[size - 1] = 0;
		size--;
	}

	cout << updateNum << "\n";

	return 0;
}