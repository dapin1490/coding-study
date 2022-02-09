#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int id = 0;
	int maxi = 0;

	for (int i = 1; i <= 5; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a = a + b + c + d;
		if (a > maxi) {
			maxi = a;
			id = i;
		}
	}

	cout << id << " " << maxi << "\n";
	
	return 0;
}
