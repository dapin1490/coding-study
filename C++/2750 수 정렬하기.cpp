// 선택 정렬

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int> v;
	int idx = 0;

	for (int i = 0; i < t; i++) {
		cin >> idx;
		v.push_back(idx);
	}

	for (int i = 0; i < t - 1; i++) {
		idx = i;

		for (int j = i + 1; j < t; j++) {
			if (v[j] < v[idx])
				idx = j;
		}

		int temp = v[idx];
		v[idx] = v[i];
		v[i] = temp;
	}

	for (int i = 0; i < t; i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}
