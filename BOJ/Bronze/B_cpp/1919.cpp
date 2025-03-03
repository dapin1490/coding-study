#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char a[1001];
	char b[1001];
	cin >> a >> b;

	sort(a, a + strlen(a));
	sort(b, b + strlen(b));

	int cnt = 0, i = 0, j = 0;
	int lena = strlen(a), lenb = strlen(b);
	while (true) {
		if (i >= lena || j >= lenb)
			break;

		if (a[i] == b[j]) {
			cnt += 2;
			i++;
			j++;
		}
		else {
			if (a[i] < b[j])
				i++;
			else
				j++;
		}
	}

	cout << lena + lenb - cnt;

	return 0;
}
