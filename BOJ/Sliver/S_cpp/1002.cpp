#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double PI = 3.14;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // 두 점 사이 거리
		double r = r1 + r2; // 반지름의 합
		double small = min(r1, r2);
		double big = max(r1, r2);

		/* 1. 큰 원 안에 작은 원이 있고 교점이 없음(0)
		>> big > d + small
		2-1. 큰 원 안에 작은 원이 있고 교점이 1개 있음(1)
		>> big == d + small
		2-2. 큰 원 안에 작은 원이 있고 교점이 2개 있음(2)
		>> big < d + small
		2-3. 두 원이 완전히 겹침(-1)
		>> r1 == r2 && d == 0
		3. 두 원이 2개의 점에서 만남(2)
		>> d > big && d < r
		4. 두 원이 1개의 점에서 외접함(1)
		>> d == r
		5. 두 원이 만나지 않음(0)
		>> d > r */
		if (d == 0 && r1 == r2)
			cout << -1 << "\n";
		else if (big > d + small || d > r)
			cout << 0 << "\n";
		else if (d == r || big == d + small)
			cout << 1 << "\n";
		else if (big < d + small || (d > big && d < r))
			cout << 2 << "\n";
	}

	return 0;
}
