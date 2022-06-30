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
	// 문제
	// 1. 전위 순회, 중위 순회, 후위 순회한 결과를 출력하는 프로그램을 작성하시오.
	// 입력
	// 1. 노드 개수 N을 입력 받는다.
	// 2. N만큼 반복문을 돌린다.
	// 3. 해당 노드 N과 자식 노드 M K 를 입력 받는다. (A가 루트 노드다)
	// 3-1. 자식 노드가 없는 경우에는 . 으로 표현한다.
	// 4. 노드의 좌우를 알기위해 구조체를 선언하고 구조체 배열을 만든다.
	// 4. 구조체 배열에 영어대문자를 넣는다.
	// 처리
	// 1.전위 순회와 중위 순회 후위 순회를 함수로 만든다.
	// 2. 왼쪽 오른쪽을 재귀함수로 구현한다.
	// 출력
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