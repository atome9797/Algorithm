#include <iostream>
#include <set>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//
	// ����
	// 1. ��Ī �������� ������ ������ ����϶�.
	// �Է�
	// 1. ���� A�� B�� �Է� �޴´�.
	// 2. ���� A��ŭ �ݺ����� ���� ���Ҹ� �Է� �޴´�.
	// 3. ���� B��ŭ �ݺ����� ���� ���Ҹ� �Է� �޴´�. 
	// ó��
	// 1. ���� 2���� ���� set ������ �Է� �޴´�.
	// 2. B��ŭ ���Ҹ� �Է� ������ A�� �ߺ� ���� �ִ��� üũ�ϰ� ī��Ʈ �Ѵ�. => set�� �̺�Ž��
	// ���
	//
	int A, B;
	cin >> A >> B;

	set<int> set1;
	for (int i = 0; i < A; i++)
	{
		int num;
		cin >> num;
		set1.insert(num);
	}

	int mixCount = 0;
	for (int i = 0; i < B; i++)
	{
		int num;
		cin >> num;
		if (set1.find(num) != set1.end())
		{
			mixCount++;
		}
	}

	cout << A + B - mixCount * 2 << "\n";

	return 0;
}