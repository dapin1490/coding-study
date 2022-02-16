#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true) {
		string s;
		getline(cin, s);

		if (s == "END")
			break;

		for (int i = s.length() - 1; i >= 0; i--) {
			cout << s.at(i);
		}
		cout << "\n";
	}
	
	return 0;
}
