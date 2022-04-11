#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;

	cin >> a >> b >> c;

	if (a + b + c == 180) {
		if (a == 60 && b == 60 && c == 60)
			cout << "Equilateral";
		else if (a == b || b == c || a == c)
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	else
		cout << "Error";

	return 0;
}
