#include <iostream>
#include <string>
#include <list>

using namespace std;


int main()
{
	//0. ����� �ӵ��� ����Ų��.
	/*ios_base::sync_with_stdio �� c�� stdio�� cpp�� iostream�� ����ȭ�����ִ� ������ �ϴµ�, �� �� iostream�� stdio�� ���۸� ��� ����ϱ� ������ �����̰� �߻��մϴ�.
	  ios_base::sync_with_stdio(false); �ڵ带 �ۼ��������ν� ����ȭ�� ��Ȱ��ȭ�����ݴϴ�.
�̷� ����, c++���� �������� ���۰� �����Ǿ� c�� ���ۿ� �����Ͽ� ����� �� ���� ������, ����ϴ� ������ ���� �پ����� ������ ���� �ӵ��� �������� �˴ϴ�.
		=> �˰��� Ǯ���� �̱۾����� ȯ���̱� ������, ios_base::sync_with_stdio(false)����ص� ����

		cin�� cout�� �����ֱ� ������ Ǯ����� �Ѵ�.
		C++������ �⺻������ cin, cerr ��Ʈ���� cout ��Ʈ���� �����ֱ�(tie) ������ ����� ������ �ϱ����� ��� ��Ʈ�� ���۸� �÷���(flush)�Ѵ�. �� �����ִ� ���� �����ϱ� ���� cin ������Ʈ�� �Լ� tie�� NULL�� �������ν� ��½�Ʈ������ ���������� �����Ѵ�.

	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1. ���ڿ��� �Է� �޴´�.
	string s;
	cin >> s;

	//2. ��ɾ��� ������ �Է� �޴´�.
	int M;
	cin >> M;


	//3. ��ɾ ó���Ѵ�.
	list <char> lst(s.begin(), s.end());
	list <char>::iterator cursor = lst.end();

	//string::size_type cursor = s.size() - 1; //������ �ε���
	//string::iterator cursor;

	while (M--)
	{
		//3-1. ��ɾ �Է� �޴´�.
		char op;
		cin >> op;

		//3-2. �� ��ɾ �°� �����Ѵ�.
		switch (op)
		{
		case 'L':
			if (cursor != lst.begin())
			{
				--cursor;
			}
			
			break;
		case 'D':
			if (cursor != lst.end())
			{
				++cursor;
			}

			break;
		case 'B':
			//������ ������ Ŀ�� ��ġ ������Ʈ �ʿ���
			if (cursor != lst.begin())
			{
				--cursor;
				cursor = lst.erase(cursor); //�ݺ��ڴ� ��ȿȭ �ɼ� �ֱ� ������, ��ȯ���� �޾ƾ� �Ѵ�.
			}
			break;
		case 'P':
			char param;
			cin >> param;

			cursor = lst.insert(cursor, param);
			++cursor;
			break;
		}
	}

	//4. ���
	for (list<char>::iterator iter = lst.begin(); iter != lst.end(); iter++)
	{
		cout << *iter;
	}

}