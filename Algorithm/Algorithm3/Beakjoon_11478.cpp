#include <iostream>
#include <set>

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

	int level = 1;
	
	set<string> set1;

	while (level <= S.size())
	{
		int test = level;
		string str;
		for (int i = 0; i < S.size();) //0 ~ 4
		{
			str += S[i];
			if (i + 1 == test)
			{
				i = test;
				test += level;
				set1.insert(str);
				str = "";
				//i���� ī��Ʈ�ؼ� �÷���
			}
			else
			{
				i++;
			}
		}
		level++; //0 ~ 4
	}

	cout << set1.size() << "\n";



	return 0;
}