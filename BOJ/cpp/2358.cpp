#include <iostream>
#include <map>
using namespace std;

/*
* x축이나 y축에 평행한 직선이라면 x좌표나 y좌표만 같으면 그만임.
* 고로 x좌표와 y좌표를 따로 카운팅해서 조합만 하면 됨.
* 예상되는 반례: 같은 좌표가 여러 번 주어져서 그 점끼리도 직선으로 간주되는 것
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    map<int, int> xcor;
    map<int, int> ycor;
    int n, temp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (xcor.find(temp) == xcor.end())
            xcor[temp] = 1;
        else
            xcor[temp]++;
        cin >> temp;
        if (ycor.find(temp) == ycor.end())
            ycor[temp] = 1;
        else
            ycor[temp]++;
    }

    temp = 0;
    for (pair<int, int> p : xcor)
        temp += (p.second >= 2 ? 1 : 0);
    for (pair<int, int> p : ycor)
        temp += (p.second >= 2 ? 1 : 0);

    cout << temp;

    return 0;
}