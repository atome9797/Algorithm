#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct root
{
	char left;
	char right;
};

struct root roots[100];

void preOrder(char root)
{
	if (root =='.')
	{
		return;
	}
	else
	{
		cout << root;
		preOrder(roots[root].left);
		preOrder(roots[root].right);
	}
	
}

void middleOrder(char root)
{
	if (root == '.')
	{
		return;
	}
	else
	{
		middleOrder(roots[root].left);
		cout << root;
		middleOrder(roots[root].right);
	}

}


void endOrder(char root)
{
	if (root == '.')
	{
		return;
	}
	else
	{
		endOrder(roots[root].left);
		endOrder(roots[root].right);
		cout << root;
	}

}

int main()
{

	//
	// ����
	// 1. ���� ��ȸ, ���� ��ȸ, ���� ��ȸ�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	// �Է�
	// 1. ��� ���� N�� �Է� �޴´�.
	// 2. N��ŭ �ݺ����� ������.
	// 3. �ش� ��� N�� �ڽ� ��� M K �� �Է� �޴´�. (A�� ��Ʈ ����)
	// 3-1. �ڽ� ��尡 ���� ��쿡�� . ���� ǥ���Ѵ�.
	// 4. ����� �¿츦 �˱����� ����ü�� �����ϰ� ����ü �迭�� �����.
	// 4. ����ü �迭�� ����빮�ڸ� �ִ´�.
	// ó��
	// 1.���� ��ȸ�� ���� ��ȸ ���� ��ȸ�� �Լ��� �����.
	// 2. ���� �������� ����Լ��� �����Ѵ�.
	// ���
	// 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int N = 0;
	cin >> N;
	char elements, left, right;

	for (int i = 0; i < N; i++)
	{
		cin >> elements >> left >> right;
		roots[elements].left = left;
		roots[elements].right = right;
	}

	preOrder('A');
	cout << "\n";
	middleOrder('A');
	cout << "\n";
	endOrder('A');
	cout << "\n";
	

	return 0;
}