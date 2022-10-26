#include <iostream>
#include <stack>
#include <string>
using namespace std;

int sol(string str) {
	int result = 0;
	int a = 0; int b = 0;
	stack<int> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(a + b);
		}
		else if (str[i] == '-') {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(b - a);
		}
		else if (str[i] == '*') {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(a * b);
		}
		else st.push(stoi(str.substr(i, 1)));
	}
	result = st.top();
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