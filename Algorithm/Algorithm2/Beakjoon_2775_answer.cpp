#include <iostream>

using namespace std;

int department(int flow, int host)
{

	//0���� �ο����� 1 2 3 ������� �����༭ �ö�´�.

	if (flow == 0) //0���� ȣ���� �ο����� �����ش�.
	{
		return host; 
	}
	else if (host == 1) //������ 1ȣ�� 1���̹Ƿ� ���ϰ��� �����ȴ�.
	{
		return 1;
	}

	//���� ���� ���� ȣ���� , ���� ���� ���� ȣ���� ���� ���Ѵ�.
	return department(flow, host - 1) + department(flow - 1, host);
}

int main()
{

	//����Ʈ ��� �Լ��� Ǯ��
	//����ڰ� ������ ȣ���� �Է¹޴´�.
	int flow = 0;
	int host = 0;
	cin >> flow >> host;
	int sum = department(flow,host);
	cout << sum << endl;

	return 0;
}