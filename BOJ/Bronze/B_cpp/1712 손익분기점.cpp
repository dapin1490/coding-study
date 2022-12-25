// 덧셈 멈춰

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int plus = c - b;

	if (plus <= 0)
	{
		cout << -1;
		return 0;
	}

	cout << (a / plus) + 1;

	
	return 0;
}
