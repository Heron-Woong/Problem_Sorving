#include <iostream>
#include <string>
#include <vector>
using namespace std;

int m = 0; int n = 0;

string sol(vector <pair<string, char>> ch, string check) {
	vector <string> ch1;
	string str;
	string res;
	int count = 0;
	for (int i = 0; i < check.size(); ++i) {
		str += check[i];
		++count;
		if (count == n) {
			ch1.push_back(str);
			count = 0;
			str = "";
		}
	}
	count = 0;
	int min = 1025;
	int idx = 0;
	for (int j = 0; j < ch1.size(); ++j) {
	    min = 1025;
		for (int i = 0; i < ch.size(); ++i) {
			count = 0;
			for (int k = 0; k < n; ++k) {
				if (ch[i].first[k] != ch1[j][k]) {
					++count;
				}
			}
			if (min > count) { 
				min = count; 
				idx = i;
			}
		}
		res += ch[idx].second;
	}
	return res;
}



int main() {
	int T = 0;
	cin >> T;	
	int size = 0;
	for (int i = 0; i < T; ++i) {
		vector <pair<string,char>> ch;
		string str;
		cin >> m >> n;
		for (int i = 0; i < m; ++i) {
			cin >> str;
			ch.push_back(make_pair(str,('A' + i)));
		}
		string check;
		cin >> size >> check;
		cout << sol(ch, check) << "\n";
	}
}