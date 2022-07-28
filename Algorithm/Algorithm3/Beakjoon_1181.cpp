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
	// 1. ������ ����
	// �Է�
	// 1. N�� �Է� �޴´�.
	// ó��
	// 2. sort�� �̿��ؼ� �����Ѵ�.
	// ���
	//

	set<pair<int, string>> set1;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;

		set1.insert({ str.size() , str });
	}

	for (set<pair<int, string>>::iterator iter = set1.begin(); iter != set1.end(); iter++)
	{
		pair<int, string> p1 = *iter;

		cout << p1.second << "\n";
	}

	return 0;
}