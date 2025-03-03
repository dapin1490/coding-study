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
		layer++;
		total += layer;
	}
	layer++; // 층의 분모 분자 합은 층 수보다 1 큼

	int div = total - n + 1; // 분모

	if (layer % 2 == 1)
		cout << layer - div << "/" << div;
	else
		cout << div << "/" << layer - div;
	
	
	return 0;
}
