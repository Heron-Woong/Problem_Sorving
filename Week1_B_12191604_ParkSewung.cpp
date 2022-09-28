#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int>&a,const pair<int,int>& b) {
	return a.first > b.first;

}

int check(vector <pair<int, int>> cha) {
	int max = 0;
	if (cha.size() == 0) {
		return max;
	}
	if (cha.size() == 1) {
		max = cha[0].second * 2;
		return max;
	}
	int result = 0;
	int check = 0;
	int index = 0;
	int chind = cha.size() - 1;
	for (int i = 0; i < cha.size()-1; ++i) {
		if (cha[i].first - (cha[i].second * 2) == cha[i + 1].first) {
			result += cha[i].second;
			if (i == cha.size() - 2) {
				result += cha[i + 1].second;
			}
		}
		if (cha[i].first - (cha[i].second * 2) > cha[i + 1].first) {
			if (check != 0) {
				if (cha[i].first - cha[i].second - cha[i + 1].first == cha[i].second + check) {
					result += cha[i].second;
					check = 0;
					if (i == cha.size() - 2) {
						result += cha[i + 1].second;
					}
				}
				else if (cha[i].first - cha[i].second - cha[i + 1].first < cha[i].second + check) {
					result += cha[i].second;
					check = cha[i].second + check - (cha[i].first - cha[i].second - cha[i + 1].first);
					if (i == cha.size() - 2) {
						result += cha[i + 1].second;
					}
				}
				else {
					result += cha[i].second;
					if (max < result * 2) max = result * 2;
					result = 0;
					check = 0;
					if (i == cha.size() - 2) {
						result += cha[i + 1].second;
					}
					if (max < result * 2) max = result * 2;
					continue;
				}
			}
			else {
				result += cha[i].second;
				if (max < result * 2) max = result * 2;
				result = 0;
				if (i == cha.size() - 2) {
					result += cha[i + 1].second;
				}
				if (max < result * 2) max = result * 2;
				continue;
			}
		}
		if (cha[i].first - (cha[i].second * 2) < cha[i + 1].first) {
		    index = cha[i].first - cha[i].second;
			check += cha[i].second -(index - cha[i+1].first );
			result += cha[i].second;
			if (i == cha.size() - 2) {
				result += cha[i + 1].second;
			}
		}
	}
	if (max < result * 2) max = result * 2;
	return max;
}

void sol(string pro, vector <pair<int, int>>& cha) {
	int ccount = 0;
	int tcount = 0;
	for (int i = 0; i < pro.size(); ++i) {
		if (pro[i] == 'C') {
			ccount++; 
			continue;
		}
		if (pro[i] == 'T' && ccount != 0) {
			tcount++;
		}
		if (ccount == tcount && ccount !=0 && tcount !=0) {
			cha.push_back({ i, tcount });
			ccount = 0; tcount = 0;
		}
		if (ccount > tcount) {
			if (i != pro.size() - 1) {
				if (pro[i + 1] == 'C') {
					cha.push_back({ i, tcount });
					ccount = ccount - tcount;
					tcount = 0;
				}
			}
			else {
				cha.push_back({ i,tcount });
			}
		}
		
	} 
}


int main() {
	int T = 0;
	cin >> T;
	string pro;
	for (int i = 0; i < T; ++i) {
		vector<int> cnum;
		vector <pair<int, int>> cha;
		cin >> pro;
		sol(pro,cha);
		sort(cha.begin(), cha.end(), compare);
		cout << check(cha) << "\n";
	}
}

/*
4
CCTTTCTCCTCCTTTTCTCT
CCCTTT
CCCCTTT
C
*/