#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//for (char ch : input)
	//{
	//	//�����̳ʿ� �����͸� �����ϰų� �����ϸ� �ȵ�
	//}

	int testCase;
	cin >> testCase;
	while (testCase--)
	{

		//1.���ڿ��� �Է� �޴´�.
		string input;
		cin >> input;
		//2. �����̳� 2���� �����.
		//�ϳ��� Ŀ�� ������ �����ϴ� ���ڿ��� ���������� ����
		// �ٸ� �ϳ��� Ŀ�� �������� �����ϴ� ���ڿ��� ���������� ����
		vector<char> left, rightReversed;

		//3. �� ���ڸ� �����ϰ� ó���Ѵ�.
		//���ĺ� ��ҹ���, ���� , �齺���̽�(-), ȭ��ǥ (<>)
		for (char ch : input)
		{
			switch (ch)
			{
			case '<' :
				if (false == left.empty())
				{
					rightReversed.push_back(left.back());
					left.pop_back();
				}
				break;
			case '>':
				if (false == rightReversed.empty())
				{
					left.push_back(rightReversed.back());
					rightReversed.pop_back();
				}
				break;
			case '-':
				if (false == left.empty())
				{
					left.pop_back();
				}
				break;
			default:
				left.push_back(ch);
				break;

			}
		}

		//rightReversed�� �Ųٷ� ����ϴ� ������ �Է½� left �� ���� �ϴ� ��Ҹ� �ݴ� ������� �����ϱ� ������ ��½ô� �ݴ�� ����Ѵ�.
		cout << string(left.begin(), left.end()) << string(rightReversed.rbegin(), rightReversed.rend()) << "\n"; //endl �� flush�۾����� �����ϱ� ������ ������

	}
}