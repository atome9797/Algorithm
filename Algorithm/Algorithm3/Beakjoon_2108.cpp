#include <iostream>
#include <set>
#include <cmath>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// ����
	// 1. N���� ���� �־������� �װ��� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ���� multiset�� ������ �Է� �޴´�.
	// ó��
	// 1. �ִ񰪰� �ּڰ��� �����ѵ� 
	// 2. N�� ���ݸ�ŭ �ݺ����� ���� �߾Ӱ��� ����Ѵ�.
	// ���
	//

	int N = 0;
	cin >> N;

	float sum = 0;
	multiset<int> ms;
	int mustCount = 0;
	int mustKey = 0;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		ms.insert(num); 
		
		if (ms.count(num) > mustCount)
		{
			mustKey = num;
			mustCount = ms.count(num);
		}
		else if (ms.count(num) == mustCount)
		{
			if (mustKey < num)
			{

			}
		}
		sum += num;
	}
	
	if (round((float)sum / N) == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << round((float)sum / N) << "\n";
	}

	int count = 0;
	for (multiset<int>::iterator iter = ms.begin(); iter != ms.end();)
	{
		if (count < N /2)
		{
			iter++;
		}
		else
		{
			cout << *iter << "\n";
			break;
		}

		count++;
	}

	cout << mustKey << "\n";

	multiset<int>::iterator iter1 = ms.begin();
	multiset<int>::iterator iter2 = ms.end();

	int Min = *iter1;
	int Max = *(--iter2);

	cout << Max - Min << "\n";


	return 0;
}