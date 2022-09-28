#include <iostream>
#include <vector>
using namespace std;




int pro(int a, int b) {
	while (1) {
		int temp = a % b;
		a = b;
		b = temp;
		if (b == 0) {
			return a;
		}
		if (a == 1) {
			return a;
		}
	}
}

int sol(vector<int> soled) {
	int result = 0;
	if (soled.size() >= 2) {
		int sol = pro(soled[0], soled[1]);
		for (int i = 2; i < soled.size(); ++i) {
			sol = pro(sol, soled[i]);
		}
		result = sol;
	}
	else {
		result = soled[0];
	}
	return result;
}

bool check(vector<int> ch, int a) {
	bool cha = true;
	for (int i = 0; i < ch.size(); ++i) {
		if (ch[i] % a == 0) {
			cha = false;
			break;
		}
	}
	return cha;
}

int main() {
	int T = 0;
	cin >> T;
	int h = 0; int n = 0;
	int num = 0;
	int inhap = 0;
	int bip = 0;
	for (int i = 0; i < T; ++i) {
		vector <int> inha;
		vector <int> bi;
		cin >> h >> n;
		for (int j = 0; j < h; ++j) {
			cin >> num;
			inha.push_back(num);
		}
		for (int j = 0; j < n; ++j) {
			cin >> num;
			bi.push_back(num);
		}
		inhap = sol(inha);
		bip = sol(bi);
		bool inch = check(inha, bip);
		bool bich = check(bi, inhap);
		if (inch == false) bip = -1;
		if (bich == false) inhap = -1;
		cout << bip << " " << inhap << "\n";
	}
}