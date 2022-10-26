#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	string str;
	for (int i = 0; i < T; ++i) {
		cin >> str;
		vector<int> sol;
		if (str[0] == '0')sol.push_back(-1);
		else sol.push_back(1);
		for (int i = 1; i < str.size(); ++i) {
			if (str[i] == '0') {
				sol.push_back(sol[i - 1]-1);
			}
			else {
				sol.push_back(sol[i - 1]+1);
			}
		}
		int answer = 0;
		map<int, int> dict;
		dict.insert({ 0,0 });
		for (int j = 0; j < str.size(); ++j) {
			if (dict.find(sol[j]) == dict.end()) {
				dict.insert({ sol[j],j+1 });
			}
			else {
				answer = max(answer, j+1 - dict[sol[j]]);
			}
		}
		cout << answer << "\n";
	}
}