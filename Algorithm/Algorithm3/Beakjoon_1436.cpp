#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// ����
	// 1. 666�� �� ������ ���ڸ� ���� ������� �̾����� N��° ������ ���ڸ� ����Ͻÿ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. ��ȭ ������ ���� ���� moveNum �� �����Ѵ�.
	// 3. �� ��° ��ȭ���� ī��Ʈ���� ������ �����Ѵ�.
	// ó��
	// 1. ī��ƮȽ���� �Է��� N�� �ٸ������� �ݺ����� ������.
	// 2. moveNum �� +1���ش�. moveNum�� temp�̶�� �ӽð�ü�� �������ش�.
	// 3. temp�� 0�� �ƴҶ����� �ݺ����ش�.
	// 4. temp �� 1000���� ���� �������� 666�̸� ī��Ʈ���ش�. �׸��� ������.
	// 5. temp�� 10���� ������.
	// ���
	//

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int moveNum = 0;
	int countNum = 0;
	int temp = 0;

	cin >> N;

	while (N != countNum)
	{
		moveNum++;
		temp = moveNum;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				countNum++;
				break;
			}
			else
			{
				temp = temp / 10;
			}
		}

	}
	
	cout << moveNum;


	return 0;
}