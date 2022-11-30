#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int n = 0;
	for (int i = 0; i < T; ++i) {
		cin >> n;
		int num = 0;
		vector<pair<int, int>> monster;
		vector<int> result;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			monster.push_back({ num,i + 1 });
			result.push_back(0);
		}
		
		set<pair<int, int>> mon;
		for(int i=0; i<n; ++i){
			pair<set<pair<int, int>>::iterator, bool> ite = mon.insert(monster[i]);
			if (ite.first == mon.begin()) {
				result[(ite.first->second)-1] = -1;
			}
			else {
				if ((ite.first->second) == 1) {
					result[0] = -1;
				}
				else {
					int idx = (ite.first->second) - 1;
					result[idx] = (--ite.first)->second;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
}