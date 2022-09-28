#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int m = 0;  int n = 0;
	int num = 0;
	string str;
	for(int i=0; i<T; ++i){
		map <int, int> pro;
		cin >> m >> n;
		for (int i = 0; i < m; ++i) {
			cin >> num;
			if (pro.find(num) != pro.end()) {
				pro[num]++;
			}
			else pro.insert({ num, 1 });
		}
		for (int i = 0; i < n; ++i) {
			cin >> str;
			if (str == "Delete") {
				cin >> str;
				if (str == "min") {
					if (pro.begin()->second > 1) {
						pro.begin()->second--;
					}
					else {
						pro.erase(pro.begin());
					}
				}
				else {
					map<int, int>::iterator it = --pro.end();
					if (it->second   > 1) {
						it->second--;
					}
					else {
						pro.erase(it);
					}

				}
			}
			else {
				cin >> num;
				if (pro.find(num) != pro.end()) {
					pro[num]++;
				}
				else pro.insert({ num, 1 });
			}
		}
		map<int, int>::iterator it = --pro.end();
		cout << pro.begin()->first << " " << it->first << "\n";
	}
}