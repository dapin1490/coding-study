#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cn[10001] = { 0 };
	int t;
	cin >> t;
	int a;

	// 입력 받기 + 개수 세기
	for (int i = 0; i < t; i++) {
		cin >> a;
		cn[a]++;
	}

	// 출력하기
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < cn[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}
