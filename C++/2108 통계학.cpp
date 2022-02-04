#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cn[8002] = { 0 }; // 카운팅 배열
	int mean = 0; // 산술 평균 : 입력받을 때 전부 더한 다음 수의 개수로 나눔. 더블 주의
	int mid = 0; // 중앙값 : 최빈값을 구한 후 카운팅 배열을 누적하여 가운데 위치해야 하는 값을 구함
	int bin = 0; // 최빈값의 카운트 수
	int binnum = 0; // 최빈값 : 카운팅 배열을 누적하기 전 개수의 최댓값 찾기
	int ran = 0; // 범위 : maxi - mini;
	int maxi = -4010; // 범위를 찾기 위한 최댓값
	int mini = 4010; // 범위를 찾기 위한 최솟값
	int t; // 수의 개수
	cin >> t;
	int a; // 입력받기용 아무데나 쓸 변수

	// 입력 받기 그외 등등
	for (int i = 0; i < t; i++) {
		cin >> a;
		cn[a + 4000]++; // 개수 세기
		mean += a; // 총합 구하기
		if (a > maxi) // 최댓값
			maxi = a;
		if (a < mini) // 최솟값
			mini = a;
		if (cn[a + 4000] > bin) // 일단 최빈값 하나 구하기
		{
			binnum = a;
			bin = cn[a + 4000];
		}
	}

	// 평균과 범위
	ran = maxi - mini;
	mean = round(double(mean) / double(t));

	// 최빈값이 여러 개 있는지 확인
	bool multi = false;
	for (int i = 0; i < 8001; i++) {
		if (cn[i] == bin && i - 4000 != binnum) {
			multi = true;
			break;
		}
	}
	if (multi) {
		multi = false;
		for (int j = 0; j < 8001; j++) {
			if (cn[j] == bin && !multi) { // 가장 작은 최빈값
				multi = true;
			}
			else if (cn[j] == bin && multi) { // 가장 작은 최빈값 이후의 최빈값
				binnum = j - 4000;
				break; // 발견되자마자 업데이트하고 break해야 두 번째로 작은 최빈값이 저장됨
			}
		}
	}

	// 카운팅 누적하기
	int cnt = 0;
	a = 0;
	while (true) {
		if (cnt >= (t + 1) / 2) { // 누적 개수가 가운데 지점을 넘어서면 중앙값
			mid = a - 1 - 4000;
			break;
		}
		cnt += cn[a];
		a++;
	}

	// 출력
	cout << mean << "\n" << mid << "\n" << binnum << "\n" << ran;

	return 0;
}
