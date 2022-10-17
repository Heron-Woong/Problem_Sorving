#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int counted;
int n; 
int m;

void Hanoi(int n, int sta, int des, vector<vector<int>>& hanoi) {
	int temp = 0;
	if (counted == m) {
		return;
	}
	if (n == 1) {
		temp = hanoi[sta][hanoi[sta].size() - 1];
		hanoi[sta].pop_back();
		hanoi[des].push_back(temp);
		++counted;
		return;
	}
	else {
		Hanoi(n - 1, sta, 6-sta-des, hanoi);
		if (counted == m) {
			return;
		}
		temp = hanoi[sta][hanoi[sta].size() - 1];
		hanoi[sta].pop_back();
		hanoi[des].push_back(temp);
		++counted;
		Hanoi(n - 1, 6-sta-des, des, hanoi);
		if (counted == m) {
			return;
		}
	}
}

int main() {
	int T = 0;
	cin >> T;
    for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		counted = 0;
		vector<vector<int>> hanoi(4);
		for (int i = n; i >= 1; --i) {
			hanoi[1].push_back(i);
		}
		Hanoi(n, 1, 3, hanoi);
		if (hanoi[2].size() != 0) {
			for (int i = hanoi[2].size()-1; i >= 0; --i) {
				cout << hanoi[2][i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

}

