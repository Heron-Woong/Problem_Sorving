#include <iostream>
using namespace  std;


int biStart;
int A; int B;


int Dist(int X) {
	if (X <= A) {
		return 2 * X;
	}
	int R = X / A;
	return Dist(X - R * A + R * B) + 2 * R * A;
}


int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> biStart >> A >> B;
		cout << Dist(biStart) << "\n";
	}
}