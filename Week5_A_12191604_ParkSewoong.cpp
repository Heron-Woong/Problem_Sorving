#include <iostream>
#include <string>
using namespace std;

bool solve(string fir, string em) {
	bool  check = true;
	for (int i = 0; i < em.size(); ++i) {
		string ch = em.substr(i, 1);
		int g = fir.find(ch);
		if (g == -1) {
			check = false;
			break;
		};
	}
	return check;
}

bool solve1(string fir, string em) {
	bool  check = true;
	for (int i = 0; i < fir.size(); ++i) {
		string ch = fir.substr(i, 1);
		int g = em.find(ch);
		if (g == -1) {
			check = false;
			break;
		};
	}
	return check;
}



int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string first; string em;
		cin >> first >> em;
		bool check1; bool check2;
		check1 = solve(first, em);
		check2 = solve1(first, em);
		if (check1 == true && check2 == true) {
			cout << "YES" << "\n";
		}
		else cout << "NO" << "\n";
	}
}

/*
4
EVL LEVEL
EVL EVIL
CRAB BARR
EVL EVL
*/