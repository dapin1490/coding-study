#include <iostream>
#include <vector>
using namespace std;

int find_winner();

vector<int> v;
int dasom;
int n, cnt, winner;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	if (n < 2) {
		cout << 0;
		return 0;
	}
	v.resize(n - 1);

	cin >> dasom;

	for (int i = 0; i < n - 1; i++)
		cin >> v[i];
	
	cnt = 0;
	winner = find_winner();

	while (v[winner] >= dasom) {
		dasom++;
		cnt++;
		v[winner]--;

		winner = find_winner();
	}

	cout << cnt;

	return 0;
}

int find_winner()
{
	int maxi = 0;
	for (int i = 1; i < n - 1; i++)
		maxi = (v[i] > v[maxi]) ? i : maxi;
	return maxi;
}
