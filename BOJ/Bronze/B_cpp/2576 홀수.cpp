#include <iostream>
using namespace std;

int main()
{
	int n;
	int minOdd = 100;
	int sumOdd = 0;

	for (int i = 0; i < 7; i++) {
		cin >> n;

		if (n % 2 == 1) {
			sumOdd += n;
			if (n < minOdd)
				minOdd = n;
		}
	}

	if (sumOdd == 0)
		cout << -1;
	else {
		cout << sumOdd << "\n" << minOdd;
	}
	
	return 0;
}
