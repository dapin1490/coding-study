#include <iostream>
#include <string>
using namespace std;

int main() {

  // 알파벳의 수를 세기 위해 26 * 2 칸 배열 생성
  // 앞부분은 소문자 뒷부분은 대문자
  // 한 글자씩 스캔
  // 소문자/대문자부터 판단하고
  // 맞는 자리 찾아서 개수 배열 증가
  // 검사 후 배열에서 가장 큰 값 찾기
  // 최대값이 여러개일 경우의 if 필요함
  
  int abc[52]; // 알파벳 개수 저장 : 0~25 소문자 26~51 대문자
  for (int i = 0; i < 52; i++)
    abc[i] = 0; // 개수 초기화
  
  string text; // 입력받을 텍스트
  cin >> text;
  
  int len = text.length();
  
  for (int i = 0; i < len; i++)
  {
    if (text.at(i) >= 'a' && text.at(i) <= 'z')
    {
      // 소문자
      int n = text.at(i) - 'a';
      abc[n] = abc[n] + 1;
    }
    else if (text.at(i) >= 'A' && text.at(i) <= 'Z')
    {
      // 대문자
      int m = text.at(i) - 'A' + 26;
      abc[m] = abc[m] + 1;
    }
  }
  
  int max = 0; // 가장 많이 나온 글자 수
  int maxIndex = 0; // 가장 많이 나온 글자
  char maxChar = 'a';
  bool same = false; // 최대값 중복
  for (int i = 0; i < 52; i++)
  {
    if (abc[i] > max)
    {
      max = abc[i];
      maxIndex = i;
    }
  }
  
  if (maxIndex < 52)
  {
    for (int i = maxIndex + 1; i < 52; i++)
    {
      if (abc[i] == max)
        same = true;
    }
  }
  
  
  if (same)
    cout << "!" << endl;
  else
  {
    if (maxIndex <= 25) // 최대값 소문자
      maxChar = maxIndex + 'a';
    else // 최대값 대문자
      maxChar = maxIndex + 'A';
    
    cout << maxChar << endl;
  }
  

  return 0;
}
