#include <iostream>
using namespace std;

bool vowel(char c);
string dokkaebi(string n);

int main() {
  string s;

  while (true) {
    cin >> s;
    if (s == "#")
      break;

    cout << dokkaebi(s) << "\n";
  }
  
  return 0;
}

bool vowel(char c)
{
  switch (c) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      return true;
    default:
      return false;
  }
}

string dokkaebi(string n)
{
  string key = n;
  while (true) {
    if (vowel(n.at(0)))
      break;

    n += n.at(0);
    n.erase(0, 1);

    if (n == key) // 단어에 모음이 없어서 한 글자씩 뒤로 보내다가 원래 단어로 돌아온 경우
      break;
  }

  n += "ay";
  return n;
}
