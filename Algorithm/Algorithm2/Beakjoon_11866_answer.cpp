#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// 문제
	// 1. N 명의 사람들 에서 K번째 사람을 제거하는 규칙을 만들어라
	// 입력
	// 1. N명과 K번째를 입력받는다.
	// 처리
	// 1. while문을 돌려 큐의 사이즈가 1이 될때 까지 반복한다.
	// 2. K 번째 만큼 이동하기 위해 K 를 
	// 출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	deque<int> dq;
	
	int K = 0;
	int N = 0;

	cin >> N >> K;
	
	//1,2,3,4,5
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	deque<int>::iterator iter = dq.begin();

	int count = 1;

	cout << "<";
	
	while (1)
	{

		if (dq.size() == 1)
		{
			cout << *iter << ">";
			break;
		}


		if (count % K == 0)
		{
			cout << *iter << ", ";
			iter = dq.erase(iter);
			count = 1;
		}
		
		if (iter == dq.end())
		{
			iter = dq.begin();
		}

		if (K != 1)
		{
			iter++;
		}
		count++;


		if (iter == dq.end())
		{
			iter = dq.begin();
		}
			
	}
	
	
	

	return 0;
}