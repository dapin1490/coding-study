#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 퀵 정렬
void st(int i, int j);

// 순서와 나이
vector<vector<int>> id;
// 순서(=인덱스)와 이름
vector<string> name;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> v;
		v.push_back(i);
		int age;
		string na;
		cin >> age >> na;
		v.push_back(age);
		id.push_back(v);
		name.push_back(na);
	}

	st(0, t - 1);

	for (int i = 0; i < t; i++)
		cout << id[i][1] << " " << name[id[i][0]] << "\n";
	
	return 0;
}

// 퀵 정렬
void st(int i, int j)
{
	if (i >= j)
		return;

	int p = (i + j) / 2;
	int p_age = id[p][1];
	int p_id = id[p][0];
	int ni = i, nj = j;

	vector<vector<int>> small;
	vector<vector<int>> big;

	for (int k = i; k <= j; k++) {
		if (k == p)
			continue;

		if (id[k][1] > p_age)
			big.push_back(id[k]);
		else if (id[k][1] < p_age)
			small.push_back(id[k]);
		else {
			if (id[k][0] > p_id)
				big.push_back(id[k]);
			else if (id[k][0] < p_id)
				small.push_back(id[k]);
		}
	}

	small.push_back(id[p]);
	j = nj - big.size();
	i = j + 1;
	small.insert(small.end(), big.begin(), big.end());

	for (int m = 0; m < small.size(); m++)
		id[m + ni] = small[m];

	st(ni, j);
	st(i, nj);
}
