#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int n = a * b * c;
	string s = to_string(n);

	int ar[10];
	for (int i = 0; i < 10; i++)
		ar[i] = 0;

	for (int i = 0; i < s.length(); i++) {
		switch (s.at(i)) {
		case '0': ar[0]++; break;
		case '1': ar[1]++; break;
		case '2': ar[2]++; break;
		case '3': ar[3]++; break;
		case '4': ar[4]++; break;
		case '5': ar[5]++; break;
		case '6': ar[6]++; break;
		case '7': ar[7]++; break;
		case '8': ar[8]++; break;
		case '9': ar[9]++; break;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << ar[i] << "\n";

	return 0;
}
