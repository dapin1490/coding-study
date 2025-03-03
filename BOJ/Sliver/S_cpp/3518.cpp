#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 왼쪽 공백 지우기
string& ltrim(string& str, string& chars);
// 오른쪽 공백 지우기
string& rtrim(string& str, string& chars);
// 양쪽 공백 지우기
string& trim(string& str, string& chars);

vector<vector<string>> words;
vector<int> wlen;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s, space = " ", temp;
	int wcnt = 0;

	while (true) {
		getline(cin, s);
		if (s.empty())
			break;

		s = trim(s, space);
		s += " "; // 다듬어진 문자열 끝에 공백 붙이기
		int len = s.length();
		vector<string> v;
		for (int i = 0; i < len; i++) { // 한 문장 내의 단어 골라내기
			if (!isspace(s.at(i))) { // 지금 글자가 공백이 아니라면
				temp += s.at(i);
			}
			else if (!temp.empty()) { // 지금 글자가 공백이고 저장된 단어가 있다면
				v.push_back(temp); // 단어 저장
				wcnt++; // 단어 개수 세기
				if (wlen.size() < wcnt) // 단어 길이 벡터가 지금 단어의 인덱스보다 적다면
					wlen.push_back(0); // 하나 추가
				// 지금 단어 길이가 단어 길이 벡터의 값보다 크다면
				if (temp.length() > wlen[wcnt - 1])
					wlen[wcnt - 1] = temp.length();
				temp.clear(); // 사용한 단어 지우기
			}
		} // 한 문장 검사 끝
		words.push_back(v); // 단어 벡터 추가
		wcnt = 0; // 단어 개수 지우기
	} // 입력 끝

	// 출력
	for (int i = 0; i < words.size(); i++) {
		int jlen = words[i].size();

		for (int j = 0; j < jlen; j++) {
			cout << words[i][j]; // 일단 단어 출력
			if (j >= jlen - 1) // 문장의 마지막 단어라면
				break; // 공백을 추가로 출력하지 않고 패스
			else // 마지막 단어가 아니라면
				cout << " "; // 띄어쓰기 출력
			if (words[i][j].length() < wlen[j]) { // 단어가 최대 길이보다 짧다면
				// 짧은 만큼 공백 추가 출력
				for (int k = 0; k < wlen[j] - words[i][j].length(); k++) {
					cout << " ";
				}
			}
		}

		if (i >= words.size() - 1)
			break;
		cout << "\n";
	}

	return 0;
}

// 왼쪽 공백 지우기
string& ltrim(string& str, string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

// 오른쪽 공백 지우기
string& rtrim(string& str, string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

// 양쪽 공백 지우기
string& trim(string& str, string& chars)
{
	return ltrim(rtrim(str, chars), chars);
}
