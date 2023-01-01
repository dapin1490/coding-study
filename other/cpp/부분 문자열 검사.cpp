// 문제
// 문자열 s1이 문자열 s2의 부분 문자열인지 검사하는 다음 함수를 작성하세요.
// 만약 일치하는 문자가 있다면 함수는 s2의 첫번째 인덱스(일치 문자의 위치 값)을 반환하고 그렇지 않으면 -1을 반환한다.
// int indexOf( const string& s1, const string& s2)

// 입력
// 첫째 줄에 첫번째 문자열 s1이 주어지고, 두번째 줄에 두번째 문자열 s2가 주어진다.

// 출력
// 첫번째 줄에 s2의 첫번째 인덱스(일치 문자의 위치 값)을 출력한다.

#include <iostream>
#include <string>
using namespace std;

int indexOf(const string& s1, const string& s2);

int main() {

  //Please Enter Your Code Here
  string shotxt;
  string longtxt;
  getline(cin, shotxt);
  getline(cin, longtxt);
  cout << indexOf(shotxt, longtxt) << endl;

  return 0;
}

int indexOf(const string& s1, const string& s2)
{
  // 1. 짧은 텍스트의 길이를 구한다.
  // 2. 그 길이만큼 긴 텍스트의 앞에서부터 구간별로 잘라서 비교한다
  int shotlen = s1.length();
  bool plag = true;
  int j = 0;
  while (plag)
  {
    string compare = "";
    for (int i = j; i < (shotlen+j); i++)
    {
      compare += s2.at(i);
    }
    if ((s1 == compare) && (j < s2.length() - shotlen))
    {
      return j;
    }
    else if (j < s2.length() - shotlen)
      j++;
    else
      return -1;
  }
}
