#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	string s;

	while (true) {
		if (cin.eof() == true)
			break;

		getline(cin, s);
		cout << s << "\n";
	}
	

	return 0;
}
