#include <iostream>

using namespace std;

int main()
{


	bool sosu[1005] = { false };

	//�Ҽ� �迭 ����� => �Ҽ� �϶� true �� ���� �Ѵ�.
	// 1-1. �Ҽ� �� ��Ģ�� �����Ѵ�.
	// 1-2. �Ҽ��� 1�� �ڱ� �ڽ� �̿ܿ� ����� ������ �ʴ� ���� �̾߱� �Ѵ�.
	for (int sosuNum = 2; sosuNum <= 1000; sosuNum++)
	{
		bool exist = true;
		for (int j = 2; j <= 1000; j++)
		{
			//�Ҽ��� �ƴҶ� false
			if (sosuNum != j && sosuNum % j == 0)
			{
				exist = false;
			}
		}

		if (sosuNum == 2) {
			exist = true;
		}
		sosu[sosuNum] = exist;
	}

	for (int i = 0; i < 100; i++)
	{
		if (sosu[i])
		{
			cout << i << endl;
		}
	}

	
	//����
	// �Է�
	// 1. ù �ٿ� ���� n�� �Է� �޴´�.
	// 2. n���� ����ŭ ���ڸ� �Է��Ѵ�.
	int n = 0;
	cin >> n;


	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;

		// ó��	
		// 1. n���� �Է� �����߿� �Ҽ��� ������ ����.
		//�Ҽ��� ī��Ʈ ���ش�.
		if (sosu[num])
		{
			count++;
		}
	}

	// ���
	// 1. ���� �Ҽ��� ������ ��� �Ѵ�.
	cout << count;

}
