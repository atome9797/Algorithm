#include <iostream>
#include <vector>

using namespace std;

int num[10000001][2] = {0};

int main()
{

	//����
	// 1. ����̰� ������ �ִ� ����ī���� ������ ���Ͻÿ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������ ���ڵ��� �Է� �޴´�.
	// 3. M�� �Է� �޴´�.
	// 4. M��ŭ �ݺ����� ������ ���ڵ��� �Է� �޴´�.
	// ó��
	// 1. M��ŭ �ݺ����� ������ ���ڵ��� ����� �Է� �޴°� ���ڵ��� ī��Ʈ�� ���� �迭�� N��ƴ �ݺ��� ������ ���� �����ص� �迭�� ���� �ҷ����� ������ ����Ѵ�.
	// ���
	//
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;

		if (input >= 0)
		{
			num[input][0] += 1;
		}
		else
		{
			int test = input * (- 1);
			num[test][1] += 1;
		}
	}

	int M = 0;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input2 = 0;
		cin >> input2;
		
		if (input2 >= 0)
		{
			cout << num[input2][0] << " ";
		}
		else
		{
			int test = input2 * (-1);
			cout << num[test][1] << " ";
		}
	}

	return 0;
}