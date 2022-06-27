#include <iostream>
#include <string>

using namespace std;

int main() {
	//1152
	//목표 : 문자열에 들어간 단어 갯수 구하기 (문자 아님 단어임) => fgets 사용
	//입력 :
	// 1. 문자열 str 을 입력 받는다. (1000000) , count 정수를 선언한다.
	//char logic_str[1000001];
	int logic_count100 = 0;
	
	string logic_str;
	getline(cin, logic_str);
	
	
	//처리 :
	// 2. 문자열 str을 반복문 돌린다.
	// 2-1. 문자가 공백이면 count 해준다.
	// 3. 맨 앞 자리와 맨 뒷자리가 공백이면 -1 count 해준다.
	for (int i = 0; i < logic_str.size(); i++) {
		if (logic_str[i] == ' ') {//strlen에 null 까지 포함됨
			logic_count100 += 1;
		}
	}

	if (logic_str[0] == ' ') {
		logic_count100 -= 1;
	}
	if (logic_str[logic_str.size() - 1] == ' ') {
		logic_count100 -= 1;
	}

	//출력 :
	printf("%d\n", logic_count100 + 1);
	return 0;
}