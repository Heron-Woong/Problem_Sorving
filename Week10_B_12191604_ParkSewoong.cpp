#include <iostream>
#include <algorithm>
#include <vector>
#include  <set>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int res = 0;
		int n = 0; int m = 0;
		cin >> n >> m;
		vector<int> acuarium;
		vector<pair<int, int>> shark;
		multiset<pair<int, int>> pq;
		int sta = 0; int las = 0;
		for (int i = 0; i < n; ++i) {
			cin >> sta >> las;
			shark.push_back({ sta,las });
		}
		int num = 0;
		for (int i = 0; i < m; ++i) {
			cin >> num;
			acuarium.push_back(num);
		}
		sort(shark.begin(), shark.end());
		sort(acuarium.begin(), acuarium.end());
		int j = 0;
		for (int i = 0; i < m; ++i) {
			while (j < n && shark[j].first <= acuarium[i]) {
				pq.insert({ shark[j].second,shark[j].first });
				++j;
			}
			while(pq.empty() == false && pq.begin()->first < acuarium[i]) {
				pq.erase(pq.begin());
			}
			if (pq.empty() == false) {
				pq.erase(pq.begin());
				++res;
			}
		}
		cout << res << "\n";
	}
}

/*
3
4 5
15 24
26 32
10 22
40 50
20
30
40
50
70

4 4
10 50
20 60
30 70
40 50
15
25
45
60

2 2
10 20
10 30 
5
15 */
