// 사용자로부터의 양의 정수를 입력받고 모든 자릿수의 합을 구하는 프로그램을 만드시오.

#include <iostream>
using namespace std;

int main() {

  int num;
  cin >> num;
  
  int sum = 0; // 합
  int div = 1; // 자릿수
  
  while (div <= num)
  {
    div = div * 10;
  }
  div = div / 10; // 입력받은 값이 만약 만의 자리까지 있는 수라면 div == 10000
  
  for (int i = div; i > 0; i = i / 10) // 반복을 거듭할 때마다 div의 자릿수가 하나씩 줄어든다
  {
    sum = sum + num / i; // 정수 연산이기 때문에 num / i의 몫만 sum에 더해진다
    num = num % i; // 이미 더해진 자릿수를 없앤다
  }
  cout << sum;

  return 0;
}
