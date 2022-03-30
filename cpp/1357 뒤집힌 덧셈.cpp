#include <iostream>
#include <string>
using namespace std;

int rev(int n);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	cout << rev(rev(a) + rev(b));

	return 0;
}

int rev(int n)
{
	string sn = to_string(n);
	string n2;

	for (int i = sn.length() - 1; i >= 0; i--)
		n2 += sn.at(i);

	return stoi(n2);
}
