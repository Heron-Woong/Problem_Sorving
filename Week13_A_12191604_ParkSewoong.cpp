#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n; int m;
vector<bool> checked;
vector<vector<pair<int, int>>> path(1001);

void sol(int start) {
	if (checked[start] == true) {
		return;
	}
	checked[start] = true;
	cout << start << "\n";
	int next = 0;
	for (int i = 0; i < path[start].size(); ++i) {
		next = path[start][i].second;
		if (checked[next] == true) continue;
		sol(next);
	}
}

int main() {
	int T = 0;
	cin >> T;
	int num = 0;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		map<int, int>index;
		vector<pair<int, int>>height;
		checked.clear();
		for (int i = 0; i < n; ++i) {
			path[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			cin >> num;
			height.push_back({ num,i });
			index.insert({ i,num });
			checked.push_back(false);
		}
		sort(height.begin(), height.end());
		int p; int w;
		for (int i = 0; i < m; ++i) {
			cin >> p >> w;
			path[p].push_back({ index[w],w });
			path[w].push_back({ index[p],p });
		}
		for (int i = 0; i < n; ++i) {
			sort(path[i].begin(), path[i].end());
		}

		for (int i = 0; i < n; ++i) {
			if (checked[height[i].second] == true) continue;
			sol(height[i].second);
		}
	}
}