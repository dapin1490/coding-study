#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string text);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;

	while (true) {
		getline(cin, s);
		
		if (s == ".")
			break;

		if (balanced(s))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}

bool balanced(string text)
{
	stack<char> s;
	bool flag = true;

	for (int i = 0; i < text.length(); i++) {
		switch (text.at(i)) {
		case '(': case '[':
			s.push(text.at(i));
			break;

		case ')':
			if (s.empty())
				flag = false;
			else if (s.top() != '(')
				flag = false;
			else
				s.pop();
			break;
		
		case ']':
			if (s.empty())
				flag = false;
			else if (s.top() != '[')
				flag = false;
			else
				s.pop();
			break;
		}
	}

	if (flag && s.empty())
		return true;
	else
		return false;
}
