#include <iostream>
#include <queue> // 큐, 우선순위 큐
#include <utility> // pair
#include <deque> // 덱
using namespace std;

int when_print(); // 문제 풀이 함수

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; // 테스트케이스 개수

	cin >> t;

	for (int i = 0; i < t; i++) {
		int ans = when_print(); // 테스트케이스 연산 결과 반환

		cout << ans << "\n";
	}

	return 0;
}

int when_print()
{
	int n, m;
	int cnt = 0;
	deque<pair<int, int>> printer; // 실제 프린터 대기열
	priority_queue<int> pq; // 우선순위 대기열

	cin >> n >> m;

	for (int i = 0; i < n; i++) { // 대기열 입력
		int num;
		cin >> num;
		printer.emplace_back(num, i);
		pq.push(num);
	}

	while (!pq.empty()) { // 인쇄물이 남지 않을 때까지 인쇄
		pair<int, int> ptr_curr_page = printer.front();
		int pq_current_page = pq.top();

		if (ptr_curr_page.first == pq_current_page) { // 현재 인쇄 대기 인쇄물의 중요도가 실제 대기열과 우선순위 대기열에서 동일할 때 출력
			cnt++;
			pq.pop();
			printer.pop_front();

			if (ptr_curr_page.second == m) // 인쇄한 인쇄물의 순번이 문제에서 지정한 것과 같다면 정답 반환
				break;
		}
		else { // 올바르지 않은 인쇄물은 대기열 맨 뒤로 보냄
			printer.pop_front();
			printer.push_back(ptr_curr_page);
		}
	}

	return cnt;
}
