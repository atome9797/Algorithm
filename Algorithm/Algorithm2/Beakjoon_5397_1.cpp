#include <iostream>
#include <list>

using namespace std;

int main()
{
	//문제
	// 1. 강산이의 비밀번호를 알아내는 프로그램을 작성하시오. (알파벳 대문자, 소문자, 숫자, 백스페이스, 화살표)
	// 입력
	// 1. 테스트 케이스를 입력한다.
	// 2. 테스트 케이스 만큼 반복문을 돌린다.
	// 2-1. 강산이의 입력을 받는다.
	// 2-1-1. 강산이가 백스페이스를 입력했다면 - 가 주어진다.
	// 2-1-2. 커서 바로앞에 글자가 존재한다면 그 글자를 지운다.
	// 2-1-3. 화살표 입력하면 < , >로 주어진다. 
	// 2-1-3-1. 이때 커서의 위치를 움직일수 있다면, 왼쪽 또는 오른쪽으로 1 만큼 움직인다.
	// 2-1-4. 만약 커서의 위치가 줄의 마지막이 아니라면 커서 및 커서 오른쪽에 잇는 모든 문자는 오른쪽 한탄 이동한다.
	// 처리
	// 출력
	
	int test_case = 0;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		list<char> list1;
		list<char>::iterator iter = list1.end();

		while (1)
		{
			char a = cin.get(); //a에 입력한 문자 
			int key = a;
			
			
			//엔터
			if (key == 13)
			{
				break;
			} //백스페이스
			else if (key == 8)
			{
				if (iter != list1.begin())
				{
					iter = list1.erase(--iter); //특정 시점의 포인터 노드를 삭제함
				}
			}// < 
			else if (key == 60)
			{
				if (iter != list1.begin())
				{
					--iter; //이전 노드 주소를 받음
				}
			}// >
			else if (key == 62)
			{
				if (iter != list1.end())
				{
					++iter; //다음 노드 주소를 받음
				}
			}
			//기타
			else
			{
				list1.insert(iter, (char)key); //특정 지점의 포인터 노드를 추가함
			}

		}

		//-앞에 글자 있으면 삭제
		//<>로 커서 움직이기
		
		for (list<char>::iterator iter = list1.begin(); iter != list1.end(); iter++)
		{
			cout << *iter;
		}
		cout << "\n";
	}

	return 0;
}