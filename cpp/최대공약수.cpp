// 두 정수 m과 n의 최대 공약수를 구하는 프로그램을 만드시오.

#include <iostream>
using namespace std;

int main() {

  int m, n;
  cin >> m >> n;
  
  if (m < n) // m이 더 큰 수가 되게 한다.
  {
    int temp = m;
    m = n;
    n = temp;
  }
  
  int maxdiv; // 최대공약수
  
  for (int i = 1; (i <= m) && (i <= n); i++) // 1부터 시작해서 m 또는 n보다 작거나 같은 값이 될 때까지 반복
  {
    if (m % i == 0 && n % i == 0) // m과 n이 모두 i로 나누어 떨어진다면 최대공약수 변수에 저장한다.
      maxdiv = i;
  }
  
  cout << maxdiv;
  

  return 0;
}
