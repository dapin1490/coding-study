/*
참고한 문제 11053 가장 긴 증가하는 부분 수열
논리 활용 : 11053 문제에서는 첫 번째 원소에서부터 key로 삼아 증가하는 부분 수열을 찾아냈다.
그렇다면 맨 마지막 원소를 key로 삼아 정 반대 방향으로 증가하는 부분 수열을 찾으면 그것이 결과적으로 감소하는 부분 수열이 되지 않을까?
라는 발상으로 11053번 코드를 조금 변형했습니다. 11053번 문제에서 달라진 코드에만 주석을 추가했습니다.
*/

#include <iostream>
#include <vector>
using namespace std;

// 증가하는 수열 거꾸로 찾기
int finder(int n);

vector<int> v;
vector<int> d;
int t, cnt = 1;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> t;
	d.resize(t, 1);
	for (int i = 0; i < t; i++) {
		cin >> a;
		v.push_back(a);
	}

	a = t - 1; // 뒤에서부터 찾아야 하기 때문에 a를 최댓값으로 준다.
	while (a >= 0) { // a가 음수가 되면 모든 원소를 검사했다는 뜻이다.
		int k = finder(a);
		if (cnt < k) {
			cnt = k;
		}
		a--; // 뒤에서부터 오기 때문에 a는 감소해야 한다.
	}

	cout << cnt;

	return 0;
}

// 증가하는 수열 거꾸로 찾기
int finder(int n)
{
	for (int i = n; i < t; i++) { // 현재 원소(key) 이후의 값(value) 중에서
		if (v[i] < v[n] && d[i] >= d[n]) { // key보다 크고 부분 수열의 길이도 크거나 같은 value가 있으면
			d[n] = d[i] + 1; // key의 부분 수열 길이 값을 업데이트한다. +1인 이유는 11053번과 같은 논리이다.
		}
	}

	return d[n];
}
