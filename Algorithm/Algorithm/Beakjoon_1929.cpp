#include <iostream>

int main()
{

	//
	// ����
	// 1.  M �̻� N������ �Ҽ��� ����ϴ� ���α׷��� �ۼ��ϱ�
	// �Է�
	// 1. M�� N�� �Է� �޴´�.
	int M = 0;
	int N = 0;
	std::cin >> M >> N;
	
	
	// ó��
	// 1. M�� N���̸� �ݺ����� ���� �Ҽ��� ���Ѵ�.
	for (int i = M; i <= N; i++)
	{
		bool exist = true;
		for (int j = 2; j <= i; j++)
		{
			//1�� �ڱ� �ڽ��� �ƴ� �ٸ����� �������� false
			if (i != j && i % j == 0)
			{
				exist = false;
				break;
			}
		}

		if (exist && i != 1) {
			std::cout << i << "\n";
		}
	}


	
	

	return 0;
}