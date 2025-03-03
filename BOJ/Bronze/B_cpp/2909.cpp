#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int coin;
	int price;
	
	cin >> price >> coin;

	cout << int(round(price * pow(0.1, coin)) * pow(10, coin));

	return 0;
}
