#include <iostream>

using namespace std;

int main()
{

	//����
	//1. nų�α׷� ���� ����Ҷ� ���� �ּҰ��� ���ϱ�
	//�Է�
	// 1. ������� �Է� Ű�θ� �޴´�.
	// 
	int sugar = 0;
	cin >> sugar;
	//ó��

	// 1. ������� �Է��� 5ų�� ������ �и��ϰ�, �������� 3ų�� ������ �и��Ѵ�.
	int sugar_5 = 0;
	int sugar_3 = 0;
	
	bool exist = true;

	//5�� ����� �켱���� �ΰ� �ݺ����� ���� -5 -3�� ���ֱ� (������ ���ϴ½�)
	while (sugar > 0)
	{
		
		if (sugar >= 5 && (sugar % 3 != 0 || sugar % 5 == 0))
		{
			sugar_5 += 1;
			sugar -= 5;
		}
		else if(sugar >= 3 && sugar % 3 == 0)
		{
			sugar_3 += 1;
			sugar -= 3;
		}
		else {
			exist = false;
			break;
		}

	}

	if (exist) {
		cout << sugar_5 + sugar_3 << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
	//���
}