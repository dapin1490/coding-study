#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main()
{
	int n;
	int* ar;
    int maxi;

    cin >> n;
    ar = new int [n];

    for (int i = 0; i < n; i++)
        cin >> *(ar + i);

    sort(ar, ar + n, cmp);

    maxi = *(ar + 0);
    for (int i = 1; i < n; i++) {
        *(ar + i) += i;
        if (*(ar + i) > maxi)
            maxi = *(ar + i);
    }

    cout << maxi + 2;

    delete[] ar;

    return 0;
}
