#include <iostream>
#include <deque>

using namespace std;

int main()
{

	//
	// ����
	// 1. N ���� ����� ���� K��° ����� �����ϴ� ��Ģ�� ������
	// �Է�
	// 1. N��� K��°�� �Է¹޴´�.
	// ó��
	// 1. while���� ���� ť�� ����� 1�� �ɶ� ���� �ݺ��Ѵ�.
	// 2. K ��° ��ŭ �̵��ϱ� ���� K �� 
	// ���
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	deque<int> dq;
	
	int K = 0;
	int N = 0;

	cin >> N >> K;
	
	//1,2,3,4,5
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	deque<int>::iterator iter = dq.begin();

	int count = 1;

	cout << "<";
	
	while (1)
	{

		if (dq.size() == 1)
		{
			cout << *iter << ">";
			break;
		}


		if (count % K == 0)
		{
			cout << *iter << ", ";
			iter = dq.erase(iter);
			count = 1;
		}
		
		if (iter == dq.end())
		{
			iter = dq.begin();
		}

		if (K != 1)
		{
			iter++;
		}
		count++;


		if (iter == dq.end())
		{
			iter = dq.begin();
		}
			
	}
	
	
	

	return 0;
}