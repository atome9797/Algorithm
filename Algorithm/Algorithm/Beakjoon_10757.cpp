#include <iostream>

using namespace std;
int main()
{
	/*
		����
			1. �� ������ ���� ���
		�Է�
			1. �� ������ �迭���·� �Է¹޴´�.
		ó��
			1. �Է� ���� �迭�� �ø��ϴ� ������� �����ش�.
		���
	*/

	char A[10000];
	char B[10000];
	char C[10000];

	cin >> A;
	cin >> B;

	int array_a = 0;
	int array_b = 0;

	for (int i = 0; A[i] != '\0'; i++)
	{
		array_a++;
	}

	for (int i = 0; B[i] != '\0'; i++)
	{
		array_b++;
	}

	//�����ϴ� �κ�
	if (array_a > array_b) {
		int upCount = 0;
		for (int i = 0; i < array_a; i++)
		{
			int num = A[i] - '0';
			int num2 = B[i] - '0';

			C[i] = ((num + num2 + upCount) % 10) + '0';
			upCount = (num + num2 + upCount) / 10;

		}
	}
	else {
		for (int i = 0; i < array_b; i++)
		{

		}
	}

	

	cout << A << endl;
	cout << B << endl;
	

	cout << "�հ�" << C << endl;


	return 0;
}