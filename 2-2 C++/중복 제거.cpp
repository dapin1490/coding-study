// 문자열에서 중복되는 문자를 제거해서 문자 중복이 없게 만드는 프로그램을 만드세요. (즉, AAABBBBCCDEFAA를 매개변수로 넣었다면, ABCDEF를 리턴)

#include <iostream>
#include <string>
using namespace std;

int main() {

  string text; // 검사할 문자열
  cin >> text;
  
  string arran = ""; // 중복 제거 후 문자열
  
  for (int j = 0; j < text.length(); j++)
  {
    for (int k = 0; k < text.length(); k++)
    {
      if (text.at(j) == text.at(k) && j < k)
        text.at(k) = ' '; // 중복되는 문자가 있다면 공백으로 대체
    }
  }
  
  for (int m = 0; m < text.length(); m++)
  {
    if (text.at(m) != ' ') // 공백이 아닌 문자만 arran에 추가한다
      arran += text.at(m);
  }
  
  cout << arran;

  return 0;
}
