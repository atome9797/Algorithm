#include <iostream>
#include <string>

using namespace std;

int main() {
	//1152
	//��ǥ : ���ڿ��� �� �ܾ� ���� ���ϱ� (���� �ƴ� �ܾ���) => fgets ���
	//�Է� :
	// 1. ���ڿ� str �� �Է� �޴´�. (1000000) , count ������ �����Ѵ�.
	//char logic_str[1000001];
	int logic_count100 = 0;
	
	string logic_str;
	getline(cin, logic_str);
	
	
	//ó�� :
	// 2. ���ڿ� str�� �ݺ��� ������.
	// 2-1. ���ڰ� �����̸� count ���ش�.
	// 3. �� �� �ڸ��� �� ���ڸ��� �����̸� -1 count ���ش�.
	for (int i = 0; i < logic_str.size(); i++) {
		if (logic_str[i] == ' ') {//strlen�� null ���� ���Ե�
			logic_count100 += 1;
		}
	}

	if (logic_str[0] == ' ') {
		logic_count100 -= 1;
	}
	if (logic_str[logic_str.size() - 1] == ' ') {
		logic_count100 -= 1;
	}

	//��� :
	printf("%d\n", logic_count100 + 1);
	return 0;
}