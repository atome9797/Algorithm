#include <iostream>
#include <list>

using namespace std;

char editor[100005] = { 0 };

int main()
{
	//���� 
	// 1. �����⿡ �ԷµǾ� �ִ� ���ڿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ���� �ҹ��ڷ� �̷���� ���ڿ� �Է� 100,000
	// 2. �Է��� ��ɾ� ���� �Է� 500,000
	// 3. ��ɾ �Է�(P�� ��� � ���ڸ� ������ �Է� �޾ƾ���)
	// ó��
	// 1. list�� ����� �ð� ���⵵�� ���δ�.
	// 
	// ���
	list<char> list1;

	//100000
	cin >> editor;
	//100000
	for (int i = 0; editor[i] != '\0'; i++)
	{
		list1.push_back(editor[i]);
	}
	
	int count = 0;
	cin >> count;

	//cout << *iter << endl;
	//iter = list1.erase(iter); //������ ��� ������
	//--iter;
	//iter = list1.erase(iter);
	//--iter;
	//iter = list1.erase(iter);
	//for (list<char>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
	//{
	//	cout << *iter << endl;
	//}
	
	//--iter;
	//list1.erase(iter);

	
	list<char>::iterator iter = list1.end(); //�� �ּҸ� ����
	
	for (int i = 0; i < count; i++)
	{
		char input;
		cin >> input;
		
		if (input == 'L')
		{
			if (iter != list1.begin())
			{
				--iter; //���� ��� �ּҸ� ����
			}
		}
		else if (input == 'D')
		{
			if (iter != list1.end())
			{
				++iter; //���� ��� �ּҸ� ����
			}
		}
		else if (input == 'B')
		{
			if (iter != list1.begin())
			{
				iter = list1.erase(--iter); //Ư�� ������ ������ ��带 ������
			}
		}
		else if (input == 'P')
		{
			char input_next;
			cin >> input_next;
			iter = list1.insert(iter, input_next); //Ư�� ������ ������ ��带 �߰���
			++iter;
		}
	}

	for (list<char>::iterator iter = list1.begin(); iter != list1.end(); iter++)
	{
		cout << *iter;
	}


}