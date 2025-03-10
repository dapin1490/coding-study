/*
https://www.acmicpc.net/problem/19844
---
프랑스어 문장처럼 생긴 문자열을 줄 테니 다음 규칙에 따라 단어 수를 세어라. 프랑스어에서 단어로 분리되는 기준은 다음과 같다.

1. 띄어쓰기와 하이픈(`-`)은 단어를 구분한다. 띄어쓰기 혹은 하이픈으로 이어진 문자열은 2개의 단어로 취급한다는 뜻이다.
2. 앞 단어가 `ce`, `je`, `ne`, `me`, `te`, `se`, `le`, `la`, `de`, `que` 혹은 `si`이고 뒤 단어가 모음(`a`, `e`, `i`, `o`, `u`, `h`)으로 시작하는 경우, 앞 단어의 마지막 모음이 사라지고, 대신 '(어포스트로피)가 붙으면서 이어진다. 이 또한 2개의 단어로 취급한다. 여기서는 `h`도 모음으로 취급한다.

예를 들어 `qu'est-ce qu'il mange aujourd'hui`는 7개의 단어로 취급된다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void boj19844() {
	string line;
	vector<string> change_words = { "c", "j", "n", "m", "t", "s", "l", "d", "qu", "s" };
	vector<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'h' };
	vector<string> line_words;
	string temp = "";
	int len = 0;
	
	getline(cin, line);

	for (int i = 0; i < line.size(); i++) {
		if ((line[i] == ' ' || line[i] == '-') && temp.size() > 0) {
			line_words.push_back(temp);
			temp = "";
		}
		else {
			temp += line[i];
		}
	}
	if (temp.size() > 0) {
		line_words.push_back(temp);
	}

	len = line_words.size();
	for (int i = 0; i < len; i++) {
		auto idx = line_words[i].find('\'');
		if (idx != string::npos) {
			temp = line_words[i].substr(0, idx);
			if (find(change_words.begin(), change_words.end(), temp) != change_words.end()
				&& find(vowels.begin(), vowels.end(), line_words[i][idx + 1]) != vowels.end()) {
				line_words.push_back(line_words[i].substr(idx + 1));
				line_words[i] = temp;
			}
		}
	}

	cout << line_words.size();

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	boj19844();

	return 0;
}