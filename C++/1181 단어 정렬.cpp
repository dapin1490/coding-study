#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 좌표 정렬 함수 : 퀵 정렬
void qsort(vector<string>& v, int i, int j);

// 좌표를 입력받을 벡터
vector<string> vec;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; // 개수
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		if (find(vec.begin(), vec.end(), s) != vec.end()) {
			continue;
		}

		vec.push_back(s);
	}

	qsort(vec, 0, vec.size() - 1); // 정렬 함수 호출

	for (int i = 0; i < vec.size(); i++) { // 정렬 후 출력
		cout << vec[i] << "\n";
	}

	return 0;
}

// 좌표 정렬 함수 : 퀵 정렬
void qsort(vector<string>& v, int i, int j)
{
	if (i >= j) // 크기가 1이라면 리턴
		return;
	
	int p = (i + j) / 2; // 피벗
	int nexti = i; // 다음 호출에 쓸 i
	int nextj = j; // 다음 호출에 쓸 j

	vector<string> small; // 작은 단어 벡터
	vector<string> big; // 큰 단어 벡터

	for (int k = i; k <= j; k++) { // 전달받은 구간만큼
		if (k == p || v[k] == v[p]) // 피벗은 패스
			continue;

		if (v[k].length() > v[p].length()) // 길면 큰 단어
			big.push_back(v[k]);
		else if (v[k].length() < v[p].length()) // 짧으면 작은 단어
			small.push_back(v[k]);
		else { // 길이가 같으면 사전순
			if (v[k] > v[p]) // 크면 큰 단어
				big.push_back(v[k]);
			else if (v[k] < v[p]) // 작으면 작은 단어
				small.push_back(v[k]);
		}
	}

	small.push_back(v[p]); // 피벗은 작은 벡터 맨 뒤에 추가
	j = nextj - big.size();
	i = j + 1;
	small.insert(small.end(), big.begin(), big.end()); // 작은 벡터 큰 벡터 합치기

	for (int m = 0; m < small.size(); m++) { // 원본 벡터에 정렬된 값 업데이트
		v[m + nexti] = small[m];
	}

	// 다음 호출
	qsort(v, nexti, j);
	qsort(v, i, nextj);
}
