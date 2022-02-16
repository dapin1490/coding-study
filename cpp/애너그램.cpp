// 문제
// 두 단어가 애너그램(anagram)인지 검사하는 함수를 작성하라.
// 여기서 애너그램이란, 순서에 상관없이 단어에 포함된 문자가 모두 같다면,
// 두 단어는 애너그램이다(예, silent와 listen). 함수의 헤더는 다음과 같다.
// bool inAnagram(const string& s1, const string& s2)

// 입력
// 두 문자열 (영어로)

// 출력
// 애너그램인지 아닌지.

#include <iostream>
#include <string>
using namespace std;

// 개선사항 : 정렬하지 않고 비교할 방법 생각하기
// 개선했는데 점수가 안 나옴 : ?

bool inAnagram(const string& s1, const string& s2); // 애너그램 판단, 정렬 있음
bool inAnagram2(const string& s1, const string& s2); // 정렬 없이 판단
string sortStr(const string& s); // 문자열의 문자 정렬

int main() {

  string t1;
  string t2;
  cin >> t1;
  cin >> t2;
  
  if (inAnagram(t1, t2))
    cout << "애너그램 맞다." << endl;
  else
    cout << "애너그램 아니다." << endl;
  

  return 0;
}

bool inAnagram(const string& s1, const string& s2)
{
  string ss1 = sortStr(s1);
  string ss2 = sortStr(s2);
  
  if (ss1 == ss2)
    return true;
  else
    return false;
}

bool inAnagram2(const string& s1, const string& s2)
{
  // 글자 수가 같은지 먼저 확인 : 다르면 false
  if (s1.length() != s2.length())
    return false;
  
  // 글자 수가 같다면 한 쪽의 스트링을 키로 삼아 선형 탐색
  // 키와 같은 글자가 있다면 플래그 true 저장
  // 반복문 내에서 매번 키에 대한 검사가 끝날 때마다 플래그를 확인하며
  // 한 번이라도 플래그가 거짓인 채로 나온다면 false 반환
  for (int i = 0; i < s1.length(); i++)
  {
    bool flag = false; // 현재 키와 같은 글자가 있는지 저장하는 플래그
    char key = s1.at(i); // 탐색에 사용할 키
    
    for (int j = 0; j < s2.length(); j++)
    {
      if (key == s2.at(j)) // 키와 같은 글자가 있을 때
        flag = true; // 플래그 true
    }
    
    // cout << "index : " << i << "\nflag : " << ((flag)? "true" : "false") << endl;
    if (!flag) // flag == false일 경우
      return false; // 키와 같은 글자가 없었다는 뜻이므로 false 반환
  }
  
  // false를 반환하지 않고 반복문을 빠져나왔다면 true 반환
  return true;
}

string sortStr(const string& s) // 문자열의 문자 정렬
{
  int len = s.length();
  string arr = s;
  for (int i = 0; i < len - 1; i++) // IT 개론 교재 참고함 : 선택정렬
  {
    int minIndex = i;
    
    for (int j = i + 1; j < len; j++)
    {
      if (arr.at(j) < arr.at(minIndex))
        minIndex = j;
    }
    
    // 인덱스가 i인 글자가
    // 인덱스가 j인 글자보다 크다.
    // j 글자를 삭제하기 전에 임시 변수에 저장해놓고 삭제한다
    char temp = arr.at(minIndex);
    arr.erase(minIndex, 1);
    // i 자리에 j 글자를 추가한다
    arr.insert(i, 1, temp);
  }
  
  return arr;
}
