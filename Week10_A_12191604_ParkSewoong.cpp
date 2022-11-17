#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int start; int last; int X;
long long result;
int counted;
int temp;


void sol(vector<int>& pro, int depth, int n, int r) {
	if (depth == r) {
		result = 0;
		for (int i = 0; i < n; ++i) {
			result = result + (pro[i] * pow(X, i));
		}
		temp = result % 1013;
		if (start <= temp && temp <= last) {
			++counted;
		}
		return;
	}
	for (int i = depth; i < pro.size(); ++i) {
		swap(pro[i], pro[depth]);
		sol(pro, depth + 1, n, r);
		swap(pro[i], pro[depth]);
	}
}


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
		cin >> start >> last >> X;
		counted = 0;
		sol(pro, 0, n, n);
		cout << counted << "\n";
	}
}