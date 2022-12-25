#include <iostream>
using namespace std;

int char_sum(string word);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string txt;
		cin >> txt;

		cout << char_sum(txt) << "\n";
	}

	return 0;
}

int char_sum(string word)
{
	int ans = 0;
	int abc[26] = { 0 };

	for (int i = 0; i < word.length(); i++)
		abc[int(word.at(i)) - int('A')] = 1;

	for (int i = 0; i < 26; i++) {
		if (abc[i] == 0)
			ans += i + 65;
	}

	return ans;
}
