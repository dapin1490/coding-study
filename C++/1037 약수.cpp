#include <iostream>
using namespace std;

int main()
{
	int mini = 1000001;
	int maxi = 0;
	int n;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n < mini)
			mini = n;
		if (n > maxi)
			maxi = n;
	}

	cout << mini * maxi;
	
	return 0;
}
