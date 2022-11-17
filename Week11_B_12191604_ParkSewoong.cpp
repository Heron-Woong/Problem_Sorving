#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int n = 0; int m = 0;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		vector<vector<int>> team(m + 1);
		vector<pair<int, int>> score;
		vector<int> chance;
		int num = 0;
		int temp = 0;
		for (int i = 0; i <= m; ++i) {
			score.push_back({ 0,i });
			chance.push_back(0);
		}
		int rest = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> num;
			if (num == 1 && i != 1) {
				if (temp != 1) {
					chance[temp]++;
					++rest;
				}
			}
			team[num].push_back(i);
			temp = num;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < team[i].size(); ++j) {
				score[i].first += n - team[i][j] + 1;
			}
		}
		int answer = 0;
		priority_queue<pair<int,int>> scoreNow;
		for (int i = 2; i <= m; ++i) {
			if (chance[i] != 0) {
				scoreNow.push({ score[i].first,score[i].second });
				chance[score[i].second]--;
			}
		}
		bool check = true;
		int temp_idx;
		while (rest > 0) {
			check = true;
			for (int i = 2; i <= m; ++i) {
				if (score[i].first >= score[1].first) {
					check = false;
					break;
				}
			}
			if (check == true) break;
			score[1].first++;
			temp_idx = scoreNow.top().second;
			score[temp_idx].first--;
			scoreNow.pop();
			--rest;
			++answer;
			if (chance[temp_idx] > 0) {
				scoreNow.push(score[temp_idx]);
				chance[score[temp_idx].second]--;
			}
		}
		check = true;
		for (int i = 2; i <= m; ++i) {
			if (score[i].first >= score[1].first) {
				check = false;
				break;
			}
		}
		if (check == false) {
			cout << -1 << "\n";
		}
		else {
			cout << answer << "\n";
		}
	}
}

/*
2
12 4 
1
2
4
3
2
3
1
2
4
3
4
1
12 4 
1
3
2
1
4
2
2
4
4
3
3
1


*/