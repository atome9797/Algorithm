#include <iostream>
#include <list>

using namespace std;

int main()
{
	//����
	// 1. �������� ��й�ȣ�� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. (���ĺ� �빮��, �ҹ���, ����, �齺���̽�, ȭ��ǥ)
	// �Է�
	// 1. �׽�Ʈ ���̽��� �Է��Ѵ�.
	// 2. �׽�Ʈ ���̽� ��ŭ �ݺ����� ������.
	// 2-1. �������� �Է��� �޴´�.
	// 2-1-1. �����̰� �齺���̽��� �Է��ߴٸ� - �� �־�����.
	// 2-1-2. Ŀ�� �ٷξտ� ���ڰ� �����Ѵٸ� �� ���ڸ� �����.
	// 2-1-3. ȭ��ǥ �Է��ϸ� < , >�� �־�����. 
	// 2-1-3-1. �̶� Ŀ���� ��ġ�� �����ϼ� �ִٸ�, ���� �Ǵ� ���������� 1 ��ŭ �����δ�.
	// 2-1-4. ���� Ŀ���� ��ġ�� ���� �������� �ƴ϶�� Ŀ�� �� Ŀ�� �����ʿ� �մ� ��� ���ڴ� ������ ��ź �̵��Ѵ�.
	// ó��
	// ���
	
	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		list<char> list1;
		list<char>::iterator iter = list1.end();

		while (1)
		{
			char a = cin.get(); //a�� �Է��� ���� 
			int key = a;
			
			
			//����
			if (key == 13)
			{
				break;
			} //�齺���̽�
			else if (key == 8)
			{
				if (iter != list1.begin())
				{
					iter = list1.erase(--iter); //Ư�� ������ ������ ��带 ������
				}
			}// < 
			else if (key == 60)
			{
				if (iter != list1.begin())
				{
					--iter; //���� ��� �ּҸ� ����
				}
			}// >
			else if (key == 62)
			{
				if (iter != list1.end())
				{
					++iter; //���� ��� �ּҸ� ����
				}
			}
			//��Ÿ
			else
			{
				list1.insert(iter, (char)key); //Ư�� ������ ������ ��带 �߰���
			}

		}

		//-�տ� ���� ������ ����
		//<>�� Ŀ�� �����̱�
		
		for (list<char>::iterator iter = list1.begin(); iter != list1.end(); iter++)
		{
			cout << *iter;
		}
		cout << "\n";
	}

	return 0;
}