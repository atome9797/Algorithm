#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//
	// ����
	// 1. N���� ���ڿ��� �̷���� ���� S�� �־�����.
	// 2. �Է����� �־����� M���� ���ڿ� �� ���� s�� ���ԵǾ� �ִ� ���� �� ����� ���Ͻÿ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������ ���ڿ��� �Է� �޴´�.
	// 3. M�� �Է� �޴´�.
	// 4. M��ŭ �ݺ����� ������ ���ڿ��� �Է� �޴´�.
	// ó��
	// 1. M��ŭ �ݺ����� ������ ���ڿ��� �Է� ������ N�� ���ڿ��� �ִ��� ������ �˻��Ѵ�.
	// 1-1. ������ ī��Ʈ ���ش�.
	// ���
	// 1. ī��Ʈ�� ���� ����Ѵ�.

	int N = 0;
	int M = 0;
	cin >> N >> M;

	vector<string> vec;

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		
		vec.push_back(str);
	}
	
	sort(vec.begin(), vec.end());
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		string str = "";
		cin >> str;

		if (binary_search(vec.begin(), vec.end(), str))
		{
			count++;
		}
	}


	cout << count;

	return 0;
}