#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, v;
	cin >> a >> b >> v;
	
	int day = static_cast<int>(ceil((v - a) / (a - b))) + 1;

	cout << day;
	
	
	return 0;
}
