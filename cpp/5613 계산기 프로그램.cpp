#include <iostream>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char sb;
	int temp, inp;

	cin >> temp; // 처음은 숫자

	while (true) {
		cin >> sb; // 그 다음은 기호

		if (sb == '=')
			break;

		cin >> inp; // 등호가 아니라면 그 다음은 숫자

		switch (sb) {
		case '+': temp = temp + inp; break;
		case '-': temp = temp - inp; break;
		case '*': temp = temp * inp; break;
		case '/': temp = temp / inp; break;
		}
	}

	cout << temp;

	return 0;
}
