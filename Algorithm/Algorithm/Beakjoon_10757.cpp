#include <iostream>

using namespace std;

//10�� 10������ 10001�� 10^2 => 100�̹Ƿ� 3�ڸ�������
char A[10001] = { 0 };
char B[10001] = { 0 };
char C[10001] = { 0 };
char a_alpha[10001] = { 0 };
char b_alpha[10001] = { 0 };

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

	
	cin >> A;
	cin >> B;

	int array_a = 0;
	int array_b = 0;
	int array_c = 0;

	for (int i = 0; A[i] != '\0'; i++)
	{
		array_a++;
	}


	int count = 0;
	for (int i = array_a -1 ; i >= 0; i--)
	{
		a_alpha[count] = A[i];
		count++;
	}

	for (int i = 0; B[i] != '\0'; i++)
	{
		array_b++;
	}

	int count2 = 0;
	for (int i = array_b - 1; i >= 0; i--)
	{
		b_alpha[count2] = B[i];
		count2++;
	}
	

	//�����ϴ� �κ�
	if (array_a >= array_b) {
		int upCount = 0;
		for (int i = 0; i < array_a; i++)
		{
			int num = a_alpha[i] - '0';
			int num2 = 0;
			if (b_alpha[i] == '\0')
			{
				num2 = b_alpha[i];
			}
			else
			{
				num2 = b_alpha[i] - '0';
			}

			C[i] = ((num + num2 + upCount) % 10) + '0';
			upCount = (num + num2 + upCount) / 10;

			//array_a�� ���̰� �ø��� �߻��ߴٸ� �ϳ� �� �־��ֱ�
			if (array_a - 1 == i && upCount == 1)
			{
				C[array_a] = upCount + '0';
			}

		}
	}
	else {
		int upCount = 0;
		for (int i = 0; i < array_b; i++)
		{
			int num = b_alpha[i] - '0';
			int num2 = 0;
			if (a_alpha[i] == '\0')
			{
				num2 = a_alpha[i];
			}
			else
			{
				num2 = a_alpha[i] - '0';
			}

			C[i] = ((num + num2 + upCount) % 10) + '0';
			upCount = (num + num2 + upCount) / 10;

			//array_a�� ���̰� �ø��� �߻��ߴٸ� �ϳ� �� �־��ֱ�
			if (array_b - 1 == i && upCount == 1)
			{
				C[array_b] = upCount + '0';
			}

		}
	}


	for (int i = 0; C[i] != '\0'; i++)
	{
		array_c++;
	}
	

	for (int i = array_c - 1; i >= 0; i--)
	{
		cout << C[i];
	}


	return 0;
}