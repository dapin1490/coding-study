#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x[] = { 0, 0, 0 };
	int y[] = { 0, 0, 0 };

	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	if (x[0] == x[1])
		cout << x[2] << " ";
	else if (x[0] == x[2])
		cout << x[1] << " ";
	else
		cout << x[0] << " ";

	if (y[0] == y[1])
		cout << y[2];
	else if (y[0] == y[2])
		cout << y[1];
	else
		cout << y[0];

	return 0;
}
