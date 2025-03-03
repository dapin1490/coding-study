#include <iostream>
#include <string>
using namespace std;

int di_root(string num);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		string n;
		
		cin >> n;

		if (n == "0")
			break;

		cout << di_root(n) << "\n";
	}

	return 0;
}

int di_root(string num)
{
	while (true) {
		int dr = 0;

		for (int i = 0; i < num.length(); i++)
			dr += (int(num.at(i)) - int('0'));

		if (dr >= 0 && dr <= 9)
			return dr;
		else
			num = to_string(dr);
	}
}
