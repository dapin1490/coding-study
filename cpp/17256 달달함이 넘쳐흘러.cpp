#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a[3];
	int c[3];

	cin >> a[0] >> a[1] >> a[2];
	cin >> c[0] >> c[1] >> c[2];

	cout << c[0] - a[2] << " " << c[1] / a[1] << " " << c[2] - a[0];

	return 0;
}
