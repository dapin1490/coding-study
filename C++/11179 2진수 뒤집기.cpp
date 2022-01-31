#include <iostream>
using namespace std;

int main()
{
    int n; // 입력받은 십진법 수
    cin >> n;

    int ans = 0; // 답

    while (true) // 횟수를 알 수 없으니 조건부 반복으로 하기 위해 while 사용
    {
        // n을 직접 2로 나누어가면서 환산할 것이기 때문에 더이상 나눌 것이 없다면 종료
        if (n == 0)
            break;
        
        // n을 2로 나눈 나머지를 이전의 값에 더하고 다시 2를 곱하면 십진수가 된다.
        // 한 번 계산한 n은 매번 2로 버림나눗셈을 해서 업데이트해야 한다.
        ans = (ans + n % 2) * 2;
        n = n / 2;
    }

    cout << ans / 2;


    return 0;
}
