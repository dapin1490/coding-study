#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	a += (b + c) / 60;
	b = (b + c) % 60;

	cout << a % 24 << " " << b;
    
	return 0;
}
