#include <iostream>
using namespace std;

int main()
{
	int yes = 0;
	int no = 0;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		bool cute;
		cin >> cute;
		if (cute)
			yes++;
		else
			no++;
	}

	cout << (yes > no ? "Junhee is cute!" : "Junhee is not cute!");
	
	return 0;
}
