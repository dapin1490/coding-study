#include <iostream>
#include <string>
using namespace std;

string yoda(string text);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	string line;
	string answer = "";

	getline(cin, line);
	n = stoi(line);

	for (int i = 0; i < n; i++) {
		getline(cin, line);

		cout << yoda(line) << "\n";
	}

	return 0;
}

string yoda(string text)
{
	int idx = text.find(' '); // 첫 번째 공백
	idx = text.find(' ', idx + 1); // 두 번째 공백

	return text.substr(idx + 1) + " " + text.substr(0, idx);
}