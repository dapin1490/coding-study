#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(void)
{
    int a = 0;
    v.push_back(1); // 출력을 위헤 첫 번째 요소로 1 추가
    v.push_back(0); // 0번째 피보나치
    v.push_back(1); // 1번째 피보나치
    v.push_back(1); // 2번째 피보나치
    
    // 첫 번째 요소에 1을 추가했기 때문에 모든 인덱스가 1씩 밀림
    for (int i = 3; i <= 40; i++) {
        a = v[i] + v[i - 1];
        v.push_back(a);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a;
        cout << v[a] << " " << v[a + 1] << "\n";
    }

	return 0;
}
