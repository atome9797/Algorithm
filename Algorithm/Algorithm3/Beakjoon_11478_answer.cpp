#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// ����
	// 1. ���� �ٸ� �κ� ���ڿ� ������ ���ϴ� ���α׷��� �ۼ��϶�
	// �Է�
	// 1. ���ڿ� S�� �־�����.
	// ó��
	// 1. set ���������� ����� �ߺ����� ���ڿ��� �Է� �޴´�.
	// ���
	//

	string S;
	cin >> S;

	unordered_set<string> set1;

	for (int i = 0; i < S.size(); i++)
	{
		string str;
		for (int j = 0; j < S.size(); j++)
		{
			str += S[j];
			set1.insert(str);
		}
	}

	

	cout << set1.size() << "\n";



	return 0;
}