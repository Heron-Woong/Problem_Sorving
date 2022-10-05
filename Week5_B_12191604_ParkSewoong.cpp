#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int dp[50001];

int main() {
	int T = 0;
	int n = 0; int m=0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		vector<pair<int, string>> v;
		vector<vector<pair<int, int>>> edges(n);
		unordered_map <string, int> city;
	
		string ci; int year;

		for (int i = 0; i < n; ++i) {
			cin >> ci >> year;
			v.push_back({ year,ci });
			dp[i] = 0;
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			city.insert({ v[i].second, i });
		}

		string ci2;
		int weight;
		for (int i = 0; i < m; ++i) {
			cin >> ci >> ci2 >> weight;
			if (v[city[ci]].first < v[city[ci2]].first) {
				edges[city[ci]].push_back(make_pair( city[ci2],weight ));
			}
			if (v[city[ci]].first > v[city[ci2]].first) {
				edges[city[ci2]].push_back(make_pair(city[ci], weight));
			}
		}
		int next = 0;
		int next_weight = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < edges[i].size(); ++j) {
				next = edges[i][j].first;
				next_weight = edges[i][j].second;
				dp[next] = max(dp[next], dp[i] + next_weight);
			}
		}
		int result = 0;
		for (int i = 0; i < n; ++i) {
			if (result < dp[i]) {
				result = dp[i];
			}
		}
		cout << result << "\n";
	}
}

/*
2
7 9
Incheon 2011
Seoul 2012
Daegu 2012
Jeju 2017
Daejeon 2015
Busan 2016
Suwon 2014
Daegu Seoul 20
Seoul Suwon 60
Suwon Incheon 20
Incheon Seoul 10
Daegu Busan 125
Suwon Busan 30
Busan Jeju 45
Busan Daejeon 70
Daejeon Jeju 120
10 15
Ava 2001
Akyab 2002
Bagan 2002
Bago 2003
Mandalay 2004
Mrawk 2005
Naypyidaw 2005
Prome 2006
Toungoo 2007
Yangon 2008
Ava Akyab 15
Ava Yangon 80
Akyab Bagan 10
Akyab Bago 20
Bagan Mandalay 20
Bagan Mrawk 60
Bago Mrawk 20
Bago Yangon 50
Mandalay Prome 65
Naypyidaw Prome 70
Naypyidaw Toungoo 120
Prome Toungoo 45
Akyab Mrawk 20
Bago Prome 80
Mrawk Prome 30
*/