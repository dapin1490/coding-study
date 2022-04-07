#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int* ar;

    cin >> n >> m;
    ar = new int[n + m];

    for (int i = 0; i < n + m; i++)
        cin >> *(ar + i);

    sort(ar, ar + n + m);

    for (int i = 0; i < n + m; i++)
        cout << *(ar + i) << " ";
    
    delete[] ar;

	return 0;
}
