#include <iostream>
#include <vector>
using namespace std;

// 1 i x: Ai를 x로 바꾼다.
void change(vector<int>& vec, int i, int x);
// 2 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 짝수의 개수를 출력한다.
int even(vector<int>& vec, int l, int r);
// 3 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 홀수의 개수를 출력한다.
int odd(vector<int>& vec, int l, int r);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v(1);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		v.push_back(a);
	}

	int m;
	cin >> m;
	int evenNum;
	int oddNum;

	for (int i = 0; i < m; i++)
	{
		int q, l, r;
		cin >> q >> l >> r;

		switch (q)
		{
		case 1:
			change(v, l, r);
			break;
		case 2:
			evenNum = even(v, l, r);
			cout << evenNum << "\n";
			break;
		case 3:
			oddNum = odd(v, l, r);
			cout << oddNum << "\n";
			break;
		}
	}

	
	return 0;
}

// 1 i x: Ai를 x로 바꾼다.
void change(vector<int>& vec, int i, int x)
{
	vec[i] = x;
}

// 2 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 짝수의 개수를 출력한다.
int even(vector<int>& vec, int l, int r)
{
	int evens = 0;

	for (int i = l; i <= r; i++)
	{
		if (vec[i] % 2 == 0)
			evens++;
	}

	return evens;
}

// 3 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 홀수의 개수를 출력한다.
int odd(vector<int>& vec, int l, int r)
{
	int odds = 0;

	for (int i = l; i <= r; i++)
	{
		if (vec[i] % 2 == 1)
			odds++;
	}

	return odds;
}
