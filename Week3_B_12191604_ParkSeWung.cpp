#include <iostream>
#include <vector>
using namespace std;

int sol(long long num) {
	int count = 0;
	int ch=0;
	vector<int> a;
	while (1) {
		ch = num % 10;
		a.push_back(ch); //각 자리수별로 나누어 준다
		num /= 10;
		if (num == 0) {
			a.push_back(0); //마지막 자리에서 올림이 있을 수 있으므로 하나를 더 추가한다.
			break;
		}
	}
	for (int i = 0; i < a.size()-1; ++i) {
		if (a[i] > 5) { //5보다 크면 무조건 일을 해서 돈을 버는게 더 이득 이므로 일을 한다.
			count += 10 - a[i]; //일한 일 수 더하기
			a[i] = 0;
			a[i + 1] ++; // 올림
			
		}
		else if (a[i] == 5) { //5일 때는 5일 일해서 그 다음 돈이 5보다 커지면 이득이기 때문에 조건을 구별해준다.
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
	long long num = 0; // 10의 10제곱이므로 long long
	for (int i = 0; i < T; ++i) {
		cin >> num;
		cout << sol(num) << "\n";
	}
}