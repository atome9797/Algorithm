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
	Node* _root = nullptr;//구조체 선언

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
	//문제
	// 1. 전위 순회한 결과값을 후위 순회의 결과로 바꾸어 출력하라
	// 2. 뿌리 노드보다 작은 거는 왼쪽, 큰거는 오른쪽에 삽입하는 순서
	// 3. 입력을 할 때 마다 후위 순회 결과로 출력되게 갱신해준다.
	// 입력
	// 1. 입력값을 받는다.
	// 2. 노드 구조체의 포인터를 선언한다. null로 초기화
	// 처리
	// 1. while문으로 돌려 입력을 받는다. while문 돌릴때 cin쓰고 싶으면 while문에서 쓰고 
	// 조건문으로 eof만나면 break로 설정해준다.
	// 2. 입력값을 insert함수에 넣어주고 node주소도 함께 넘겨준다.
	// 3-1. 입력값이 초기값이면 루트로 지정한다.
	//		새로운 노드객체를 생성하고 그 노드의 데이터에 입력값을 넣어준다.
	//		그리고 초기값이기 때문에 left와 right는 null로 정의한다.
	// 3-2. 입력값이 초기값이 아니면 
	// 3-2-1.  입력값과 노드안의 데이터의 값의 크기를 비교하고 노드의 left, right포인터에 insert함수 를 할당한다. => 재귀적으로 들어가게 한다. 
	// 3-2-2. insert 함수를 node* 포인터로 반환하여 값을 갱신해준다.  
	// 3-3. root는 계속 root포인터를 가지고 있으므로, 후위순회로 출력가능하다.
	// 3-3-1. 후위 순회의 경우 오른쪽과 왼쪽이 둘다 널일때 데이터를출력할수 있다.
	// 출력
	//https://imnotabear.tistory.com/224

	int input = 0;


	//입력 하고 싶은 만큼 반복해서 입력할수있음 그리고 결과값이 while 안에 존재하게됨
	while (scanf("%d", &input) != EOF) { 
		insert(input);
	}



	return 0;
}