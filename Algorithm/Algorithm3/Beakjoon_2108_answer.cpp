#include <iostream>
#include<cmath> 

using namespace std;

int search[10000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//���� 4000�� ���� �����Ƿ� -4000 ~ 4000���� ���̴�.
	int N = 0;
	int sum = 0;

	int Max = 0;
	int MaxNumber = -4000;
	int MinNumber = 987654321;
	//���� �ֺ󰪰� ���ο� �ֺ��� ��� �׸��� ��������
	int MaxCount = 0;
	int MaxCountTest = 0;
	int count = 0;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		search[num + 4000] += 1;
		sum += num;

		if (search[num + 4000] >= Max)
		{
			Max = search[num + 4000];
		}

		if (num >= MaxNumber)
		{
			MaxNumber = num;
		}
		if (num < MinNumber)
		{
			MinNumber = num;
		}

	}

	//������
	float everage = round((float)sum / N);
	if (everage == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << round((float)sum / N) << "\n";
	}

	//�߾Ӱ�
	for (int i = 0; i < 8005; i++)
	{
		if (search[i] != 0)
		{
			count += search[i];

			if (count >= (N / 2) + 1)
			{
				cout << i - 4000 << "\n";
				break;
			}
		}
	}

	for (int i = 0; i < 8005; i++)
	{
		if (search[i] == Max)
		{
			MaxCountTest++;
		}
	}


	for (int i = 0; i < 8005; i++)
	{
		if (search[i] == Max)
		{
			MaxCount++;
		}

		if (MaxCountTest >= 2)
		{
			if (search[i] == Max && MaxCount == 2)
			{
				cout << i - 4000 << "\n";
				break;
			}
		}
		else
		{
			if (search[i] == Max)
			{
				cout << i - 4000 << "\n";
				break;
			}
		}
	}

	//���� ���
	cout << MaxNumber - MinNumber << "\n";



	return 0;
}