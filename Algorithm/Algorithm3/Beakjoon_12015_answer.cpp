#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//���͸� �����Ѵ�.
	//�Է°����� ������ ���� ���� ������ �����ϰ�
	//�ƴϸ� �Է°��� ���Ŀ� �����ϴ� ��ġ����(lower_bound ���) �������ִ� ��� ���
	//�׸��� ���� �迭 ������ ��������

	vector<int> vec;
	vec.push_back(0);
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		//value�� ���� ū���̸� ���ο� �ε��� ���� 
		if (num > vec.back())
		{
			vec.push_back(num);
		}
		else
		{
			//value�� ���ٸ�, value���� ū ���߿��� ���� ���� ���� ��ȯ
			//value�� ���� ū���̸� ���ο� �ε��� ���������� ������ �������� ���ֱ� ������ �׷����� ����
			int index = lower_bound(vec.begin(), vec.end(), num) - vec.begin();

			vec[index] = num;
		}
	}

	cout << vec.size() -1;
	

	return 0;
}