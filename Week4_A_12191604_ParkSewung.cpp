#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

int main() {
	int T = 0;
	int N = 0; int K = 0;
	cin >> T;
	int num = 0;
	for (int i = 0; i < T; ++i) {
		int result = 0;
		vector<int> w;
		vector<int> p;
		cin >> N >> K;
		for (int i = 0; i < N; ++i) {
			cin >> num;
			w.push_back(num);
		}
		for (int i = 0; i < N; ++i) {
			cin >> num;
			p.push_back(num);
		}
		multimap<int, int> pro;
		for (int i = 0; i < N; ++i) {
			int num = p[i] / w[i];
			pro.insert({ num , i });
		}
		multimap <int, int>::iterator it;
		for (it = --pro.end(); it != --pro.begin(); --it) {
			if (w[it->second] < K) {
				result += p[it->second];
				K -= w[it->second];
			}
			else {
				result += (p[it->second] / w[it->second]) * K;
				break;
			}
		}
		cout << result << "\n";
	}
	return 0;
}
/*
2
7 95
36 14 48 32 61 43 29
36 56 240 320 61 43 290
6 73
26 71 6 37 12 15
234 639 54 111 96 150
*/