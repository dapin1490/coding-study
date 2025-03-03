#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct dictWord {
	int cnt;
	unsigned int len;
	string word;
};

bool cmp(dictWord a, dictWord b) {
	if (a.cnt == b.cnt) {
		if (a.len == b.len)
			return a.word < b.word;
		return a.len > b.len;
	}
	return a.cnt > b.cnt;
}

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<dictWord> dict;
	map<string, int> idxmap;
	unsigned int n, m;
	string w;

	cin >> n >> m;

	for (unsigned int i = 0; i < n; i++) {
		cin >> w;
		unsigned int l = w.length();
		if (l < m)
			continue;

		if (idxmap.find(w) == idxmap.end()) { // 단어가 사전에 없음
			idxmap.insert(pair<string, int>(w, dict.size()));
			dict.push_back(dictWord{ 1, l, w });
		}
		else // 이미 있는 단어
			dict[idxmap[w]].cnt++;
	}

	sort(dict.begin(), dict.end(), cmp);

	for (int i = 0; i < dict.size(); i++)
		cout << dict[i].word << "\n";

	return 0;
}
