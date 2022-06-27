#include <iostream>
#include <vector>
#include <string>

using namespace std;


//cin �� char �迭, double ��, int���� ������ �ִ�.
string s1, s2, temp; //�迭�� �뷮�� �Է����� �ʾƵ��� => ���� �޸�
int num1[10001];
int num2[10001];


int main()
{
	
	/*
		�� ���� A�� B�� �Է¹��� ���� A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*/
	
	cin >> s1 >> s2;
	int sum;
	vector <int> vec;

	//�� ����� s1���� �ޱ�
	if (s1.size() < s2.size()) 
	{
		temp = s1;
		s1 = s2;
		s2 = temp;
	}

	//num1, num2 �迭 ����� ����
	//�迭�� �� ���ڸ��� �ø����� ���� 1�� �߻��Ҽ� �ֱ� ������ ����ش�.
	for (int i = 0; i < s1.size(); i++)
	{
		num1[i + 1] = s1[i] - '0'; 
	}

	for (int i = 0; i < s2.size(); i++)
	{
		num2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0'; 
		//�� �迭�� ������ ���� ������������ �� ���ڸ� ���� �ݺ������� ���� �迭�� �������ֱ� ����
		//���� �ڸ��� ���� �ش�.
	}
	
	for (int i = s1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum > 10)
		{
			num1[i - 1]++;//���ڸ��� +1 ���ش�.
			sum -= 10;// 10�̻��̸� 10�� �������ν� ���������� ���Ҽ� �ִ�.
		}
		vec.push_back(sum);
	}

	//���ڸ� + 1�� �� ���ڸ� ���� 1�� �ö����� 1��µǰ� �Ѵ�.
	if (num1[0] != 0)
	{
		cout << 1;
	}
	
	//���Ͱ��� �Ųٷ� ������ش�.
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i];
	}

	return 0;
}