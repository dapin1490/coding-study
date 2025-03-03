#include <iostream>
using namespace std;

string classify_triangle(int a, int b, int c);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i << ": " << classify_triangle(a, b, c) << "\n";
	}

	return 0;
}

string classify_triangle(int a, int b, int c)
{
	if (a + b + c - max(a, max(b, c)) <= max(a, max(b, c)))
		return "invalid!";

	if (a == b && b == c && a == c)
		return "equilateral";
	else if (a == b || b == c || a == c)
		return "isosceles";
	else
		return "scalene";
}
