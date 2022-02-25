#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int cow[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int cnt = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int id, way;
		cin >> id >> way;
		if (cow[id] != -1 && cow[id] != way) {
			cnt++;
			cow[id] = way;
		}
		else if (cow[id] == -1) {
			cow[id] = way;
		}
	}

	cout << cnt;

	return 0;
}
