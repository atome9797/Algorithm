#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//����
	// 1. ����̰� ��� ī�带 ������ �ִ��� ���Ͻÿ�
	//�Է�
	// 1. ����̰� ������ �ִ� ī�� ���� �Է�
	// 2. ī�� ������ŭ �ݺ��� 
	// 2-1. ī���� ��ȣ�� �Է�
	// 3. ����̰� ������ �ִ� ī�带 �˱� ���� ���� �Է�
	// 3-1. ����� ī�带 �˱����� ī�� �� ��ȣ �Է�
	// 3-2. ����� ī���� ���ڸ� �Է�
	//ó��
	// 
	//���
	int N = 0;
	cin >> N;

	vector <int> vec;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		vec.push_back(num);
	}

	int M = 0;
	cin >> M;

	vector <int> vec2;
	for (int i = 0; i < M; i++)
	{
		int num = 0;
		cin >> num;
		
		int count_num = count(vec.begin(), vec.end(), num);
		//erase�� �����̳��� ���� ��ü�� �����Ѵ�. �������� ����
		//remove�� ���Ҹ� ��ĭ �� ��ܼ� �����. ������ ������
		//erase�� remove�� ���� ��������ν� ���Ҹ� ����� ������ ������ �����ִ� �۾��� �Ѵ�.
		vec.erase(remove(vec.begin(), vec.end(), num), vec.end());
		
		vec2.push_back(count_num);
	}
	
	for (int i = 0; i < vec2.size(); i++)
	{
		if (i == vec2.size() - 1)
		{
			cout << vec2[i];
		}
		else
		{
			cout << vec2[i] << " ";
		}
	}

	return 0;
}