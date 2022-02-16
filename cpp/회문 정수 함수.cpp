// 문제
// 다음 헤더를 사용하여 함수를 작성하세요.
// isPalindrome을 구현하기 위해 reverse 함수를 사용하세요.
// 수를 역으로 했을 때 같은 값이면 회문이 된다. 사용자가 3개의 정수를 입력하고 입력한 정수가 각각 회문인지를 알려주는 테스트 프로그램을 작성하세요.
// int reverse(int number) : 정수를 역으로 한 값을 반환, 즉, reverse(456)은 654를 반환
// bool isPalindrome(int number) : 수가 회문이면 참을 반환

// 입력
// 첫째 줄, 둘째 줄, 셋째 줄에 각각 정수 M이 주어진다.

// 출력
// 첫째 줄, 둘째 줄, 셋째 줄에 각각 yes 또는 no를 출력한다.

#include <iostream>
using namespace std;

int reverse(int number)
{
  // 정수의 자릿수를 먼저 알아내고
  // 자릿수에 따라 나머지 연산으로 한 자리씩 떼어내기
  // 거꾸로 곱해서 더하기
  int len = 1; // 정수의 자릿수 구하기. 정수보다 한 자리 많은 10의 거듭제곱수.
  for (int i = 1; i <= number; i *= 10)
  {
    len = i;
  }

  int arran = 0; // 앞뒤가 바뀐 숫자를 저장할 변수
  // 1. 큰 수부터 나누게 될 것이다.
  // 2. 큰 수가 앞에 먼저 더해진다.
  // 3. len은 반복문 진행에 따라 작아지고
  // 4. 더해지기 위해 곱하는 값은 커진다.
  // 반복문 종료 조건은?
  // 5. for, len >= 1
  int k = 10;
  for (int j = len; j >= 1; j /= 10)
  {
    arran += (number % k) * j;
    number /= k;
  }
  
  return arran;
}

bool isPalindrome(int number)
{
  if (number == reverse(number))
    return true;
  else
    return false;
}

int main() {

  //Please Enter Your Code Here
  int num;
  for (int i = 0; i < 3; i++)
  {
    cin >> num;
    if (isPalindrome(num))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}
