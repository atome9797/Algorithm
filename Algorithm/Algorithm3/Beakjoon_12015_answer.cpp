#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//벡터를 선언한다.
	//입력값보다 벡터의 최후 값이 작으면 삽입하고
	//아니면 입력값이 최후에 등장하는 위치에서(lower_bound 사용) 삽입해주는 방식 사용
	//그리고 벡터 배열 사이즈 가져오기

	vector<int> vec;
	vec.push_back(0);
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		//value가 가장 큰값이면 새로운 인덱스 생성 
		if (num > vec.back())
		{
			vec.push_back(num);
		}
		else
		{
			//value가 없다면, value보다 큰 값중에서 가장 작은 값을 반환
			//value가 가장 큰값이면 새로운 인덱스 생성하지만 위에서 조건으로 빼주기 때문에 그럴일은 없음
			int index = lower_bound(vec.begin(), vec.end(), num) - vec.begin();

			vec[index] = num;
		}
	}

	cout << vec.size() -1;
	

	return 0;
}