#include <iostream>
#include <vector>
using namespace std;

// 좌표 정렬 함수 : 퀵 정렬
void qsort(vector<vector<int>>& ve, int i, int j);

// 좌표를 입력받을 벡터
vector<vector<int>> vec;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; // 개수
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		vector<int> tm;
		tm.push_back(a);
		tm.push_back(b);
		vec.push_back(tm);
	}

	qsort(vec, 0, t - 1); // 정렬 함수 호출

	for (int i = 0; i < t; i++) { // 정렬 후 출력
		cout << vec[i][0] << " " << vec[i][1] << "\n";
	}

	return 0;
}

// 좌표 정렬 함수 : 퀵 정렬
void qsort(vector<vector<int>>& v, int i, int j)
{
	if (i >= j) // 크기가 1이라면 리턴
		return;
	
	int p = (i + j) / 2; // 피벗
	int nexti = i; // 다음 호출에 쓸 i
	int nextj = j; // 다음 호출에 쓸 j

	vector<vector<int>> small;
	vector<vector<int>> big;

	for (int k = i; k <= j; k++) {
		if (k == p)
			continue;

		if (v[k][1] > v[p][1])
			big.push_back(v[k]);
		else if (v[k][1] < v[p][1])
			small.push_back(v[k]);
		else {
			if (v[k][0] > v[p][0])
				big.push_back(v[k]);
			else if (v[k][0] < v[p][0])
				small.push_back(v[k]);
		}
	}

	small.push_back(v[p]);
	j = nextj - big.size();
	i = j + 1;
	small.insert(small.end(), big.begin(), big.end());

	for (int m = 0; m < small.size(); m++) {
		v[m + nexti].swap(small[m]);
	}

	// 다음 호출
	qsort(v, nexti, j);
	qsort(v, i, nextj);
}
