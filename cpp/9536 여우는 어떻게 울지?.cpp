#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string t;
	getline(cin, t);

	for (int i = 0; i < stoi(t); i++) {
		string sound;
		getline(cin, sound);

		while (true) {
			string dict;
			getline(cin, dict);

			if (dict == "what does the fox say?")
				break;

			int idx = dict.find("goes");
			int len = dict.length() - (idx + 5);
			string not_fox = dict.substr(idx + 5, len);

			idx = 0;
			while (true) {
				idx = sound.find(not_fox, idx);
				if (idx == -1)
					break;
				
				if (idx != 0) {
					if (sound.at(idx - 1) != ' ') {
						if (idx >= sound.length() - 1)
							break;
						else {
							idx++;
							continue;
						}
					}
				}

				if (idx + len >= sound.length()) {
					sound.erase(idx, len);
				}
				else if (sound.at(idx + len) == ' ') {
					sound.erase(idx, len + 1);
				}
			}
		}

		cout << sound << "\n";
	}

	return 0;
}
