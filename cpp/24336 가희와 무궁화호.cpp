#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

double calc(string start, string end);

map<string, double> table = { { "Seoul", 0.0 }, { "Yeongdeungpo", 9.1 },
	{ "Anyang", 23.9 }, { "Suwon", 41.5 }, { "Osan", 56.5 }, { "Seojeongri", 66.5 },
	{ "Pyeongtaek", 75.0 }, { "Seonghwan", 84.4 }, { "Cheonan", 96.6 },
	{ "Sojeongni", 107.4 }, { "Jeonui", 114.9 }, { "Jochiwon", 129.3 },
	{ "Bugang", 139.8 }, { "Sintanjin", 151.9 }, { "Daejeon", 166.3 },
	{ "Okcheon", 182.5 }, { "Iwon", 190.8 }, { "Jitan", 196.4 },
	{ "Simcheon", 200.8 }, { "Gakgye", 204.6 }, { "Yeongdong", 211.6 },
	{ "Hwanggan", 226.2 }, { "Chupungnyeong", 234.7 }, { "Gimcheon", 253.8 },
	{ "Gumi", 276.7 }, { "Sagok", 281.3 }, { "Yangmok", 289.5 },
	{ "Waegwan", 296.0 }, { "Sindong", 305.9 }, { "Daegu", 323.1 },
	{ "Dongdaegu", 326.3 }, { "Gyeongsan", 338.6 }, { "Namseonghyeon", 353.1 },
	{ "Cheongdo", 361.8 }, { "Sangdong", 372.2 }, { "Miryang", 381.6 },
	{ "Samnangjin", 394.1 }, { "Wondong", 403.2 }, { "Mulgeum", 412.4 },
	{ "Hwamyeong", 421.8 }, { "Gupo", 425.2 }, { "Sasang", 430.3 },
	{ "Busan", 441.7 }
};
vector<string> name;
vector<pair<string, string>> tm;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, q;

	cin >> n >> q;
	name.resize(n);
	::tm.resize(n, make_pair("", ""));
	// 예약어와 변수명이 겹치면 컴파일 에러가 날 수 있다.
	// 변수 앞에 ::을 붙이면 해결된다. std namespace가 아니고 전역변수라는 뜻.

	for (int i = 0; i < n; i++)
		cin >> name[i] >> ::tm[i].first >> ::tm[i].second;

	for (int i = 0; i < q; i++) {
		string s, e;
		cin >> s >> e;
		cout << setprecision(10) << calc(s, e) << "\n";
	}

	return 0;
}

double calc(string start, string end)
{
	// start에서는 출발 시간, end에서는 도착 시간 필요
	// 출발 시간은 pair.second, 도착 시간은 pair.first
	double timelen;
	double dist;

	int sid = find(name.begin(), name.end(), start) - name.begin();
	int eid = find(name.begin(), name.end(), end) - name.begin();
	string stime = ::tm[sid].second;
	string etime = ::tm[eid].first;

	double sh = stoi(stime.substr(0, 2));
	double sm = stoi(stime.substr(3, 2));
	double eh = stoi(etime.substr(0, 2));
	double em = stoi(etime.substr(3, 2));

	if (sh > eh) // 날짜 바뀜
		eh += 24;

	if (sm <= em) // 내림 필요 없음
		timelen = (eh - sh) + (em - sm) / 60;
	else { // 내림 필요함
		eh -= 1;
		em += 60;
		timelen = (eh - sh) + (em - sm) / 60;
	}

	dist = abs(table[end] - table[start]);

	return dist / timelen;
}
