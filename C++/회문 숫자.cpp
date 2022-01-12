// 문제
// 사용자로부터 양의 정수를 입력받고 회문(palindrome) 숫자인지 확인하는 프로그램을 만드시오.
// 회문 숫자는 자릿수를 반대로 해도 원래 숫자와 같아지는 숫자를 의미함 (예를 들어 353, 376673, 등).

// 입력
// 첫번째 줄에 양의 정수 n이 주어진다.

// 출력
// "(입력받은 값) is a palindrome."
// "(입력받은 값) is not a palindrome."

#include <iostream>
using namespace std;

int main() {

  //Please Enter Your Code Here
  string num;
  cin >> num;
  
  int start = 0, last;
  last = num.length() - 1;
  bool flag = true;
  
  while (start <= last)
  {
    if (num.at(start) != num.at(last))
    {
      flag = false;
      break;
    }
    start++;
    last--;
  }
  
  if (flag)
    cout << num << " is a palindrome." << endl;
  else
    cout << num << " is not a palindrome." << endl;

  return 0;
}
