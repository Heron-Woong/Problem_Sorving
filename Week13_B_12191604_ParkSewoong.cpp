#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int N = 0; int M = 0; int Q = 0;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M >> Q;
		int u = 0; int v = 0; int w = 0;
		vector<vector<pair<int, int>>> path(N);
		int dp[250][250];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) {
					dp[i][j] = 0;
				}
				else { dp[i][j] = 987654321; }
			}
		}
		for (int i = 0; i < M; ++i) {
			cin >> u >> v >> w;
			dp[u][v] = w;
			dp[v][u] = w;
		}
		//i 거쳐가는 노드
		for (int k = 0; k < N; ++k) {
			//j 출발 노드
			for (int i = 0; i < N; ++i) {
				//k 도착 노드
				for (int j = 0; j < N; ++j) {
					if (dp[i][k] + dp[k][j] < dp[i][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
		for (int i = 0; i < Q; ++i) {
			cin >> u >> v;
			cout << dp[u][v] << "\n";
		}
	}
}

/*
2
4 4 4
0 2 20
2 3 10
1 2 30
3 0 5
0 3
2 3
1 2
0 2

*/