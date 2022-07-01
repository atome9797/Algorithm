#include <stdio.h>
#include <queue>

class Set
{
public:
	Set() = default;
struct Node
{
	int data = 0;
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
};

private:
	int size = 0;
	Node* _root = nullptr;//����ü ����

};


using namespace std;

void insert(int root)
{
	Set st = new Set();
	if (_root == nullptr)
	{
		Node* newNode = new Node(root);
	}

	Node *preNode = _root;
	
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
	//https://imnotabear.tistory.com/224

	int input = 0;


	//�Է� �ϰ� ���� ��ŭ �ݺ��ؼ� �Է��Ҽ����� �׸��� ������� while �ȿ� �����ϰԵ�
	while (scanf("%d", &input) != EOF) { 
		insert(input);
	}



	return 0;
}