#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[100001];
int n,m;

int parent[100001];
int depth[100001];

int minDepth;






int main() {
	
	int T = 0;
	cin >> T;
	int v = 0; 
	int u = 0;
	int inf = 0;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		queue <int> que;
		vector<vector<int>> tree(n + 1);
		vector<int> infected;
		int now = 0;
		for (int i = 0; i < n-1; ++i) {
			cin >> v >> u;
			tree[v].push_back(u);
			tree[u].push_back(v);
		}
		for (int i = 1; i <= n; ++i) {
			parent[i] = 0;
			depth[i] = -1;
			check[i] = false;
		} 
		
		for (int i = 0; i < m; ++i) {
			cin >> inf;
			infected.push_back(inf);
		}
		que.push(1);
		depth[1] = 0;
		while (que.empty() == false) {
			now = que.front();
			que.pop();
			for (int i = 0; i < tree[now].size(); ++i) {
				if (depth[tree[now][i]] == -1) {
					que.push(tree[now][i]);
					depth[tree[now][i]] = depth[now] + 1;
					parent[tree[now][i]] = now;
				}
				
			}
		}
		minDepth = n;
		for (int i = 0; i < m; ++i) {
			minDepth = min(minDepth, depth[infected[i]]);
		}
		for (int i = 0; i < m; ++i) {
			while (depth[infected[i]] > minDepth) {
				if (check[infected[i]] == true) break;
				check[infected[i]] = true;
				infected[i] = parent[infected[i]];
			}
			if (check[infected[i]] == false) {
				que.push(infected[i]);
				check[infected[i]] = true;
			}
		}
		while (que.size() > 1) {
			now = que.front();
			que.pop();
			if (check[parent[now]] == false) {
				que.push(parent[now]);
				check[parent[now]] = true;
			}
		}
		int LCA = 0;
		LCA = que.front();
		int LCA_par;
		if (LCA == 1) {
			cout << -1 << "\n";
		}
		else {
			LCA_par = parent[LCA];
			if (LCA > LCA_par) swap(LCA, LCA_par);
			cout << LCA << " " << LCA_par << "\n";
		}

	}
	


}
