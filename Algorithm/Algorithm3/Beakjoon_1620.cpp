#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	//
	// ����
	// 1. ���ϸ��� ��ȣ�� ���� ���ϸ��� �̸��� ���ϴ� ������ �϶�
	// �Է�
	// 1. N�� M�� �Է¹޴´�.
	// ó��
	// 1. ���ڷθ� ������, ���ϸ� ��ȣ�� �ش��ϴ� ���ڸ� ����ؾ���.
	// 2. ���ĺ����� ������ ���ϸ� ��ȣ�� ���ؾ� �Ѵ�.
	// ���
	//
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> map;
	for (int i = 0; i < N + M; i++)
	{
		if (i < N)
		{
			string str = "";
			cin >> str;
			map.insert({ str, i});
		}
		else
		{
			
			string str = "";
			cin >> str;
		}
	}

	return 0;
}