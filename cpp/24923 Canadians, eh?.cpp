#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	getline(cin, s);

	s = s.substr(s.length() - 3, 3);

	if (s == "eh?")
		cout << "Canadian!";
	else
		cout << "Imposter!";

	return 0;
}
