#include <iostream>
#include <string>
#include <stack>
using namespace std;



int sol(string str) {
	stack <int> save;
	int max = 0;
	int result = 0;
	save.push(0);
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'C') {
			save.push(i+1);
			continue;
		}
		else {
			if (save.size() == 1) {
				save.pop();
				save.push(i + 1);
				continue;
			}
			else { 
				save.pop(); 
			}
			if (result < i + 1 - save.top()) {
				result = i + 1 - save.top();
			}
		}

	}
	return result;
}



int main() {
	int T = 0;
	cin >> T;
	string str;
	for (int i = 0; i < T; ++i) {
		cin >> str;
		cout << sol(str) << "\n";
	}

}