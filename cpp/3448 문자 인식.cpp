#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void detectChar(string txt);

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	string text;

	getline(cin, text);
	n = stoi(text);

	for (int i = 0; i < n; i++) {
		text = "";

		while (true) {
			string line;
			getline(cin, line);

			if (line != "")
				text += line;
			else break;

			if (cin.eof() == true)
				break;
		}

		detectChar(text);
	}
	
	return 0;
}

void detectChar(string txt)
{
	int total_len = txt.length();
	int detected_char = 0;
	double res;
	string temp;

	for (int i = 0; i < total_len; i++) {
		if (txt.at(i) != '#')
			detected_char++;
	}

	res = round(double(detected_char) / double(total_len) * 1000) / 10;
	temp = to_string(res);

	if (temp.at(temp.find('.') + 1) == '0')
		cout << fixed << setprecision(0) << "Efficiency ratio is " << res << "%.\n";
	else
		cout << fixed << setprecision(1) << "Efficiency ratio is " << res << "%.\n";
}
