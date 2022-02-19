#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string work[] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };
	double cwork[7] = { 0 };
	map<string, int> m;
	m.insert(pair<string, int>("Re", 0));
	m.insert(pair<string, int>("Pt", 0));
	m.insert(pair<string, int>("Cc", 0));
	m.insert(pair<string, int>("Ea", 0));
	m.insert(pair<string, int>("Tb", 0));
	m.insert(pair<string, int>("Cm", 0));
	m.insert(pair<string, int>("Ex", 0));

	double cnt = 0;
	while (true) {
		string n;
		cin >> n;

		if (cin.eof())
			break;
		
		cnt++; // 전체 개수 세기
		m[n] += 1; // 개별 개수 세기
	}

	for (int i = 0; i < 7; i++) {
		cwork[i] = double(m[work[i]]) / cnt;
		cout << fixed << setprecision(2) << work[i] << " " << m[work[i]] << " " << cwork[i] << "\n";
	}
	cout << "Total " << int(cnt) << " 1.00";

	return 0;
}
