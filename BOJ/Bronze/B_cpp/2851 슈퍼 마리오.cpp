#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans;
	int mush[10] = { 0 };

	cin >> mush[0];
	for (int i = 1; i < 10; i++) {
		cin >> mush[i];
		mush[i] += mush[i - 1];
	}

	for (int i = 0; i < 10; i++)
		mush[i] = 100 - mush[i];

	ans = mush[0];
	for (int i = 1; i < 10; i++) {
		if (abs(mush[i]) < abs(ans) || (abs(mush[i]) == abs(ans) && mush[i] < ans))
			ans = mush[i];
	}

	cout << 100 - ans;

	return 0;
}
