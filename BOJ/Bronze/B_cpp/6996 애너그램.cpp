#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string a, string b);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	string str1, str2;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		cout << (str1 + " & " + str2 + " are ") << (isAnagram(str1, str2) ? "anagrams.\n" : "NOT anagrams.\n");
	}

	return 0;
}

bool isAnagram(string a, string b)
{
	int str1[26] = { 0 };
	int str2[26] = { 0 };
	int len;

	if (a.length() == b.length())
		len = a.length();
	else
		return false;

	for (int i = 0; i < len; i++) {
		str1[int(a.at(i)) - int('a')]++;
		str2[int(b.at(i)) - int('a')]++;
	}

	for (int i = 0; i < 26; i++) {
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}
