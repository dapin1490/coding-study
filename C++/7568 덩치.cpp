#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n;

void dc();

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> xy;
		int x, y;
		cin >> x >> y;
		xy.push_back(x);
		xy.push_back(y);
		xy.push_back(1);
		v.push_back(xy);
	}

	dc();

	for (int i = 0; i < n; i++) {
		cout << v.at(i).at(2) << " ";
	}
	
	return 0;
}

void dc()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v.at(i).at(0) < v.at(j).at(0) && v.at(i).at(1) < v.at(j).at(1))
				v.at(i).at(2) += 1;
		}
	}
}
