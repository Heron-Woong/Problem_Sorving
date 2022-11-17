#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n = 0; int m = 0; int k = 0;
		cin >> n >> m >> k;
		vector<int> res;
		vector<bool> check;
		map<long long, int> h;
		long long hei;
		for (int i = 0; i < n; ++i) {
			cin >> hei;
			h.insert({ hei,i });
			res.push_back(0);
			check.push_back(false);
		}
		vector<vector<int>>path(n);
		int v = 0; int u = 0;
		for (int i = 0; i < m; ++i) {
			cin >> v >> u;
			path[v].push_back(u);
			path[u].push_back(v);
		}
		int start = h.begin()->second;
		queue<int> q; q.push(start);
		int next = 0;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i < path[now].size(); ++i) {
				next = path[now][i];
				if (next == start)continue;
				if (check[next] == false) {
					check[next] = true;
					res[next] = res[now] + 1;
					q.push(next);
				}
				else {
					res[next] = min(res[now] + 1, res[next]);
				}
			}
		}
		int num = 0;
		for (int i = 0; i < k; ++i) {
			cin >> num;
			if (num >= n) {
				cout << -1 << "\n";
			}
			else if (num == start) {
				cout << 0 << "\n";
			}
			else if (res[num] == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << res[num] << "\n";
			}
		}
	}
}