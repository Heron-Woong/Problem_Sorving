#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int main() {
	long long dp[30][2];
	dp[0][0] = 0; dp[0][1] = 1;
	dp[1][0] = 1; dp[1][1] = 2;
	for (int i = 2; i <= 29; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = 2 * dp[i - 1][1] + pow(2, i - 1) - 1;
	}
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int num = 0;
		cin >> num;
		long long count = 0;
		while (1) {
			num /= 2;
			++count;
			if (num == 1) {
				break;
			}
		}
		cout << dp[count][0] << " " << dp[count][1] << "\n";
	}
}