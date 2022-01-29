#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cnt = 0;
	int i = 666;
	int n;
	cin >> n;

	while (true) {
		if (cnt == n)
			break;

		string s = to_string(i);
		if (s.find("666") != string::npos)
			cnt++;
		i++;
	}

	cout << i - 1;
	
	return 0;
}
