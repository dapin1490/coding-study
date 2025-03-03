#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;

	cin >> a >> b;

	cout << (a * 8 + b * 3) - 28;

	return 0;
}
