#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main()
{

	//
	// ����
	// 1. ���� M���� �־������� �̼��� ����ī�带 ����̰� ������ �ִ��� �������� ���Ͻÿ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������ ���ڸ� �Է� �޴´�. (�ߺ� ����)
	// 3. M�� �Է� �޴´�.
	// 4. M ��ŭ �ݺ����� ������ ���ڸ� �Է� �޴´�. 
	// 4-1. 
	// 
	// ���
	//
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int M = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;
		if (binary_search(vec.begin(), vec.end(), num))
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}


	return 0;
} 