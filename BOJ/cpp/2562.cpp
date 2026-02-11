#include <iostream>
using namespace std;

int main() {
	int ar[9];

	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;

		ar[i] = n;
	}

	int max = 0;
	int index = -1;

	for (int i = 0; i < 9; i++) {
		if (ar[i] > max)
		{
			max = ar[i];
			index = i + 1;
		}
	}

	cout << max << "\n" << index;

	return 0;
}
