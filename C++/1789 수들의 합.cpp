#include <iostream>
using namespace std;

unsigned long sigma(unsigned long n);

int main(void)
{
	unsigned long s;
	cin >> s;
	unsigned long under = 0;
	unsigned int n = 1;

	while (under < s) {
		under = sigma(n);
		n++;
	}

	if (under == s)
		cout << n - 1;
	else
		cout << n - 2;

	return 0;
}

unsigned long sigma(unsigned long n)
{
	unsigned long ans = (1 + n) * n / 2;
	return ans;
}
