// 참고 : 15650 N과 M (2)
// 백트래킹 사용

#include <iostream>
#include <vector>
using namespace std;

vector<bool> nvi; // 카드 사용 여부 저장
vector<int> v; // 더해야 할 3장의 카드 저장
vector<int> card; // 전체 카드 저장
int maxsum = 0; // 답
int m, n; // 입력값
int idx = 0; // 최근 사용한 카드의 인덱스 저장

void jack(); // 2798 블랙잭

int main()
{
	cin >> n >> m;
	nvi.resize(n, 0); // false로 초기화

	// 카드 입력받기
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		card.push_back(temp);
	}

	jack(); // 2798 블랙잭

	cout << maxsum; // 답 출력

	return 0;
}

// 2798 블랙잭
void jack()
{
	// 3장을 다 뽑았을 때
	if (v.size() == 3)
	{
		int tempsum = 0; // 지금 뽑은 3장의 합 저장
		for (int i = 0; i < 3; i++) {
			tempsum += v.at(i);
		}
		if (tempsum > maxsum && tempsum <= m) // 정답 조건에 맞으면 답에 저장
			maxsum = tempsum;
		return;
	}

	// 카드 3장 뽑기
	for (int i = 0; i < n; i++)
	{
		if (nvi[i] || i < idx) // 중복 방지, 오름차순
			continue;
		v.push_back(card.at(i)); // 더해야 할 카드에 추가
		idx = i; // 인덱스 기록
		nvi[i] = 1; // 사용 여부 기록
		jack(); // 재귀 호출
		v.pop_back(); // 사용한 카드 버림
		idx = 0; // 인덱스 초기화
		nvi[i] = 0; // 사용 여부 초기화
	}
}
