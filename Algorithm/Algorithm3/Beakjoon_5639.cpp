#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


Node* insert(Node* root, int value)
{
	//�ʱⰪ�̸� ���ο� ��� �������ش�.
	if (root == nullptr)
	{
		root = new Node();
		root->data = value;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (root->data >= value) //value�� ������ left�� �ִ´�.
	{
		root->left = insert(root->left, value);
	}
	else
	{
		root->right = insert(root->right, value);
	}

	return root; //�ʱⰪ �׻�����
}

void endCicle(Node* root)
{
	if (root->left != nullptr)
	{
		endCicle(root->left);
	}

	if (root->right != nullptr)
	{
		endCicle(root->right);
	}

	cout << root->data << "\n";
}

int main()
{
	//
	//����
	// 1. ���� ��ȸ�� ������� ���� ��ȸ�� ����� �ٲپ� ����϶�
	// 2. �Ѹ� ��庸�� ���� �Ŵ� ����, ū�Ŵ� �����ʿ� �����ϴ� ����
	// 3. �Է��� �� �� ���� ���� ��ȸ ����� ��µǰ� �������ش�.
	// �Է�
	// 1. �Է°��� �޴´�.
	// 2. ��� ����ü�� �����͸� �����Ѵ�. null�� �ʱ�ȭ
	// ó��
	// 1. while������ ���� �Է��� �޴´�. while�� ������ cin���� ������ while������ ���� 
	// ���ǹ����� eof������ break�� �������ش�.
	// 2. �Է°��� insert�Լ��� �־��ְ� node�ּҵ� �Բ� �Ѱ��ش�.
	// 3-1. �Է°��� �ʱⰪ�̸� ��Ʈ�� �����Ѵ�.
	//		���ο� ��尴ü�� �����ϰ� �� ����� �����Ϳ� �Է°��� �־��ش�.
	//		�׸��� �ʱⰪ�̱� ������ left�� right�� null�� �����Ѵ�.
	// 3-2. �Է°��� �ʱⰪ�� �ƴϸ� 
	// 3-2-1.  �Է°��� ������ �������� ���� ũ�⸦ ���ϰ� ����� left, right�����Ϳ� insert�Լ� �� �Ҵ��Ѵ�. => ��������� ���� �Ѵ�. 
	// 3-2-2. insert �Լ��� node* �����ͷ� ��ȯ�Ͽ� ���� �������ش�.  
	// 3-3. root�� ��� root�����͸� ������ �����Ƿ�, ������ȸ�� ��°����ϴ�.
	// 3-3-1. ���� ��ȸ�� ��� �����ʰ� ������ �Ѵ� ���϶� �����͸�����Ҽ� �ִ�.
	// ���

	int input = 0;


	//�Է� �ϰ� ���� ��ŭ �ݺ��ؼ� �Է��Ҽ����� �׸��� ������� while �ȿ� �����ϰԵ�
	Node* root = nullptr;
	while (cin >> input) {
		if (input == EOF)
		{
			break;
		}
		root = insert(root, input);
	}

	endCicle(root);


	return 0;
}