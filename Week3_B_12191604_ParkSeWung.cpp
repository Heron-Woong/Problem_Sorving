#include <iostream>
#include <vector>
using namespace std;

int sol(long long num) {
	int count = 0;
	int ch=0;
	vector<int> a;
	while (1) {
		ch = num % 10;
		a.push_back(ch); //�� �ڸ������� ������ �ش�
		num /= 10;
		if (num == 0) {
			a.push_back(0); //������ �ڸ����� �ø��� ���� �� �����Ƿ� �ϳ��� �� �߰��Ѵ�.
			break;
		}
	}
	for (int i = 0; i < a.size()-1; ++i) {
		if (a[i] > 5) { //5���� ũ�� ������ ���� �ؼ� ���� ���°� �� �̵� �̹Ƿ� ���� �Ѵ�.
			count += 10 - a[i]; //���� �� �� ���ϱ�
			a[i] = 0;
			a[i + 1] ++; // �ø�
			
		}
		else if (a[i] == 5) { //5�� ���� 5�� ���ؼ� �� ���� ���� 5���� Ŀ���� �̵��̱� ������ ������ �������ش�.
			if (a[i + 1] + 1 > 5) {
				count += 10 - a[i];
				a[i] = 0;
				a[i + 1]++;
			}
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		count += a[i];
	}
	return count;
}


int main() {
	int T = 0;
	cin >> T;
	long long num = 0; // 10�� 10�����̹Ƿ� long long
	for (int i = 0; i < T; ++i) {
		cin >> num;
		cout << sol(num) << "\n";
	}
}