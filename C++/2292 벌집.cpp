#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int layer = 1; // 층 수
	int total = 1; // 층의 최대 주소

	while (n > total)
	{
		total += layer * 6;
		layer++;
	}

	cout << layer;

	
	return 0;
}
