#include <iostream>
using namespace std;

char intensity(int r, int g, int b);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int h, w;

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int r, g, b;
			cin >> r >> g >> b;

			cout << intensity(r, g, b);
		}
		cout << "\n";
	}

	return 0;
}

char intensity(int r, int g, int b)
{
	int its = 2126 * r + 7152 * g + 722 * b;

	if (its < 510000)
		return '#';
	else if (its < 1020000)
		return 'o';
	else if (its < 1530000)
		return '+';
	else if (its < 2040000)
		return '-';
	else
		return '.';
}
