#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<char> v;
	string text;
	int len;
	bool tag_on = false;

	getline(cin, text);
	text += ' ';
	len = text.length();

	for (int i = 0; i < len; i++) {
		char key = text.at(i);

		v.push_back(key);

		if (key == '<')
			tag_on = true;
		else if (key == '>') {
			tag_on = false;
			while (true) {
				if (v.empty())
					break;

				cout << v.front();
				v.erase(v.begin());
			}
		}

		if (!tag_on && key == ' ') {
			v.pop_back();
			while (true) {
				if (v.empty())
					break;

				cout << v.back();
				v.pop_back();
			}
			cout << " ";
		}
		
		if (v.size() > 1 && key == '<') {
			v.pop_back();
			while (true) {
				if (v.empty())
					break;

				cout << v.back();
				v.pop_back();
			}
			v.push_back(key);
		}
	}

	return 0;
}
