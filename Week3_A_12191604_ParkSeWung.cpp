#include <iostream>
#include <vector>
#include <map>
using namespace std;

double midnum(map<double, int> a, int d) {
	map<double, int>::iterator it;
	double mid = 0;
	int cnt = 0;
	if (d % 2 != 0) {
		cnt = d / 2 + 1;
		for (it = a.begin(); it != a.end(); ++it) {
			if (cnt - it->second > 0) {
				cnt -= it->second;
				continue;
			}
			else if (cnt - it->second <= 0) {
				mid = it->first;
				break;
			}
		}
	}
	else {
		cnt = d / 2;
		for (it = a.begin(); it != a.end(); ++it) {
			if (cnt == 0) {
				mid += it->first;
				break;
			}
			if (cnt - it->second > 0) {
				cnt -= it->second;
				continue;
			}
			else if (cnt - it->second == 0) {
				mid += it->first;
				cnt -= it->second;
			}
			else if (cnt - it->second < 0) {
				mid += (it->first * 2);
				break;
			}
		}
		mid /= 2;
	}
	return mid;
}


int sol(vector<double> calorie, int d) {
	double mid = 0;
	int count = 0;
	int check = 0;
	int index = 0;
	map <double, int> a;
	for (int i = 0; i < calorie.size(); ++i) {
		if (count >= d) {
			if (2 * mid <= calorie[i]) {
				++check;
			}
		}
		map <double, int>::iterator it;
		if (a.find(calorie[i]) != a.end()) {
			a[calorie[i]]++;
		}
		else { a.insert({ calorie[i], 1 }); }
		++count;
		if (count >= d) {
			mid = midnum(a, d);
			if (a[calorie[index]] > 1) {
				a[calorie[index]]--;
			}
			else a.erase(calorie[index]);
			++index;
		}
	}
	return check;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	int n = 0; int d = 0;
	double num = 0;
	for (int i = 0; i < T; ++i) {
		vector <double> calorie;
		cin >> n >> d;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			calorie.push_back(num);
		}
		cout << sol(calorie, d) << "\n";
	}
}

/*

2
9 5
2 3 4 2 3 6 8 4 5
5 4
1 2 3 4 4


*/