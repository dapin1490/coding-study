#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    const int trueN = n;

    int a = trueN / 10;
    int b = trueN % 10;
    n = ((n % 10) * 10) + ((a + b) % 10);
    int count = 1;

    while (true)
    {
        if (trueN == 0 || trueN == n)
            break;

        a = n / 10;
        b = n % 10;

        n = ((n % 10) * 10) + ((a + b) % 10);
        count++;
    }

    cout << count;


    return 0;
}