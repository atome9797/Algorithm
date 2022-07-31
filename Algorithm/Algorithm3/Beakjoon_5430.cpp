#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, p;
	bool FR, err;
	string str, numline; //��ɾ�, ���� �迭

	cin >> T;
	int i;

	while (T--) {
		deque<int> dq;
		FR = true;
		err = false;
		cin >> str >> p >> numline;
		i = 1;
		while (numline[i] != '\0') {
			int x = 0;
			while (numline[i] >= '0' and numline[i] <= '9') {
				x *= 10;
				x += int(numline[i] - '0');
				i++;
			}
			if (x != 0) {
				dq.push_back(x);
			}
			i++;
		}

		i = 0; //���� �� �Ҵ��ϱ� ������ �޸� �Ʊ��ٰ� �Ǵ��ؼ� ���� �ʱ�ȭ
		while (str[i] != '\0') { //���⼭ ���ڿ� �Ǻ�
			if (str[i] == 'R') {
				FR = !FR;
			}
			else if (str[i] == 'D') {
				if (dq.empty()) { //deque�� ��������� D��ɾ ������ error�߻�
					cout << "error" << endl;
					err = true;
					break;
				}
				if (FR) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
			i++;
		}

		//����ϴ� �κ� error ���ο� ���� '[',']'��ȣ�� ������� �Ǵ�
		if (!err) {
			cout << "[";
		}
		while (!dq.empty()) {
			if (FR) {
				auto c = dq.front();
				dq.pop_front();
				cout << c;
			}
			else {
				auto c = dq.back();
				dq.pop_back();
				cout << c;
			}
			if (!dq.empty()) {
				cout << ",";
			}
		}
		if (!err) {
			cout << "]" << endl;
		}
	}
}