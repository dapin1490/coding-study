#include <iostream>
using namespace std;

void worktime(int time[6], int ans[3]);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t[6] = { 0 };
	int a[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++)
			cin >> t[j];
		worktime(t, a);
		cout << a[0] << " " << a[1] << " " << a[2] << "\n";
	}

	return 0;
}

void worktime(int time[6], int ans[3])
{
	long long start, end;

	start = 0;
	end = 0;
	for (int i = 0; i < 3; i++) {
		start = (start + time[i]) * 60;
		end = (end + time[i + 3]) * 60;
	}

	start /= 60;
	end /= 60;

	end -= start;

	ans[0] = end / (60 * 60);
	end %= (60 * 60);
	ans[1] = end / 60;
	end %= 60;
	ans[2] = end;

	return;
}
