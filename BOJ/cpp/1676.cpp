#include <iostream>
using namespace std;

int count_ten(int n);

int main()
{
    // 빠른 입출력
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;
    cout << count_ten(n);

    return 0;
}

int count_ten(int n)
{
    int two, five;

    two = 0;
    five = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (true) {
            if (temp == 0 || temp % 2 != 0)
                break;
            two++;
            temp /= 2;
        }
        temp = i;
        while (true) {
            if (temp == 0 || temp % 5 != 0)
                break;
            five++;
            temp /= 5;
        }
    }

    return min(two, five);
}
