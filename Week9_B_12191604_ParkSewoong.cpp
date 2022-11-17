#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	string str1; string str2;
	for (int i = 0; i < T; ++i) {
		cin >> str1 >> str2;
		vector<vector<int>> ch(str1.size() + 1);
		for (int i = 0; i < str1.size() + 1; ++i) {
			for (int j = 0; j <= str2.size() + 1; ++j) {
				ch[i].push_back(0);
			}
		}
		for (int i = 0; i < str1.size()+1; ++i) {
			ch[i][0] = i;
		}
		for (int i = 0; i < str2.size() + 1; ++i) {
			ch[0][i] = i;
		}
		int maxed = 0;
		for (int i = 0; i < str1.size(); ++i) {
			for (int j = 0; j < str2.size(); ++j) {
				if (str1[i] == str2[j]) {
					ch[i + 1][j + 1] = ch[i][j];
				}
				else {
					ch[i + 1][j + 1] = min(ch[i][j+1]+1, ch[i+1][j]+1);
					ch[i + 1][j + 1] = min(ch[i][j] + 1, ch[i + 1][j + 1]);
				}
			}
		}
		cout << ch[str1.size()][str2.size()] << "\n";
	}
}