#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double r;
	cin >> r;
	cout << fixed << setprecision(6) << 3.14159265359 * r * r
		<< "\n" << 2.0 * r * r;

	return 0;
}
