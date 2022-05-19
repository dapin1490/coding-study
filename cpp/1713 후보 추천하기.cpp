#include <iostream>
#include <algorithm>
using namespace std;

struct human {
	int number;
	int order;
	int cnt;
};

int findPic(human* p, int n, int number);
int findDropout(human* p, int n);
int cmp(human a, human b) { return a.number < b.number; }

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, vote, seat;
	int voted[101] = { 0 };
	human h;
	human* pic;

	cin >> n >> vote;
	pic = new human[n];
	for (int i = 0; i < n; i++)
		(pic + i)->number = 0;
	seat = 0; // 1. 학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.

	for (int i = 0; i < vote; i++) {
		int num, idx;
		cin >> num; // 2. 어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.

		voted[num]++;
		idx = findPic(pic, n, num);

		if (idx != -1) { // 4. 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
			(pic + idx)->cnt++;
		}
		else {
			if (seat < n) { // 빈자리 있음
				(pic + seat)->number = num;
				(pic + seat)->cnt = voted[num];
				(pic + seat)->order = i;
				seat++;
			}
			else { // 3. 비어있는 사진틀이 없는 경우
				int dro = findDropout(pic, n);
				
				voted[(pic + dro)->number] = 0; // 5. 사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
				(pic + dro)->number = num;
				(pic + dro)->cnt = voted[num];
				(pic + dro)->order = i;
			}
		}
	}

	sort(pic, pic + n, cmp);

	for (int i = 0; i < n; i++) {
		if ((pic + i)->number == 0)
			continue;
		cout << (pic + i)->number << " ";
	}

	delete[] pic;

	return 0;
}

int findPic(human* p, int n, int number)
{
	for (int i = 0; i < n; i++) {
		if ((p + i)->number == number)
			return i;
	}

	return -1;
}

int findDropout(human* p, int n)
{
	bool multidrop = false;
	int min_cnt, min_order, out_human_idx;

	min_cnt = (p + 0)->cnt;
	min_order = (p + 0)->order;
	out_human_idx = 0;

	for (int i = 1; i < n; i++) {
		if (((p + i)->cnt < min_cnt) || ((p + i)->cnt == min_cnt && (p + i)->order < min_order)) {
			min_cnt = (p + i)->cnt;
			min_order = (p + i)->order;
			out_human_idx = i;
		}
	}

	return out_human_idx;
}
