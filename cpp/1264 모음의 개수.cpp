#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int cnt = 0;
	
	while (true) {
		getline(cin, s);
		if (s == "#")
			break;

		for (int i = 0; i < s.length(); i++) {
			switch (s.at(i))
			{
			case 'A': case 'a':
			case 'E': case 'e':
			case 'I': case 'i':
			case 'O': case 'o':
			case 'U': case 'u':
				cnt++;
				break;
			}
		}

		cout << cnt << "\n";
		cnt = 0;
	}
	
	return 0;
}
