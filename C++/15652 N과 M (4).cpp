#include <iostream>
#include <vector>
using namespace std;

int nvi[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
vector<int> v;
int mm, nn;
int idn;

void pr(int n, int m);

int main()
{
	cin >> nn >> mm;

	pr(nn, mm);

	return 0;
}

void pr(int n, int m)
{
	if (v.size() == m)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (nvi[i] >= m || (i + 1) < idn)
			continue;
		v.push_back(i + 1);
		idn = i + 1;
		nvi[i] += 1;
		pr(n, m);
		v.pop_back();
		idn = 0;
		nvi[i] -= 1;
	}
}
