#include <iostream>

using namespace std;


int main()
{

	//���� ���� ����
	//5ų�θ� Ȱ���� Ƚ���� �� �������� 3���� �������� ������ ����Ѵ�.
	//�� ���� ���� 5ų�� Ƚ�� -1 ����
		//3ų�ε� �ȳ������� -1

	int sugar = 0;
	cin >> sugar;

	int sugar_5 = sugar / 5;//5ų�η� ���� �� Ƚ���� ���Ѵ�.
	int sugar_3 = 0;

	while (true)
	{
		//0�϶� ���� ����ϰ� -1 ���� ������� �ʴ´�.
		if (sugar_5 < 0)
		{
			cout << -1 << "\n";
			return 0; //���� �������ν� ���� �Լ��� ������.
		}

		//5������ �ִ��� ����ϸ鼭 3������ ����� �ּ� ������ ���Ҽ� �ִ�.
		if ((sugar - (5 * sugar_5)) % 3 == 0)
		{
			sugar_3 = (sugar - (5 * sugar_5)) / 3;
			break;
		}
		sugar_5--;
	}
	
	cout << sugar_5 + sugar_3 << "\n";

	return 0;
}