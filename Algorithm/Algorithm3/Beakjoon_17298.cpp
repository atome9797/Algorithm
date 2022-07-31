#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> vec(1000001);
stack <int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// ����
	// 1. ���� A�� ������ index�� �ش��ϴ� ������ ū���� �����ʿ� ������ ���� ���ʿ� �ִ¼��� ���϶�
	// 2. ���� ��� -1�� ó���Ѵ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ vector�� �Է��Ѵ�.
	// ó��
	// 1. �Źݺ��� �������� stack�� ��ȣ�� �׾Ƶΰ� ���� �ݺ����� ��ȣ�� ���ؼ� ������ stack���� �����Ѵ�. 
	// 2. ū���� ������ ū���� ��� �迭�� ��Ƶΰ� , ������ -1�� ��Ƶд�.
	// ���
	// =
 	

	int N = 0;
	cin >> N;
	vector<int> result(N);
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= vec[i])
		{
			st.pop();
		}

		if (st.empty())
		{
			result[i] = -1;
		}
		else 
		{
			//ū���� �ִٴ� ���̹Ƿ� �־��ش�.
			result[i] = st.top();
		}

		st.push(vec[i]);
	}

	for (int element : result)
	{
		cout << element << " ";
	}

	return 0;
}