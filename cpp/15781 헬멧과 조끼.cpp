#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int helmet = 0, vest = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (helmet < temp)
			helmet = temp;
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;

		if (vest < temp)
			vest = temp;
	}

	cout << helmet + vest;

	return 0;
}
