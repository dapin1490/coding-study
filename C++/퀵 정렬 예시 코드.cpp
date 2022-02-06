#include <iostream>
#include <algorithm>
using namespace std;

void qsort(int list[], int i, int j);
int s = 12;
int ar[] = { 5, 9, 6, 9, 2, 9, 1, 3, 7, 10, 4, 8 };
int main()
{
	qsort(ar, 0, s - 1);

	for (int i = 0; i < s; i++)
		cout << ar[i] << " ";
	
	return 0;
}

void qsort(int list[], int i, int j)
{
	int p = (i + j) / 2;
	int ni = i; // 다음 호출에 쓸 i
	int nj = j; // 다음 호출에 쓸 j

	if (i >= j)
		return;

	while (i <= j) {
		while (list[i] < list[p]) {
			i++;
		}

		while (list[j] > list[p]) {
			j--;
		}

		if (i <= j) {
			swap(list[i], list[j]);

			cout << "swapped i " << i << " and j " << j << "\n";
			for (int i = 0; i < s; i++)
				cout << ar[i] << " ";
			cout << "\n";

			i++;
			j--;
		}
	}

	qsort(list, ni, j);
	qsort(list, i, nj);
}
