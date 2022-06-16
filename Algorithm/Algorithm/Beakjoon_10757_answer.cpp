#include <iostream>
#include <vector>
#include <string>

using namespace std;


//cin 는 char 배열, double 형, int형을 담을수 있다.
string s1, s2, temp; //배열의 용량을 입력하지 않아도됨 => 동적 메모리
int num1[10001];
int num2[10001];


int main()
{
	
	/*
		두 정수 A와 B를 입력받은 다음 A+B를 출력하는 프로그램을 작성하시오.
	*/
	
	cin >> s1 >> s2;
	int sum;
	vector <int> vec;

	//더 긴수를 s1으로 받기
	if (s1.size() < s2.size()) 
	{
		temp = s1;
		s1 = s2;
		s2 = temp;
	}

	//num1, num2 배열 만드는 과정
	//배열의 맨 앞자리는 올림으로 인한 1이 발생할수 있기 때문에 비워준다.
	for (int i = 0; i < s1.size(); i++)
	{
		num1[i + 1] = s1[i] - '0'; 
	}

	for (int i = 0; i < s2.size(); i++)
	{
		num2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0'; 
		//두 배열의 길이의 차를 더해준이유는 맨 끝자리 부터 반복문으로 돌려 배열에 저장해주기 위해
		//수의 자리를 맞춰 준다.
	}
	
	for (int i = s1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum > 10)
		{
			num1[i - 1]++;//윗자리에 +1 해준다.
			sum -= 10;// 10이상이면 10을 빼줌으로써 나머지값을 구할수 있다.
		}
		vec.push_back(sum);
	}

	//윗자리 + 1로 맨 윗자리 수가 1로 올라갔으면 1출력되게 한다.
	if (num1[0] != 0)
	{
		cout << 1;
	}
	
	//벡터값을 거꾸로 출력해준다.
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i];
	}

	return 0;
}