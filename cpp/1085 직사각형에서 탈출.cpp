#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d[4] = { 0, 0, 0, 0 }; // 동, 서, 북, 남 거리
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	d[0] = w - x; // 동
	d[1] = w - d[0]; // 서
	d[2] = h - y; // 북
	d[3] = h - d[2]; // 남
	
	int min = 1000;
	for (int i = 0; i < 4; i++)
	{
		if (d[i] < min)
			min = d[i];
	}

	cout << min;

	return 0;
}
