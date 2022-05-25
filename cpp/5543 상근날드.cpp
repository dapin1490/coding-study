#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int menu[5] = { 0 };
	for (int i = 0; i < 5; i++)
		cin >> menu[i];

	cout << min(menu[0], min(menu[1], menu[2])) + min(menu[3], menu[4]) - 50;

	return 0;
}
