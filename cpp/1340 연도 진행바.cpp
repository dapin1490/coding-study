#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string sm, sd, sh;
	int year;
	cin >> sm >> sd >> year >> sh;
	int mon = 1, day = 1, minute = 1;
	bool leap = false;

	switch (sm.at(0)) {
	case 'J': //  January, June, July
		if (sm == "January") { mon = 1; }
		else if (sm == "June") { mon = 6; }
		else { mon = 7; }
		break;
	case 'F': // February
		mon = 2; break;
	case 'M': // March, May
		if (sm == "March") { mon = 3; }
		else { mon = 5; }
		break;
	case 'A': //  April, August
		if (sm == "April") { mon = 4; }
		else { mon = 8; }
		break;
	case 'S': // September
		mon = 9; break;
	case 'O': // October
		mon = 10; break;
	case 'N': // November
		mon = 11; break;
	case 'D': // December
		mon = 12; break;
	}

	day = stoi(sd.substr(0, 2)) - 1;
	minute = stoi(sh.substr(0, 2)) * 60 + stoi(sh.substr(3, 2));

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		leap = true;

	for (int i = 1; i < mon; i++) {
		switch (i) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			day += 31; break;
		case 4: case 6: case 9: case 11:
			day += 30; break;
		case 2:
			if (leap) day += 29;
			else day += 28;
		}
	}

	double total = double(day) + double(minute) / 1440.0;

	if (leap)
		cout << setprecision(15) << total / 366.0 * 100.0;
	else
		cout << setprecision(15) << total / 365.0 * 100.0;

	return 0;
}
