#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n = 0;
		cin >> n;
		vector<int> pro;
		int num = 0;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			pro.push_back(num);
		}
		sort(pro.begin(), pro.end());
		int start; int last; int X;
		long long result = 0;
		int count = 0;
		int temp = 0;
		cin >> start >> last >> X;
		do {
			result = 0;
			for (int i = 0; i < n; ++i) {
				result = result + (pro[i] * pow(X, i));
			}
			temp = result % 1013;
			if (start <= temp && temp <= last) {
				++count;
			}
		} while (next_permutation(pro.begin(), pro.end()));
		cout << count << "\n";
	}
}