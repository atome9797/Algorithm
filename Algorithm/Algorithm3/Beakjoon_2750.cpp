#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;

int main()
{

	//
	// ����
	// 1. N���� ���� �־�������, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N�� ��ŭ �Է� �޴´�.
	// ó��
	// ���
	//

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << "\n";
	}

	return 0;
}