#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	double ans = 0;
	double total_cost = 0;
	for (int i = 0; i < t; i++) {
		string s, g;
		double c;
		cin >> s >> c >> g;

		double grade = 0;
		switch (g.at(0)) {
		case 'A': grade += 4.0; break;
		case 'B': grade += 3.0; break;
		case 'C': grade += 2.0; break;
		case 'D': grade += 1.0; break;
		}
		if (g != "F") {
			switch (g.at(1)) {
			case '+': grade += 0.3; break;
			case '-': grade -= 0.3; break;
			}
		}

		ans += c * grade;
		total_cost += c;
	}

	ans = ans / total_cost + 0.000000001;
	cout << fixed << setprecision(2) << (round(ans * 100) / 100);

	return 0;
}
