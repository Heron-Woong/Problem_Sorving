#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; int m;
int counted;

void Hanoi(vector<vector<pair<int, int>>>& hanoi, int sta, int des, int n) {
	pair<int,int> temp1;
	pair<int, int>temp2;
	if (counted >= m) {
		return;
	}
	if (n == 1) {
		temp1 = hanoi[sta][hanoi[sta].size() - 1];
		counted += hanoi[sta][hanoi[sta].size() - 1].second;
		if (counted > m) {
			temp1 = hanoi[sta][hanoi[sta].size() - 1];
			temp2 = hanoi[sta][hanoi[sta].size() - 1];
			temp1.second = temp1.second - (counted - m);
			temp2.second = counted - m;
			hanoi[sta].pop_back();
			hanoi[sta].push_back(temp2);
			hanoi[des].push_back(temp1);
		}
		else {
			hanoi[sta].pop_back();
			hanoi[des].push_back(temp1);
		}
		return;
	}
	else {
		Hanoi(hanoi, sta, 6 - sta - des, n - 1);
		if (counted >= m) {
			return;
		}

		temp1 = hanoi[sta][hanoi[sta].size() - 1];
		counted += hanoi[sta][hanoi[sta].size() - 1].second;
		if (counted > m) {
			temp1 = hanoi[sta][hanoi[sta].size() - 1];
			temp2 = hanoi[sta][hanoi[sta].size() - 1];
			temp1.second = temp1.second - (counted - m);
			temp2.second = counted - m;
			hanoi[sta].pop_back();
			hanoi[sta].push_back(temp2);
			hanoi[des].push_back(temp1);
		}
		else {
			hanoi[sta].pop_back();
			hanoi[des].push_back(temp1);
		}

		if (counted >= m) {
			return;
		}
		Hanoi(hanoi, 6 - sta - des, des, n - 1);
		if (counted >= m) {
			return;
		}
	}
}

int main() {
	int T = 0;
	cin >> T;
	int num = 0;
	int j = 1;
	int cnt = 0;
	for (int i = 0; i < T; ++i) {
		counted = 0;
		vector<vector<pair<int,int>>>hanoi(4);
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> num;
			hanoi[1].push_back({ i,num });
		}
		cin >> m;
		sort(hanoi[1].rbegin(), hanoi[1].rend());
		Hanoi(hanoi, 1, 3, n);
		if (hanoi[2].size() != 0) {
			for (int i = hanoi[2].size() - 1; i >= 0; --i) {
				for (int j = 0; j < hanoi[2][i].second; ++j){
					cout << hanoi[2][i].first << " ";
			}
			}
			cout << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}
