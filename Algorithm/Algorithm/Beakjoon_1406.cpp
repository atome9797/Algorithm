#include <iostream>
#include <list>

using namespace std;

char editor[100005] = { 0 };

int main()
{
	//문제 
	// 1. 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오.
	// 입력
	// 1. 영어 소문자로 이루어진 문자열 입력 100,000
	// 2. 입력할 명령어 개수 입력 500,000
	// 3. 명령어를 입력(P의 경우 어떤 글자를 받을지 입력 받아야함)
	// 처리
	// 1. list를 사용해 시간 복잡도를 줄인다.
	// 
	// 출력
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
	//iter = list1.erase(iter); //마지막 요소 삭제함
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

	
	list<char>::iterator iter = list1.end(); //끝 주소를 받음
	
	for (int i = 0; i < count; i++)
	{
		char input;
		cin >> input;
		
		if (input == 'L')
		{
			if (iter != list1.begin())
			{
				--iter; //이전 노드 주소를 받음
			}
		}
		else if (input == 'D')
		{
			if (iter != list1.end())
			{
				++iter; //다음 노드 주소를 받음
			}
		}
		else if (input == 'B')
		{
			if (iter != list1.begin())
			{
				iter = list1.erase(--iter); //특정 시점의 포인터 노드를 삭제함
			}
		}
		else if (input == 'P')
		{
			char input_next;
			cin >> input_next;
			iter = list1.insert(iter, input_next); //특정 지점의 포인터 노드를 추가함
			++iter;
		}
	}

	for (list<char>::iterator iter = list1.begin(); iter != list1.end(); iter++)
	{
		cout << *iter;
	}


}