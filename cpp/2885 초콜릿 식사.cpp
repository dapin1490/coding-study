#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;
	int eat_choco = k;

	while (true) {
		if (k == 0)
			break;
		v.push_back(k % 2);
		k /= 2;
	}

	int buy_choco = pow(2, v.size());
	if (eat_choco * 2 == buy_choco) {
		cout << eat_choco << " " << 0;
		return 0;
	}

	int idx = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) {
			idx = v.size() - i;
			break;
		}
	}

	cout << buy_choco << " " << idx;

	return 0;
}
