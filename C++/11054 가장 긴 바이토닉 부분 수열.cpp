/*
이 문제에서 요구하는 수열은 특정 원소를 기준으로 왼쪽은 증가하는 수열, 오른쪽은 감소하는 수열입니다.
그러므로 왼쪽은 11053번 증가하는 부분 수열을, 오른쪽은 11722번 감소하는 부분 수열을 붙이면 바이토닉 부분 수열이 됩니다.
이때 증가하는 부분 수열의 마지막 원소와 감소하는 부분 수열의 마지막 원소가 중복되므로 길이를 합할 때 1을 빼야 합니다.

증가하는 부분 수열과 감소하는 부분 수열의 검사 방향이 다르다보니 검사와 최댓값 업데이트를 동시에 할 수는 없고,
검사를 모두 마친 후 최댓값을 따로 계산합니다.
*/

#include <iostream>
#include <vector>
using namespace std;

// 증가하는 수열 거꾸로 찾기 : 11722번에서 썼던 함수. 구분을 위해 이름을 바꾸었고 값을 반환받을 필요가 없어 void입니다.
void downfinder(int n);
// 증가하는 수열 앞에서부터 찾기 : 11053번에서 썼던 함수. 이유는 위와 같습니다.
void upfinder(int n);

vector<int> v;
vector<int> dn; // 감소하는 부분 수열의 길이 저장
vector<int> up; // 증가하는 부분 수열의 길이 저장
int t, cnt = 1;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> t;
	dn.resize(t, 1); // 초기화는 동일합니다
	up.resize(t, 1); // 초기화 동일
	for (int i = 0; i < t; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < t; i++) { // 부분 수열의 길이를 모두 구합니다. 증가하는 부분 수열은 앞에서부터, 감소하는 부분 수열은 뒤에서부터.
		upfinder(i);
		downfinder(t - 1 - i);
	}

	for (int i = 0; i < t; i++) { // 3, 4번 줄의 설명대로 (두 부분 수열의 길이 합 - 1)이 답이 되므로 이 값의 최댓값을 찾는 반복문과 선택문입니다.
		if (dn[i] + up[i] - 1 > cnt) {
			cnt = dn[i] + up[i] - 1;
		}
	}

	cout << cnt;

	return 0;
}

// 증가하는 수열 거꾸로 찾기 : t - 1부터 대입
void downfinder(int n)
{
	for (int i = n; i < t; i++) {
		if (v[i] < v[n] && dn[i] >= dn[n]) {
			dn[n] = dn[i] + 1;
		}
	}
}

// 증가하는 수열 앞에서부터 찾기 : 0부터 대입
void upfinder(int n)
{
	for (int i = n; i >= 0; i--) {
		if (v[i] < v[n] && up[i] >= up[n]) {
			up[n] = up[i] + 1;
		}
	}
}
