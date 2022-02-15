#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cnt = 0;
	string s;
	for (int j = 0; j < m; j++)
	{
		int ACGT[4] = { 0 };

		for (int i = 0; i < n; i++)
		{
			switch (v[i].at(j))
			{
			case 'A':
				ACGT[0]++;
				break;
			case 'C':
				ACGT[1]++;
				break;
			case 'G':
				ACGT[2]++;
				break;
			case 'T':
				ACGT[3]++;
				break;
			}
		}

		int idx = 0, cn = 0;
		for (int k = 0; k < 4; k++)
		{
			if (ACGT[k] > cn) {
				cn = ACGT[k];
				idx = k;
			}
		}

		cnt += (n - cn);
		switch (idx)
		{
		case 0:
			s += 'A';
			break;
		case 1:
			s += 'C';
			break;
		case 2:
			s += 'G';
			break;
		case 3:
			s += 'T';
			break;
		}
	}

	cout << s << "\n" << cnt;

	return 0;
}
