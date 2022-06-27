#include <iostream>
#include <string>
#include <list>

using namespace std;


int main()
{
	//0. 입출력 속도를 향상시킨다.
	/*ios_base::sync_with_stdio 는 c의 stdio와 cpp의 iostream을 동기화시켜주는 역할을 하는데, 이 때 iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생합니다.
	  ios_base::sync_with_stdio(false); 코드를 작성해줌으로써 동기화를 비활성화시켜줍니다.
이로 인해, c++만의 독립적인 버퍼가 생성되어 c의 버퍼와 병행하여 사용할 수 없게 되지만, 사용하는 버퍼의 수가 줄어들었기 때문에 실행 속도는 빨라지게 됩니다.
		=> 알고리즘 풀때는 싱글쓰레드 환경이기 때문에, ios_base::sync_with_stdio(false)사용해도 무관

		cin과 cout이 묶여있기 때문에 풀어줘야 한다.
		C++에서는 기본적으로 cin, cerr 스트림과 cout 스트림이 묶여있기(tie) 때문에 입출력 동작을 하기전에 출력 스트림 버퍼를 플러쉬(flush)한다. 이 묶여있는 것을 해제하기 위해 cin 오브젝트의 함수 tie에 NULL을 넣음으로써 출력스트림과의 묶여있음을 해제한다.

	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//1. 문자열을 입력 받는다.
	string s;
	cin >> s;

	//2. 명령어의 개수를 입력 받는다.
	int M;
	cin >> M;


	//3. 명령어를 처리한다.
	list <char> lst(s.begin(), s.end());
	list <char>::iterator cursor = lst.end();

	//string::size_type cursor = s.size() - 1; //마지막 인덱스
	//string::iterator cursor;

	while (M--)
	{
		//3-1. 명령어를 입력 받는다.
		char op;
		cin >> op;

		//3-2. 각 명령어에 맞게 실행한다.
		switch (op)
		{
		case 'L':
			if (cursor != lst.begin())
			{
				--cursor;
			}
			
			break;
		case 'D':
			if (cursor != lst.end())
			{
				++cursor;
			}

			break;
		case 'B':
			//문자을 지운후 커서 위치 업데이트 필요함
			if (cursor != lst.begin())
			{
				--cursor;
				cursor = lst.erase(cursor); //반복자는 무효화 될수 있기 때문에, 반환값을 받아야 한다.
			}
			break;
		case 'P':
			char param;
			cin >> param;

			cursor = lst.insert(cursor, param);
			++cursor;
			break;
		}
	}

	//4. 출력
	for (list<char>::iterator iter = lst.begin(); iter != lst.end(); iter++)
	{
		cout << *iter;
	}

}