#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	string key;
	cin >> t >> key;

	for (int i = 1; i < t; i++) {
		string value;
		cin >> value;
		for (int j = 0; j < key.length(); j++) {
			if (key.at(j) != value.at(j))
				key.replace(j, 1, "?");
		}
	}

	cout << key;

	return 0;
}
