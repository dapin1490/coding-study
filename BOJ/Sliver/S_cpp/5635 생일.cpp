#include <iostream>
#include <algorithm>
using namespace std;

struct human {
	string name = "";
	int year = 0;
	int month = 0;
	int day = 0;
};

bool cmp(human a, human b) {
	if (a.year == b.year) {
		if (a.month == b.month)
			return a.day < b.day;
		else
			return a.month < b.month;
	}
	else
		return a.year < b.year;
}

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	human* people;

	cin >> n;

	people = new human[n];
	for (int i = 0; i < n; i++)
		cin >> (people + i)->name >> (people + i)->day >> (people + i)->month >> (people + i)->year;

	sort(people, people + n, cmp);

	cout << (people + n - 1)->name << "\n" << (people + 0)->name;

	delete[] people;

	return 0;
}
