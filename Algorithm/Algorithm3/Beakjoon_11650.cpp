#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// ����
	// 1. x��ǥ, y��ǥ �� �����ϴ� ������� ����϶�
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������ x, y��ǥ�� �Է� �޴´�.
	// ó��
	// 1. sort ���� �Ἥ ���Ľ�Ų��.
	// ���
	//

	multiset<pair<int, int>> set;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X = 0;
		int Y = 0;
		cin >> X >> Y;

		set.insert({ X, Y });
	}

	//sort(set.begin(), set.end());
	for (multiset<pair<int, int>>::iterator iter = set.begin(); iter != set.end(); iter++)
	{
		pair<int, int> p1 = *iter;
		cout << p1.first << " " << p1.second << "\n";
	}


	/*for (pair <int, int> p1 : set)
	{
		cout << p1.first << " " << p1.second << "\n";
	}*/

	return 0;
}